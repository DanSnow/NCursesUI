#include "widget.hpp"
#include "ncurses_app.hpp"

#include <ncurses.h>

using namespace std;;
using namespace NCursesUI;

Widget::Widget(Widget *parent) {
  this->parent = nullptr;
  start_x = start_y = 0;
  getmaxyx(stdscr, height, width);
  is_register = false;
  key_respond = false;
  register_parent(parent);
}

Widget::~Widget() {
}

void Widget::register_parent(Widget *parent) {
  int wid, hei, s_x, s_y;
  if(this->parent != nullptr) {
    return;
  }
  if(parent) {
    parent->register_child(this);
    tie(wid, hei) = parent->get_max_xy();
    tie(s_x, s_y) = parent->get_start_xy();
    set_start_xy(s_x, s_y);
    set_max_xy(wid, hei);
  }
}

void Widget::move_cursor(int x, int y) {
  wmove(stdscr, start_y + y, start_x + x);
}

void Widget::register_child(Widget *child) {
  children.push_back(child);
}

bool Widget::is_key_respond() const {
  return key_respond;
}

void Widget::set_key_respond(bool status) {
  key_respond = status;
}

void Widget::set_max_xy(int max_x, int max_y) {
  width = max_x;
  height = max_y;
}

void Widget::set_start_xy(int s_x, int s_y) {
  start_x = s_x;
  start_y = s_y;
}

void Widget::show() {
  show_all();
  register_widget();
  refresh();
}

void Widget::show_all() {
  this->show_widget();
  for(auto child : children) {
    child->show_all();
  }
}

void Widget::register_widget() {
  NCursesApp *app = NCursesApp::app();
  if(is_register) { // Don't register twice
    return;
  }
  if(app) {
    app->register_widget(this);
    for(auto child : children) {
      child->register_widget();
    }
    is_register = true;
  }
}

tuple<int, int> Widget::get_start_xy() {
  return make_tuple(start_x, start_y);
}

tuple<int, int> Widget::get_max_xy() {
  return make_tuple(width, height);
}
