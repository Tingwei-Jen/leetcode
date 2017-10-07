class Solution {
public:
    double myPow(double x, int n) {
        
        //If n is Integer.MIN_VALUE, the -n will have overflow runtime error.
        //因為 1---255;   -256 +1 = -255 --> 255
        //Complexity = O(logn)
        
        if(n==0 || x==1) return 1;
        if(n==1) return x;
        if(n<0) return 1/(x*myPow(x, -(n+1)));    // if 2(-3) --> 1/[2(2)*2]
        
        double res = 1;
        while(n>1){
            
            if(n%2==1){   //奇數
                res*=x;
            }
            x = x*x;
            n/=2;         //9--->4 , 15-->7
        }
        res *= x;
        return res;   
    }
};
