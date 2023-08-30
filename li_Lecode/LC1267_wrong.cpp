class Solution {
public:
  // 做错了，题目理解错了
  // 理解为了必须相邻才能通信
    int countServers(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(isServer(grid,i,j)){
                    if(isServer(grid,i-1,j)||isServer(grid,i+1,j)||isServer(grid,i,j-1)||isServer(grid,i,j+1)){
                        ++result;
                    }
                }
            }
        }
        return result;
    }
private:
  // 但是我抽象出了这个函数
  // 我认为它后续会经常用到
    bool isServer(vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0){
            return false;
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return false;
        }
        return grid[i][j];
    }
};