#include <bits/stdc++.h>
using std::vector;

// no use
template<typename T>
class MonoStack{
public:
    MonoStack(){ pred = std::less<T>();}
    MonoStack(const std::function<bool(const T&, const T&)>& p){pred = p;}

    void push(const T& elem){
        while(!q.empty() && !pred(elem, top())){
            pop();
        }
        q.emplace_back(elem);
    }

    void pop(){
        q.pop_back();
    }

    const T& top(){
        return q.back();
    }

    std::deque<T> q;
private:
    std::function<bool(const T&, const T&)> pred;
};

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        const auto& n = maxHeights.size();
        std::deque<std::pair<int, int>> mono_stack; // (i, maxHeights[i])
        vector<long long> prefix(n);
        prefix.front() = maxHeights.front();
        mono_stack.emplace_back(0, maxHeights.front());
        for(int i=1;i<n;++i){
            while(!mono_stack.empty() && mono_stack.back().second>maxHeights[i]){
                mono_stack.pop_back();
            }
            if(!mono_stack.empty()){
                int& pre_i = mono_stack.back().first;
                prefix[i] = prefix[pre_i] + static_cast<long long>(i-pre_i) * maxHeights[i];
            }else{
                prefix[i] = static_cast<long long>(i+1) * maxHeights[i];
            }
            mono_stack.emplace_back(i, maxHeights[i]);
        }
        mono_stack.clear();

        vector<long long> suffix(n);
        suffix.back() = maxHeights.back();
        mono_stack.emplace_back(n-1, maxHeights.back());
        for(int i=n-1;i>=0;--i){
            while(!mono_stack.empty() && mono_stack.back().second>maxHeights[i]){
                mono_stack.pop_back();
            }
            if(!mono_stack.empty()){
                int& suf_i = mono_stack.back().first;
                suffix[i] = suffix[suf_i] + static_cast<long long>(suf_i-i) * maxHeights[i];
            }else{
                suffix[i] = static_cast<long long>(n-i) * maxHeights[i];
            }
            mono_stack.emplace_back(i, maxHeights[i]);
        }

        long long res = -1;
        for(int i=0;i<n;++i){
            long long t = prefix[i] + suffix[i] - maxHeights[i];
            if(t > res){
                res = t;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> input = {{5,3,4,1,1}};
    std::cout << s.maximumSumOfHeights(input)<<'\n';
    return 0;
}