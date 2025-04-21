#include "MyLib.h"
class Base {
public:
  int val_b;
  void print() { std::cout << "基类=" << val_b << '\n'; }
};

class Derived : public Base {
public:
  int val_d;
  void print() { std::cout << "子类=" << val_d << ", (基类=" << val_b << '\n'; }
};

int main() {
  {
    Derived d;
    std::cout << std::hex << reinterpret_cast<long long>(&d) << '\n';
    d.val_d = 2;
    d.val_b = 1;
    d.print();
  }
  std::cout << '\n';

  int a[10] = {10, 11};
  for (int i = 0; i < 10; ++i) {
    std::cout << "i=" << i << ", addr=" << std::hex
              << reinterpret_cast<long long>(&(a[i])) << ", a[i]=" << std::dec
              << a[i] << '\n';
  }
  std::cout << '\n';

  {
    Base b;
    std::cout << std::hex << reinterpret_cast<long long>(&b) << '\n';
    b.val_b = 1;
    b.print();
    static_cast<Derived *>(&b)->print();
  }
}