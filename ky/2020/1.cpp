#include <iostream>

int gcd(int a, int b){
    if(a < b){ return gcd(b, a); }
    if(0 == b){ return a; }
    return gcd(b, a%b);
}

int main(int argc, char* argv[]){
    int a=0, b=0;
    std::cin >> a >> b;
    std::cout << gcd(a, b);
    return 0;
}