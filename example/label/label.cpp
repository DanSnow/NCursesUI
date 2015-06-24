#include "ncurses_app.hpp"
#include "event.hpp"
#include "event_handler.hpp"
#include "key_down_event.hpp"
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
  Label test("This is a label demo. Press q to exit");
  test.show();
  app.exec();
  return 0;
}
