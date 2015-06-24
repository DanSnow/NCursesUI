#ifndef LABEL_HPP_INCLUDE
#define LABEL_HPP_INCLUDE

#include "widget.hpp"

#include <string>
#include <memory>

namespace NCursesUI {
  class Label : public Widget {
  public:
    Label(Widget * = nullptr);
    Label(std::string, Widget * = nullptr);
    ~Label(void);
    void show_widget(void) override;

  private:
    std::string text;
  };
}

#endif /* end of include guard: LABEL_HPP_INCLUDE */

