#ifndef SIGNAL_HPP_INCLUDE
#define SIGNAL_HPP_INCLUDE

#include <functional>

namespace NCursesUI {
  template<typename Signature>
  class Signal {
  public:
    typedef typename std::function<Signature> Function;
    typedef typename Function::result_type Result;

    Signal(void);
    Signal(const Signal &);
    Signal &operator=(const Signal &);
    void connect(Function);

    template<typename... Args>
    Result operator()(Args&&... args);

  private:
    Function f;
  };
}

#include "signal_priv.hpp"

#endif /* end of include guard: SIGNAL_HPP_INCLUDE */

