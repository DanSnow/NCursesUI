#ifndef KEY_DOWN_EVENT_HPP_INCLUDE
#define KEY_DOWN_EVENT_HPP_INCLUDE

#include "event.hpp"

#include <memory>

namespace NCursesUI {
  class KeyDownEvent : public Event {
  public:
    static int get_key(std::unique_ptr<Event>);
    KeyDownEvent(int);
    ~KeyDownEvent(void);
    int key() const;

  private:
    int key_code;
  };
}

#endif /* end of include guard: KEY_DOWN_EVENT_HPP_INCLUDE */

