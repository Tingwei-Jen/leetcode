class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        //use DFS to find island
        if(grid.empty() || grid[0].empty()) return 0; 
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] =='1' && !visited[i][j]){       //是陸地且沒找過
                    findIslandDFS(grid, visited, i, j);
                    res++;                                    //完成一次DFS  代表找完一個小島
                }
            }
        }
        
        return res;
    }
    
    void findIslandDFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y){
        
        //遞迴結束條件
        if(x<0 || x>=grid.size()) return;
        if(y<0 || y>=grid[0].size()) return;
        
        //水 或是 找過了 return
        if(grid[x][y] =='0' || visited[x][y]) return;
        
        //不然標記成找過了    
        visited[x][y] = true;
        
        //往上下左右找
        findIslandDFS(grid, visited, x-1, y);    //left
        findIslandDFS(grid, visited, x+1, y);   //right
        findIslandDFS(grid, visited, x, y-1);   //up
        findIslandDFS(grid, visited, x, y+1);   //down
    }

};
