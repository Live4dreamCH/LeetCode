class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int result = 0;
        Prepare(grid);

        for (int i = 0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(isCommunatable(grid,i,j)){
                    ++result;
                }
            }
        }
        return result;
    }
private:
    // i, j位置上是否是个服务器
    bool isServer(const vector<vector<int>>& grid, int i, int j){
        if(i<0 || j<0){
            return false;
        }
        if(i>=grid.size() || j>=grid[0].size()){
            return false;
        }
        return grid[i][j];
    }

    // i, j位置上是否是个可通信服务器
    bool isCommunatable(const vector<vector<int>>& grid, int i, int j){
        return isServer(grid, i, j)&& (row_count[i]>=2 || col_count[j]>=2);
    }

    // 准备row_count和col_count
    void Prepare(const vector<vector<int>>& grid){
        row_count.resize(grid.size(), 0);
        col_count.resize(grid[0].size(), 0);

        for (int i = 0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(isServer(grid,i,j)){
                    ++row_count[i];
                    ++col_count[j];
                }
            }
        }
    }

    vector<int> row_count; // 一行中的服务器个数
    vector<int> col_count; // 一列中的服务器个数
};