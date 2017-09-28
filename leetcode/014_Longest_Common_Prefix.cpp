class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        // two dimention
        
        if (strs.empty()) 
            return "";
        
        string res = "";
        
        for (int j=0; j< strs[0].size(); j++){            //尋訪 第一條string 的每個字元 並且拿該字元 與其他字串 同位置的字元做比較
            
            char c = strs[0][j];
            
            for(int i =1; i<strs.size(); i++){            //其他字串
                
                if( j>=strs[i].size() || strs[i][j]!=c)   //該位置 超過其他字串長度 以及 同位置字元不相同時 結束
                    return res;
                
            }
            
            res.push_back(c);
            
        }
        
        return res;                                        //找完第一個string 的全部字元發現都有出現在其他字串

        
    }
};
