#include "key_down_event.hpp"
#include "event.hpp"

#include <memory>

using namespace std;
using namespace NCursesUI;

int KeyDownEvent::get_key(unique_ptr<Event> e) {
  KeyDownEvent *event = static_cast<KeyDownEvent *>(e.get());
  return event->key();
}

KeyDownEvent::KeyDownEvent(int key_code) : Event(KEY_DOWN_EVENT) {
  this->key_code = key_code;
}

KeyDownEvent::~KeyDownEvent() {
}

int KeyDownEvent::key() const {
  return key_code;
}
