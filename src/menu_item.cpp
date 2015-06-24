#include "menu_item.hpp"

using namespace std;
using namespace NCursesUI;

MenuItem::MenuItem(const string &item_text) {
  text(item_text);
}

MenuItem::MenuItem(const MenuItem &oth) : item_text(oth.item_text) {
  select = oth.select;
}

string MenuItem::text() const {
  return item_text;
}

void MenuItem::text(const string &item_text) {
  this->item_text = item_text;
}
