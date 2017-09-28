class Solution {
public:
    int reverse(int x) {                     //抓個位數 用 "％"  往前抓 十位百位用 "/"
        
        long long res = 0;                   
        
        while(x!=0){                          //ex: 123   res = 0+3, x = 12;   res = 30+2, x = 1;
            
            int k = x%10;                     //x 的個位數
            x/=10;
            
            res = res*10;                     // 原本的數往前一位
            res = res + k;                    // 加上新的各位數
            
            
            //res = res*10 + x%k;
            //x/=10;
            
        }
        
        return (res>INT_MAX || res<INT_MIN)? 0 : res;
        
    }
};
