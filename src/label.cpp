#include "label.hpp"

#include <iostream>
#include <ncurses.h>

using namespace std;
using namespace NCursesUI;

Label::Label(Widget *parent) : Widget(parent) {
}

Label::Label(string text, Widget *parent) : Widget(parent) {
  this->text = text;
}

Label::~Label() {
}

void Label::show_widget() {
  move_cursor(0, 0);
  wprintw(stdscr, "%s", text.c_str());
}
