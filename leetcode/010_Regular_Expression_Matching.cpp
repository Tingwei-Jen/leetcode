class Solution {
public:
    bool isMatch(string s, string p) {
        
        //if s[i] = p[j] || p[j] = '.'  --> T[i][j] = T[i-1][j-1]   
        //if p[j] = "*"  T[i][j] = T[i][j-2] || if s[i] = p[j-1] || p[j-1] = '.' ---> T[i][j] = T[i-1][j] 
        
        int m = s.size();
        int n = p.size();
        
        vector<vector<bool>> f(m+1,vector<bool>(n+1, false));  //補上" "
        
        f[0][0] = true;        
        //Deal with patterns like a* , a*b*, a*b*c*
        for(int j=1; j<=n;j++){
            if(p[j-1] == '*'){                  //因為有補" " 所以位置差一
                f[0][j] = f[0][j-2];
            }
        }

        for(int i=1; i<=m; i++){               //取一個到取所有
            for(int j=1; j<=n; j++){              
                if(p[j-1] == '.' || s[i-1]==p[j-1]){            
                    f[i][j] = f[i-1][j-1];
                } else if (p[j-1]=='*'){
                    if(p[j-2]=='.' || p[j-2]==s[i-1]) {          //*當multiple  s的最後等於*前面一個字符
                        f[i][j] = f[i][j-2] || f[i-1][j];
                    } else {
                        f[i][j] = f[i][j-2];
                    }             
                }
            }
        }
        
        return f[m][n];
    }
};
