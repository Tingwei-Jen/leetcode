class Solution {
public:
    string convertToTitle(int n) {
        
        string res;
        char temp; 
        
        while(n){
            n = n-1;                     //because start from 1
            temp = 'A' + n%26;           //ASC table  ex. n%26 = 1, temp = 'A' + 1 = 'B'
            res = temp+res;              //new + old
            n/=26;
        }
        return res;
    }
};

// n  n-1  temp            res 
// 28 27   'A' +1 = 'B'    'B' + 0 = 'B'
// 1  0    'A' +0 = 'A'    'A' + 'B' = 'AB'
