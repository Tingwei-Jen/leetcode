class Solution {
public:
    bool isPalindrome(string s) {
        
        int start = 0;
        int end = s.size()-1;
        
        while(start<end){    
            if(!isalnum(s[start])) start++;       //遇到非字母跳過
            else if (!isalnum(s[end])) end--; 
            else {
                if(tolower(s[start++]) != tolower(s[end--]))      //算完之後 +1
                    return false;   
            }
        }
        return true;
        
    }
};
