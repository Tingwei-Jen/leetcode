class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        
        for(int i=n-1;i>=0;i--){        //從後面巡回來
            
            if(digits[i]==9){           //位數=9
                
                digits[i] =0;
                
            } else {
                
                digits[i] +=1;          //包含進位後 下一個位數+1
                return digits;          //直接返回
                
            }
            
        }
 
        //999999999999 +1 的情況：
        digits[0] = 1;
        digits.push_back(0);
        return digits;
        
        
        
    }
};
