#include "box.hpp"

#include <iostream>
#include <algorithm>

using namespace std;
using namespace NCursesUI;

Box::Box(Orientation ori, Widget *parent) : Layout(parent), ori(ori) {
}

Box::~Box() {
}

void Box::add_widget(Widget *widget) {
  if(widget == nullptr) {
    return;
  }
  Layout::add_widget(widget);
}

void Box::add_stretch() {
  Layout::add_widget(nullptr);
}

void Box::show_widget() {
  int wid, hei, length;
  vector<int> max_lengths;
  tie(wid, hei) = get_max_xy();
  if(widgets_size() == 0) {
    return;
  }
  length = calculate_length(ori == HORIZIONTAL ? wid : hei); // Check box orientation, alloc box widgth or height
  alloc_length(length);
}

int Box::calculate_length(int length) {
  int count = 0;
  for_each(widgets_begin(), widgets_end(), [this, &length, &count](Widget *widget) {
    int wid, hei, widget_len;
    tie(wid, hei) = widget->get_max_xy();
    if(this->ori == HORIZIONTAL) {
      widget_len = wid;
    } else {
      widget_len = hei;
    }
    if(widget_len < length) {
      length -= widget_len;
    } else {
      ++count;
    }
  });
  return count != 0 ? length / count : length / widgets_size();
}

void Box::alloc_length(int length) {
  int widgth, height, len, total_len = 0;
  tie(widgth, height) = get_max_xy();
  len = ori == HORIZIONTAL ? widgth : height;
  for_each(widgets_begin(), widgets_end(), [this, length, len, &total_len](Widget *widget) {
    int wid, hei, orig_x, orig_y;
    int new_len;
    tie(wid, hei) = widget->get_max_xy();
    tie(orig_x, orig_y) = widget->get_start_xy();
    if(this->ori == HORIZIONTAL) {
      new_len = wid == len ? length : wid;
      widget->set_max_xy(new_len, hei);
      widget->set_start_xy(total_len, orig_y);
    } else {
      new_len = hei == len ? length : hei;
      widget->set_max_xy(wid, new_len);
      widget->set_start_xy(orig_x, total_len);
    }
    total_len += new_len;
  });
}
