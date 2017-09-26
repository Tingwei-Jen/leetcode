class Solution {
public:
    int mySqrt(int x) {
        
        if (x==0) 
            return 0;

        // binary search
        long long left = 1;
        long long right = x;
         
        while(left < right){
            
            long long mid = (left+right)/2;
            
            if (mid*mid == x)
                return mid;
            else if (mid*mid >x)
                right = mid-1;
            else 
                left = mid +1;
        }
        
        return left*left > x ? (left-1) : left;               //left平方 在 x 旁邊
        
        
        //newton's method     Xn+1 = Xn - f(Xn)/f'(Xn)             f(Xn) = X2-n = 0 求方程式解
        // xi+1=xi - (xi2 - n) / (2xi) = xi - xi / 2 + n / (2xi) = xi / 2 + n / 2xi = (xi + n/xi) / 2
        
        /*double res = 1;
        double pre = 0;
        
        while(res!=pre){
            pre = res;
            res = (res + x / res) / 2; 
        }
        
        return int(res);*/
        
        
        
    }
};
