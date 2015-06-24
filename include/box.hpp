#ifndef BOX_HPP_INCLUDE
#define BOX_HPP_INCLUDE

#include "layout.hpp"

#include <vector>

namespace NCursesUI {
  class Widget;
  class Box : public Layout {
  public:
    enum Orientation {
      HORIZIONTAL,
      VERTICAL
    };
    Box(Orientation, Widget * = nullptr);
    ~Box();
    void add_stretch(void);
    void add_widget(Widget *);
    void show_widget() override;

  private:
    Orientation ori;
    std::vector<Widget *> widgets;
    int calculate_length(int);
    void alloc_length(int);
  };
}

#endif /* end of include guard: BOX_HPP_INCLUDE */

