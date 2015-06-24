#ifndef MENU_ITEM_H_INCLUDE
#define MENU_ITEM_H_INCLUDE

#include "signal.hpp"

#include <string>

namespace NCursesUI {
  class MenuItem {
   public:
     MenuItem(const std::string &);
     MenuItem(const MenuItem &);
     std::string text() const;
     void text(const std::string &);
     Signal<void(void)> select;
   private:
     std::string item_text;
  };
}

#endif /* end of include guard: MENU_ITEM_H_INCLUDE */

