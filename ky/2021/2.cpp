#include <bits/stdc++.h>
#include <iostream>
// #include <stdio.h>

int main(int argc, char* argv[]){
    unsigned long long a=0, b=0;
    std::cin>>a>>b;
    unsigned long long c = a^b;
    int res = 0;
    for(int i=0;i<64;++i){
        if(1==(c&1)){
            ++res;
        }
        c = c>>1;
    }
    std::cout<< res;
    return 0;
}