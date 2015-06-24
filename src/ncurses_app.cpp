#include "ncurses_app.hpp"
#include "widget.hpp"
#include "event.hpp"
#include "event_handler.hpp"
#include "key_down_event.hpp"

#include <iostream>
#include <memory>
#include <ncurses.h>

using namespace std;
using namespace NCursesUI;

namespace NCursesUI {
  NCursesApp *NCursesApp::instance = nullptr;
}

NCursesApp::NCursesApp() {
  if(instance != nullptr) {
    throw "initialize twice";
  }
  instance = this;
  running = false;
  initscr();
  keypad(stdscr, TRUE);
  clear_screen();
}

NCursesApp::~NCursesApp() {
  endwin();
}

void NCursesApp::clear_screen() {
  clear();
}

void NCursesApp::exec() {
  running = true;
  event_loop();
}

void NCursesApp::exit() {
  running = false;
}

void NCursesApp::event_loop() {
  while(running) {
    int ch = getch();
    KeyDownEvent key_event(ch);
    bool block = false;
    for(auto handler : event_handlers) {
      if(!handler->key_down_event(key_event)) {
        block = true;
      }
    }
  }
}

void NCursesApp::register_widget(Widget *widget) {
  widgets.push_back(widget);
}

void NCursesApp::register_event_handler(const EventHandler *handler) {
  event_handlers.push_back(handler);
}

void NCursesApp::next_widget() {
  ++widget_iter;
  if(widget_iter == widgets.end()) {
    widget_iter = widgets.begin();
  }
}

NCursesApp *NCursesApp::app() {
  return instance;
}
