class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        //Dynamic Programming 當前狀態由之前狀態所決定
        //這題很像爬樓梯 只是 變成 爬n 階 一次可爬 1,2,3.....n 然後判斷 有沒有在dict 裡面
        
        //state: f(i) = true or false
        //init: f(0) = true
        //func: f(i) = f(i-j)
        //res: f(n+1)
        
        // "abcd" = 0"1234"
        
        if (s.size()==NULL) return false;
        if (wordDict.size()==NULL) return false;

        vector<bool> breakable((s.size()+1), false);            //原先長度+1
        breakable[0] = true;
        
        //func:  wb[i] = true, if [0, i-j] is true && [i-j, i] in dict 
        for(int i=0; i<=s.size();i++){
            for(int j = 1; j<=i ;j++){                   //j = 1->i
                
                string str = s.substr(i-j, j);                                             //str(pos, len)
                if(find(wordDict.begin(), wordDict.end(), str) != wordDict.end()) {        
                    if(breakable[i-j]==true){                                                     
                        breakable[i] = true;                                                 
                        break;
                    }
                }
            }
        }
        
        return breakable[s.size()];
    }
};
