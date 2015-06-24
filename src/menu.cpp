#include "menu.hpp"

#include <ncurses.h>

using namespace std;
using namespace NCursesUI;

Menu::Menu(Widget *parent) : Widget(parent) {
  key_down.connect(bind(&Menu::menu_handler, this, placeholders::_1));
  set_key_respond(true);
  item_select = 0;
}

void Menu::add_item(const string &text, function<void(void)> callback) {
  MenuItem item(text);
  item.select.connect(callback);
  items.push_back(item);
}

void Menu::add_item(const MenuItem &item) {
  items.push_back(item);
}

void Menu::show_widget() {
  for(int i = 0, len = items.size(); i < len; ++i) {
    move_cursor(pad_x, pad_y + i);
    printw("%c %s", (i == item_select ? '>' : ' '), items[i].text().c_str());
  }
}

void Menu::menu_handler(int ch) {
  int len = items.size();
  switch(ch) {
    case KEY_UP:
      if(item_select) {
        --item_select;
      }
      break;
    case KEY_DOWN:
      if(item_select < len) {
        ++item_select;
      }
      break;
    case KEY_ENTER:
      items[item_select].select();
  }
  show();
}
