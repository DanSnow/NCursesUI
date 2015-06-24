#include "event.hpp"

using namespace std;
using namespace NCursesUI;

Event::Event(EventID id) {
  this->id = id;
}

Event::~Event() {
}

Event::EventID Event::type() const {
  return id;
}
