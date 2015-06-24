#ifndef EVENT_HANDLER_HPP_INCLUDE
#define EVENT_HANDLER_HPP_INCLUDE

namespace NCursesUI {
  class KeyDownEvent;
  class EventHandler {
  public:
    EventHandler(void);
    virtual ~EventHandler(void);
    virtual bool key_down_event(const KeyDownEvent &) const = 0;
  };
}

#endif /* end of include guard: EVENT_HANDLER_HPP_INCLUDE */

