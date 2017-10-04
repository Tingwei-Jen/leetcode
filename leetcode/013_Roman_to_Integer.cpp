class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> T = { { 'I' , 1 },              //IV = 4 = 5-1
                                       { 'V' , 5 },              //IX = 9 = 10-1
                                       { 'X' , 10 },             //XL = 40 = 50-10 
                                       { 'L' , 50 },          
                                       { 'C' , 100 },            //XC = 90 = 100-10
                                       { 'D' , 500 },
                                       { 'M' , 1000 } };
        
        int res=0;
        for(int i=0; i<s.size()-1;i++){
            
            if(T[s[i]]>=T[s[i+1]])
                res+=T[s[i]];
            else 
                res-=T[s[i]];   
        }
        res+=T[s[s.size()-1]];           //再把最後一位加上去
        return res;
    }
};
