#include <iostream>

int main() {
    int a = 42;
    void *pa;
    pa = &a;
    void **ppa;
    ppa = &pa;
    std::cout << "a: " << a << ", &a: " << &a << std::endl
              << "*pa: " << *(int *)pa << ", pa: " << pa << ", &pa: " << &pa << std::endl
              << "**ppa: " << *(int *)*ppa << ", *ppa: " << *ppa << ", ppa: " << ppa << ", &ppa: " << &ppa << std::endl;
    return 0;
}