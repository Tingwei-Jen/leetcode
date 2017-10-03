class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1.size()==0 || num2.size()==0) return "0";
        int l1 = num1.size();
        int l2 = num2.size();
        vector<int> res(l1+l2,0);
        for(int j=l2-1; j>=0;j--){         //從後面乘回來
            for(int i=l1-1; i>=0; i--){
                int mul = (num1[i]-'0')*(num2[j]-'0');
                int positionLow = i+j+1;           //從vector的最後面開始放數字
                int positionHigh = i+j;
                mul += res[positionLow];           //處理進位
                res[positionLow] = mul%10;
                res[positionHigh] += mul/10;
             }
        }
        
        int start = 0;
        while(res[start]==0  && start<(l1+l2)) start++;   //原先設l1+l2 太長 前面很多0    ex. 00032221
        if(start==(l1+l2)) return "0";                    //找到不是0的第一位
        
        string s = "";
        for(int i=start; i<(l1+l2); i++){
            s += (char)(res[i]+'0');    
        }
        return s;
    }
};
