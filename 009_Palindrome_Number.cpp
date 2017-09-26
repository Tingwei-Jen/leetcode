class Solution {
public:
    bool isPalindrome(int x) {              // reverse interger 後 與原先相同
        
        long long res = 0;
        int target = x;
        
        if (x<0)
            return false;                   //palindrome number must be poistive
        
        while(x!=0){
            
            res = res*10 + x%10;
            x/=10;
            
        }
        
        if (res==target) 
            return true;
        else 
            return false;
        
        
        
    }
};
