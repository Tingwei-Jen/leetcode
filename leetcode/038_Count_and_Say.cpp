class Solution {
public:
    string countAndSay(int n) {
        
        if (n==0) return "";
        if (n==1) return "1";
        
        string res = "1";
        string cur;
        
        for(int i=1; i<n; i++){    
            for(int j=0; j<res.size();j++){         
                int count = 1;
                while(j<(res.size()-1) && res[j]==res[j+1]){
                    count ++;
                    j++;
                }
                cur += to_string(count) + res[j];
            }
            res = cur;
            cur.clear();
        }
        return res;   
    }
};
