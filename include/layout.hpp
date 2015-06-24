#ifndef LAYOUT_HPP_INCLUDE
#define LAYOUT_HPP_INCLUDE

#include "widget.hpp"

#include <vector>

namespace NCursesUI {
  class Layout : public Widget {
  public:
    Layout(Widget * = nullptr);
    virtual ~Layout();

  protected:
    void add_widget(Widget *);
    std::vector<Widget *>::iterator widgets_begin(void);
    std::vector<Widget *>::iterator widgets_end(void);
    int widgets_size(void);
    std::vector<Widget *> widgets;
  };
}

#endif /* end of include guard: LAYOUT_HPP_INCLUDE */

