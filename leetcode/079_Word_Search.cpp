class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        //DFS and backtracking
        
        if(word.empty()) return true;
        if(board.empty()) return false;
        
        //與board 同樣大小 用來判斷 是否已經走過
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));          

        //尋訪每一點 找第一個字母 然後開始遞迴
        for(int row = 0; row<board.size();row++){
            for(int col = 0; col<board[0].size();col++){
                
                if( search(board, used, row, col, 0, word))
                    return true;
                
            }
        }
        
        return false;               //沒找到
    }
    
    bool search(vector<vector<char>> &board, vector<vector<bool>> &used, int row, int col, int index, string word){
        
        //return true or false 都會結束遞迴
        
        //index 現在在找第幾個字
        if(index == word.size()) return true;
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size())
            return false;
        if( used[row][col] || board[row][col] != word[index])                //找過了或是當前位置與所要找的字符不相同
            return false;
        
        
        used[row][col] = true;    //之前沒被找過且是要找的 現在遇到做紀錄
        
        //往上下左右找 有一個找到就return true                              //return false會退回上一步找上一步其他上下左右
        bool exist = search(board, used, row-1, col, index+1, word)   //up
                   || search(board, used, row+1, col, index+1, word)  //down
                   || search(board, used, row, col-1, index+1, word)  //left
                   || search(board, used, row, col+1, index+1, word); //right
        
        used[row][col] = false;       //洗掉紀錄
        
        return exist;
        
    } 
};
