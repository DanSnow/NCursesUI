#ifndef MENU_HPP_INCLUDE
#define MENU_HPP_INCLUDE

#include "widget.hpp"
#include "menu_item.hpp"

#include <string>
#include <functional>
#include <vector>

namespace NCursesUI {
  class Menu : public Widget {
  public:
    Menu(Widget * = nullptr);
    void add_item(const std::string &, function<void(void)>);
    void add_item(const MenuItem &);
    void padding(int, int);
  protected:
    void show_widget(void) override;
  private:
    int item_select, pad_x, pad_y;
    std::vector<MenuItem> items;
    void menu_handler(int); // Key press handler
  };
}

#endif /* end of include guard: MENU_HPP_INCLUDE */

