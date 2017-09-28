class Solution {
public:
    int numDecodings(string s) {
        
        //Dynamic Programming
        //排到後面的結果數量 只跟其前面兩位有關
        //與爬樓梯類似 可以一個一個看 也可以兩個一起看
        
        //ex.  xxxxxx123 : 若指到3  可以看成   (xxxx12) 3 or (xxxxx1) 23 
        //所以f(i) = f(i-1) + f(i-2)
        
        //若指到0 必須與前一個數一起看  所以 n(i) = 0 ---> f(i) = f(i-2)
        //若前一個是0 只能單獨看       所以 n(i-1) = 0 -----> f(i) = f(i-1)
        
        //若兩個一起看超過26 只能單獨看 所以 n(i-2) = 2 && n(i-1) >6 ---> f(i) = f(i-1)
        
        //state: f(i)
        //inti:  f(0) = 1, f(1) = 1
        //function: f(i) = f(i-1) + f(i-2)
        //res: f(n)
        
        //O(n) --> O(1)
        //state: current, prev
        //init:  current = 1, prev =1
        //function: current = current + prev
        //res: current
        
        
        if(s.size()==0) return 0;
        if(s[0]=='0') return 0;
        
        int current = 1;               //F(1)
        int prev = 1;                  //F(0)
        
        for(int i=1; i<=s.size();i++){
            
            int temp = current;        //因為current 會一直變 所以先記錄起來
            
            if(s[i]=='0'){
            
                current = prev;                        //F(2) = F(0)
                if(s[i-1]>'2' || s[i-1]=='0') return 0;    //不是一個可decode 的狀態
            
            }  else if (s[i]!=0){
                
                if(s[i-1] =='1' || s[i-1] =='2' && s[i]<='6')         //兩個一起看要小於26
                    current = current + prev;
                //else if (s[i-1] == '0')
                    //current = current;
            }
            
            prev = temp;                  //尋訪完這個位置 把prev 紀錄一下
        }
        
        return current;
        
    }
};
