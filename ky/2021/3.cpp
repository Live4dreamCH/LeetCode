#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using std::vector;

#define RETURN_TRUE_IF(cond)\
    if(cond) {return true;}

constexpr double thresh = 1e-6;

bool eq_24(const double n){
    return 24-thresh < n && n < 24+thresh;
}

// 用过加法后，不能再用乘法
bool solve(vector<double> nums, bool add_used){
    if(nums.empty()){return false;}
    if(1==nums.size()){
        return eq_24(nums[0]);
    }
    if(2==nums.size()){
        RETURN_TRUE_IF(eq_24(nums[0]+nums[1]));
        RETURN_TRUE_IF(!add_used && eq_24(nums[0]*nums[1]));
        return false;
    }
    vector<double> inner_nums = nums;
    for(int j=nums.size()-1;j>0;--j){
        const auto& b = nums[j];
        inner_nums.erase(inner_nums.begin()+j);
        for(int i=j-1;i>=0;--i){
            const auto& a = nums[i];
            inner_nums.erase(inner_nums.begin()+i);
            // +
            inner_nums.emplace_back(a+b);
            RETURN_TRUE_IF(solve(inner_nums, true));
            inner_nums.pop_back();
            
            // *
            if(!add_used){
                inner_nums.emplace_back(a*b);
                RETURN_TRUE_IF(solve(inner_nums, false));
                inner_nums.pop_back();
            }
            inner_nums.emplace(inner_nums.begin()+i,a);
        }
        inner_nums.emplace(inner_nums.begin()+j,b);
    }
    return false;
}

int main(int argc, char* argv[]){
    std::vector<double> nums(4);
    bool res = true;
    for(int i=0;i<4;++i){
        std::cin>>nums[i];
        if(nums[i]>24+thresh){
            res = false;
        }
    }
    if(!res){
        std::cout<<"NO";
    }

    res = solve(nums, false);
    if(res){
        std::cout<<"YES";
    }else{
        std::cout<<"NO";
    }
    return 0;
}