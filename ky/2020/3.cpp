#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using std::string;

struct JoinComp{
    // a+b > b+a
    bool operator()(const string& a, const string& b){
        for(int i=0; i < a.size()+b.size(); ++i){
            const char& ab_ch = (i < a.size()) ? a[i] : b[i - a.size()];
            const char& ba_ch = (i < b.size()) ? b[i] : a[i - b.size()];
            if(ab_ch != ba_ch){
                return ab_ch > ba_ch;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]){
    std::fstream f("number.in");
    if(!f){
        return 0;
    }

    std::set<string, JoinComp> desc_set;
    std::vector<string> desc_vec;
    for(std::string num; f >> num; ){
        desc_set.emplace(num);
        desc_vec.emplace_back(num);
    }
    std::sort(desc_vec.begin(), desc_vec.end(), JoinComp{});

    std::cout << "set: ";
    for(const auto& n: desc_set){
        std::cout << n;
    }
    std::cout << "\nvec: ";
    for(const auto& n: desc_vec){
        std::cout << n;
    }
    return 0;
}