#include <bits/stdc++.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    int num = 0;
    std::cin>> num;
    std::vector<int> sevens;
    for(int remain = num;remain!=0;remain/=7){
        sevens.emplace_back(remain%7);
    }
    for(auto it = sevens.rbegin(); it !=sevens.rend(); ++it){
        std::cout<<*it;
    }
    return 0;
}