class Solution {
public:
    string longestPalindrome(string s) {
        return method1_DP(s);
    }
    
    // Use Dynamic Programming
    //state: f[i][j]: 字符 i-->j 是不是 Palindrome
    //transition f[i][j] = false if s[i] != s[j] 頭尾不相同 
    //                else = f[i+1][j-1]    
    string method1_DP(string s){
        
        int n = s.size();
        bool dp[n][n]= {0};
        int right = 0;
        int left = 0;
        int len = 0;
        
        for(int j=0;j<n;j++){                //j在前面
            for(int i=0;i<j;i++){
                if(s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])){   //2 及3 個以上
                    dp[i][j] = true;
                } else {
                    dp[i][j] = false;
                }
                
                if (dp[i][j] && len < j - i + 1) {
                    len = j - i + 1;
                    left = i;
                    right = j;
                }                    
            }
            dp[j][j] = true;
        }
        return s.substr(left, right-left+1);        
    }
    
};
