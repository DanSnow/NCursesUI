#ifndef WIDGET_HPP_INCLUDE
#define WIDGET_HPP_INCLUDE

#include <memory>
#include <tuple>
#include <vector>
#include "signal.hpp"

namespace NCursesUI {
  class Widget {
  public:
    Widget(Widget * = nullptr);
    virtual ~Widget(void);
    void show(void);
    bool is_key_respond(void) const;
    void register_parent(Widget *);
    std::tuple<int, int> get_start_xy();
    std::tuple<int, int> get_max_xy();
    void set_max_xy(int, int);
    void set_start_xy(int, int);
    Signal<void(int)> key_down;
  protected:
    virtual void show_widget(void) = 0;
    void move_cursor(int, int);
    void set_key_respond(bool);
  private:
    void show_all(void);
    void register_child(Widget *);
    void register_widget(void);
    std::vector<Widget *> children;
    Widget *parent;
    int start_x, start_y, width, height;
    bool is_register;
    bool key_respond;
  };
}

#endif /* end of include guard: WIDGET_HPP_INCLUDE */

