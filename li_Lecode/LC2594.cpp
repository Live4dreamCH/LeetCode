class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        m_ranks = ranks;
        m_cars = cars;

        int min_rank = 1000;
        for(const auto& r:ranks){
            if(r < min_rank){
                min_rank = r;
            }
        }
        long long upper_limit = min_rank;
        upper_limit *= cars;
        upper_limit *= cars;
        if(1 == ranks.size()){
            return upper_limit;
        }
        long long lower_limit = 1;
        long long try_time{};

        while(lower_limit < upper_limit){
            try_time = (upper_limit + lower_limit) / 2;
            if (isAbleToRepairInThisTime(try_time)){
                upper_limit = try_time;
            }else{
                if(lower_limit == try_time){
                    return upper_limit;
                }
                lower_limit = try_time;
            }
        }
        return lower_limit;
    }
private:
    bool isAbleToRepairInThisTime(long long try_time){
        int repaired_cars = 0;
        for(const auto& r:m_ranks){
            repaired_cars += std::floor(std::sqrt(double(try_time)/r));
            if(repaired_cars >= m_cars){
                return true;
            }
        }
        return false;
    }

    std::vector<int> m_ranks{};
    int m_cars{};
};