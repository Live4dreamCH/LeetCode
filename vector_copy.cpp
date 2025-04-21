#include <MyLib.h>

int main() {
  vector<int> a{1, 2, 3};
  vector<int> b = a;
  b[0] = 10086;
  std::cout << a[0];
  return 0;
}