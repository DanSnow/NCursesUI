#ifndef EVENT_HPP_INCLUDE
#define EVENT_HPP_INCLUDE

#include <memory>

namespace NCursesUI {
  class Event {
  public:
    enum  EventID {
      BASE,
      KEY_DOWN_EVENT
    };
    Event(EventID);
    virtual ~Event(void);
    EventID type() const;

  private:
    EventID id;
  };
}

#endif /* end of include guard: EVENT_HPP_INCLUDE */

