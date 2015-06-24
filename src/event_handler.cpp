#include "event_handler.hpp"
#include "ncurses_app.hpp"

#include <iostream>

using namespace std;
using namespace NCursesUI;

EventHandler::EventHandler() {
  NCursesApp *app = NCursesApp::app();
  if(app) {
    app->register_event_handler(this);
  }
}

EventHandler::~EventHandler() {
}

bool EventHandler::key_down_event(const KeyDownEvent & /*e*/) const {
  return true;
}
