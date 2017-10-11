class Solution {
public:
    int countSubstrings(string s) {
        //https://www.youtube.com/watch?v=V-sEwsca1ak
        //第五題延伸
        
        if(s.empty()) return 0;
        
        for(int i=0; i<s.size()-1;i++){
            checkPalindrome(i,i, s);     //以i 為中心檢查 長度為1,3,5,7...是不是palindrome
            checkPalindrome(i,i+1, s);   //以i, j為中心檢查 長度為 2,4,6,8 ..是不是palindrome
        }
        count++;                         //加上最後一個character
        return count;                  
    }
    void checkPalindrome(int i, int j, string s){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            count++;
            i--;                    //往兩邊檢查
            j++;
        }
    }
    
private:
    int count = 0;
   
};
