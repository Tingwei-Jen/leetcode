class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int n = x^y ; //XOR               //XOR: 11--0
                                          //     10--1
                                          //     01--1
                                          //     00--0
        int dis = 0;
        while(n>0){
            if(n&1==1) dis++;           
            n>>=1;
        }
        return dis;
    }
};

//ex. 4(0100) 1(0001) 4^1 = 0101
//0101 & 0001 == 0001   dis++;     0101>>=1
//0010 & 0001 == 0000 
//0001 & 0001 == 0001   dis++;
