class Solution {
public:
    int climbStairs(int n) {
        
        //Dynamic Programming : 出現過的子問題會被儲存起來 以空間換取時間 節省重複計算的時間 
        //ex. F(5) = F(4) + F(3)    而F(4) 與 F(3) 之前已經算過存起來了
        
        //Fibonacci series.
        //F(n) = F(n-1) + F(n-2)  (轉移方程)
        
        //state:    F(i)   
        //initial:  F(0) = 1, F(1) = 1         因為 F(2) = F(1) + F(0) = 2 --> (1,1) or (2)
        //function: F(i) = F(i-1) + F(i-2)     每一階 只跟其前一階與其前兩階 有關       
        //result:   F(n)
        
        //O(n)---->O(2)
        //state: prev, current
        //initial: prev = 1, current = 1
        //function: current = current + prev
        //result: current
        
        if(n==1) return 1;
        if(n==2) return 2;
        
        int current = 2;     //F(2)
        int prev    = 1;     //F(1)
        
        for(int i=3;i<=n;i++){
            
            current = current + prev;     //F(3) = F(2) + F(1)
            prev = current-prev;          //F(2) = F(3) - F(1)
        
        }
        
        return current;
        
    }
};
