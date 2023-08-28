#include <iostream>

int fn(int& c){
    return c+c;
}

int main(){
    int a=1;
    // a=1;
    // // 1=2;
    // const int b=3;
    // b;
    // 3;
    // "123";
    int& ref_a=a;
    int&& ref_fn_a=fn(a);
    int&& ref_literal=3;
    ref_a = ref_fn_a;
    std::cout<<fn(a)<<'\n';

    if(1){
        int c=1;
        int& p=c;

        p=&c;
        std::cout<<c<<'\n';
    }
    int d=3;
    p=2;
    std::cout<<d;
    
    return 0;
}