#include <iostream>

// Base class template using CRTP
template <typename Derived> class Base {
public:
  void interface() {
    // Call the derived class implementation
    std::cout << "I want to add more on all derived implementations\n";
    static_cast<Derived *>(this)->implementation();
  }

  // Default implementation (optional)
  //   void implementation() { std::cout << "Base implementation\n"; }
};

// Derived class inheriting from Base using CRTP
class X : public Base<X> {
  friend class Base<X>; // Allow Base<X> to access private members
  void implementation() { std::cout << "X\n"; }
};

class Y : public Base<Y> {
  friend class Base<Y>; // Allow Base<Y> to access private members
  void implementation() { std::cout << "Y\n"; }
};

template <typename T> void fBase(Base<T> &b) {
  b.interface(); // Calls T's implementation
}

template <typename T> void f(T &t) {
  std::cout << "I want to add more on all derived implementations as well\n";
  t.interface(); // Calls T's implementation
}

class Z {
  template <typename T>
  friend void f(T &t); // 限定死了接口的参数和返回值类型，看起来没CRTP好
  void interface() { std::cout << "Z\n"; }
};

class W {
  template <typename T>
  friend void f(T &t); // 限定死了接口的参数和返回值类型，看起来没CRTP好
  void interface() { std::cout << "W\n"; }
};

int main() {
  X x;
  x.interface(); // Calls Derived's implementation
  fBase(x);      // Calls Derived's implementation
  f(x);          // Calls Derived's implementation

  Y y;
  y.interface(); // Calls Derived's implementation
  fBase(y);      // Calls Derived's implementation
  f(y);          // Calls Derived's implementation

  Z z;
  f(z);
  W w;
  f(w);

  return 0;
}