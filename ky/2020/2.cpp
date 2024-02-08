#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>

int main(){
    int n=0, k=0;
    std::fstream f("array.in");
    if(!f.is_open()){
        return 0;
    }
    f >> n >> k;
    if(n < k){
        return 0;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap;
    int num = 0;
    for(int i=0;i<k;++i){
        f >> num;
        min_heap.emplace(num);
    }
    for(int i=0; i < n-k; ++i){
        f >> num;
        if(num >= min_heap.top()){
            min_heap.pop();
            min_heap.emplace(num);
        }
    }
    std::cout << min_heap.top();
    return 0;
}