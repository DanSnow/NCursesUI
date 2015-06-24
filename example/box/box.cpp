#include "ncurses_app.hpp"
#include "event.hpp"
#include "event_handler.hpp"
#include "key_down_event.hpp"
#include "box.hpp"
#include "label.hpp"

#include <iostream>
#include <unistd.h>

using namespace std;
using namespace NCursesUI;

class QuitApp : public EventHandler {
public:
  QuitApp() : EventHandler() {
  }

  bool key_down_event(const KeyDownEvent &e) const {
    NCursesApp *app = NCursesApp::app();
    if(e.key() == 'q') {
      app->exit();
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  NCursesApp app;
  QuitApp handler;
  Box box(Box::HORIZIONTAL);
  Label test("This is a box demo. Press q to exit");
  Label test2("This is second label, you should see this at about middle");
  box.add_widget(&test);
  box.add_widget(&test2);
  box.show();
  app.exec();
  return 0;
}
