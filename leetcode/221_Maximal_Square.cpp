class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
    
        int max_size = 0;
        vector<vector<int>> T(m+1, vector<int>(n+1, 0));      //上面和左邊增加一行與一列補0

        for(int i=1; i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1] == '1'){ 
                    T[i][j] = min(T[i][j-1], min(T[i-1][j-1], T[i-1][j])) +1 ;          //左邊 左上 上面的min +1
                    max_size = max(max_size, T[i][j]);                                  //min 函數只能有兩個
                }        
            }
        }
        return max_size*max_size;   
    }
};
