// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>

int main(int argc, char* argv[]){
    int n =0;
    std::cin>>n;

    double res=0, item = 1;
    for(int k=1;k<=n;++k){
        item /= k;
        res+=item;
    }

    printf("%.4lf", res);
    return 0;
}