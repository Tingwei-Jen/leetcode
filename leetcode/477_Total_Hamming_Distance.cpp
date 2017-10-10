class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
     
        //return method1(nums);
        return method2(nums);
        
    }
    int method2(vector<int>& nums){
        
        //4:  0100
        //14: 1110
        //2:  0010
        //1:  0001
        
        //第四行 HammingDistance = 3, 第三行 HammingDistance = 4 第二行 HD = 4 第一行 HD = 3 total = 14 
        //每一行 HD= 0的個數*1的個數
        int res =0;
        int onecount = 0;
        for(int j=0; j<32; j++){
            
            onecount = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>>j & 1) 
                    onecount++;
            }
            res += onecount*(nums.size()-onecount);
        }
        return res;
    }

    //超時！！！
    int method1(vector<int>& nums){
        
        if(nums.size()==0) return 0;
        int res = 0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1; j<nums.size();j++){
                res+=HammingDistance(nums[i],nums[j]);
            }
        }
        return res;        
    }
    int HammingDistance(int x, int y){
        
        int n = x^y ; //XOR               //XOR: 11--0
        int dis = 0;                      //     10--1
                                          //     01--1
                                          //     00--0
        while(n>0){
            if(n&1==1) dis++;           
            n>>=1;
        }
        return dis;
    }
};
