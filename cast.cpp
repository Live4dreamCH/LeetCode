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
  // 内容是子类
  {
    Derived d;
    d.val_d = 2;
    d.val_b = 1;
    d.print();

    // 基类指针，指向子类对象
    Base *base_type_ptr = &d;
    base_type_ptr->print();

    // 基类转子类
    { // 强转
      Derived *derived_type_ptr = (Derived *)base_type_ptr;
      derived_type_ptr->print();
    }

    { // static_cast
      Derived *derived_type_ptr = static_cast<Derived *>(base_type_ptr);
      derived_type_ptr->print();
    }

    { // dynamic_cast
      // 不行，得多态
      //   Derived *derived_type_ptr = dynamic_cast<Derived *>(base_type_ptr);
      //   derived_type_ptr->print();
    }
    std::cout << std::hex << reinterpret_cast<long long>(&d) << '\n';
  }
  int a[10] = {10, 11};
  for (int i = 0; i < 10; ++i) {
    std::cout << "i=" << i << ", addr=" << std::hex
              << reinterpret_cast<long long>(&(a[i])) << ", a[i]=" << std::dec
              << a[i] << '\n';
  }
  // 内容是父类
  {
    Base b;
    b.val_b = 1;
    b.print();

    // 基类指针，指向父类对象
    Base *base_type_ptr = &b;
    base_type_ptr->print();

    // 基类转子类，会失败吗？
    { // 强转
      Derived *derived_type_ptr = (Derived *)base_type_ptr;
      derived_type_ptr->print();
    }

    { // static_cast
      Derived *derived_type_ptr = static_cast<Derived *>(base_type_ptr);
      derived_type_ptr->print();
    }

    { // dynamic_cast
      // 不行，得多态
      //   Derived *derived_type_ptr = dynamic_cast<Derived *>(base_type_ptr);
      //   derived_type_ptr->print();
    }
    std::cout << std::hex << reinterpret_cast<long long>(&b) << '\n';
  }

  std::shared_ptr<int> share_ptr = std::make_shared<int>(1);
  *share_ptr += 1;
  std::shared_ptr<int> s_p;
  s_p = share_ptr;

  return 0;
}