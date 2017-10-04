class Solution {
public:
    bool validPalindrome(string s) {
     
        int start = 0;
        int end = s.size()-1;
        
        while(start<end){
            if(s[start] == s[end]){
                start++;
                end--;
            } else {                //s[start] != s[end]  跳過後 用同樣方法確認剩下
                return isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1);
            }
        }
        return true;    
    }

    bool isPalindrome(string s, int start, int end){
        
        while(start<end){
            if(s[start]==s[end]){
                start++;
                end--;
            } else 
                return false;
        }
        return true;    
    }
};
