#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for(int i=0;i<nums.size();++i){
            auto it = hashmap.find(target-nums[i]);
            if(it==hashmap.end()){
                hashmap.emplace(nums[i],i);
            }else{
                return vector<int>{it->second,i};
            }
        }
        return vector<int>{-1,-1};
    }
};

int main(){
    Solution s;
    vector<int> nums;
    int n,temp,target;
    cin>>n>>target;
    for(int i=0;i<n;++i){
        cin>>temp;
        nums.push_back(temp);
    }
    auto const& index = s.twoSum(nums,target);
    for(const auto& in:index){
        cout<<in<<' ';
    }
    return 0;
}