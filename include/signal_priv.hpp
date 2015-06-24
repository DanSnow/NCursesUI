#ifndef SIGNAL_PRIV_HPP_INCLUDE
#define SIGNAL_PRIV_HPP_INCLUDE

namespace NCursesUI {
  using namespace std;
  template<typename Signature>
  Signal<Signature>::Signal() {
  }

  template<typename Signature>
  Signal<Signature>::Signal(const Signal &oth) {
    f = oth.f;
  }

  template<typename Signature>
  Signal<Signature> &Signal<Signature>::operator=(const Signal &oth) {
    f = oth.f;
    return *this;
  }


  template<typename Signature>
  void Signal<Signature>::connect(Function func) {
    this->f = func;
  }

  template<typename Signature>
  template<typename... Args>
  typename Signal<Signature>::Result
  Signal<Signature>::operator()(Args&&... args) {
    return f(std::forward<Args>(args)...);
  }
}

#endif /* end of include guard: SIGNAL_PRIV_HPP_INCLUDE */

