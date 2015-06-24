#ifndef NCURSES_APP_HPP_INCLUDE
#define NCURSES_APP_HPP_INCLUDE

#include <map>
#include <vector>
#include <functional>
#include "event.hpp"

namespace NCursesUI {
  class Widget;
  class EventHandler;
  class NCursesApp {
  public:
    static NCursesApp *app();
    NCursesApp(void);
    ~NCursesApp(void);
    void clear_screen(void);
    void exec();
    void exit();
    void register_widget(Widget *);
    void register_event_handler(const EventHandler *);
  private:
    static NCursesApp *instance;
    bool running;
    std::vector<const EventHandler *> event_handlers;
    std::vector<const Widget *> widgets;
    std::vector<const Widget *>::iterator widget_iter;

    void next_widget(void);
    void event_loop(void);
  };
}

#endif /* end of include guard: NCURSES_APP_HPP_INCLUDE */

