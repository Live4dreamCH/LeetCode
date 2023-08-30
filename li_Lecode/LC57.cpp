class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()){
            return vector<vector<int>>{newInterval};
        }
        bool left_hit = false, right_hit = false;
        int left_index = 0, right_index = 0;
        findInterval(intervals, newInterval[0], left_hit, left_index);
        findInterval(intervals, newInterval[1], right_hit, right_index);

        int left_num{}, right_num{};
        int erase_left{}, erase_right{};
        if(left_hit){
            left_num = std::min(intervals[left_index][0], newInterval[0]);
            erase_left = left_index;
        }else {
            left_num = newInterval[0];
            erase_left = left_index;
        }
        if(right_hit){
            right_num = std::max(intervals[right_index][1],newInterval[1]);
            erase_right = right_index+1;
        }
        else{
            right_num = newInterval[1];
            erase_right = right_index;
        }
        intervals.erase(intervals.begin()+erase_left, intervals.begin()+erase_right);
        intervals.emplace(intervals.begin()+left_index,vector<int>{left_num, right_num});
        return intervals;
    }

    void findInterval(const vector<vector<int>>& intervals, const int num, bool& hit, int& index){
        hit = false;
        for (index = 0;index<intervals.size();++index){
            if(num<intervals[index][0]){
                hit = false;
                return ;
            }
            if(intervals[index][0]<=num && num<=intervals[index][1]){
                hit = true;
                return ;
            }
        }
    }
};