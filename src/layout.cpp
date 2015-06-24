#include "layout.hpp"

#include <iostream>

using namespace std;
using namespace NCursesUI;

Layout::Layout(Widget *parent) : Widget(parent) {
}

Layout::~Layout() {
}

void Layout::add_widget(Widget *widget) {
  widget->register_parent(this);
  widgets.push_back(widget);
}

vector<Widget *>::iterator Layout::widgets_begin() {
  return widgets.begin();
}

vector<Widget *>::iterator Layout::widgets_end() {
  return widgets.end();
}

int Layout::widgets_size() {
  return widgets.size();
}
