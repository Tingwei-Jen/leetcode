class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        //Edit distance: 量測方式是看至少需要多少次的處理才能將一個字符串變成另一個字符串
        
        //1. modify(取代)
        //abcde
        //abxde
        //2. insertion
        //abcde
        //abxcde
        //3. append
        //abcde
        //abcdex
        
        if(t.size()>s.size()) swap(s,t);                    //let s be longer one
        
        int lens = s.size();
        int lent = t.size();
        
        int diff = lens-lent;
        
        if(diff>1) return false;               //長度差大於1 return false
        else if(diff==1) {                     //長的去掉一個字符 剩下要與短的一樣  one edit distance
            for(int i=0; i<lent; i++){
                if(s[i] != t[i]){
                    return s.substr(i+1) == t.substr(i);
                }
            }
            return true;                       //append 的情況
        }
        else {                                //長度相同 只能有一個地方不一樣  one edit distance
            
            int count = 0;
            for(int i=0;i<lent;i++){
                if(s[i]!=t[i]) count++;     
            }
            return count==1;
        }
    }
};
