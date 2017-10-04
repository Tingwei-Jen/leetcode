class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size()==0) return 0;
        int m = haystack.size();
        int n = needle.size();
        
        for(int i=0; i<m-n+1;i++){
            int j=0;
            for(j;j<n;j++){       
                if(haystack[i+j] != needle[j])       
                    break;                   
            }
            if(j==n) return i;                      //找到答案
        }
        return -1;
    }
};
