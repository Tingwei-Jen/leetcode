class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        //每一列第一個值都是1。
        //每一列第n個值則是上一列n-1位子+n位子的值。
        
        vector<vector<int>> res(numRows);  
        
        for(int i=0; i<numRows; i++){
            
            res[i].resize(i+1);
                
            res[i][0] = 1;                          //每一列開頭結尾都是1
            res[i][i] = 1;   
            
            for(int j=1;j<i;j++){                   //填每列裡的數字 第一列有一個數字 第二列有兩個數字 j<i                
                
                int n = res[i-1][j-1]+res[i-1][j];
                res[i][j] = n;
            } 
        }
        return res;
 
    }
};
