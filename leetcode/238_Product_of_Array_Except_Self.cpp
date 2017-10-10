class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      //前面乘積 * 後面乘積  
      //ex.[1,2,3,4,5]
      //front = [1,1,2,6,24]  //從前面乘到後面
      //back = [120,60,20,5,1] //從後面乘回來
      //res = [120 60 40 30 24]
        
        //return method1(nums);
        return method2(nums);
    }
    
    vector<int> method2(vector<int>& nums){         //optimize space complexity
        
        //把front 累積在res中 再把back乘進去
        vector<int> res(nums.size(),1);
        
        for(int i=0;i<nums.size()-1;i++){
            res[i+1] = res[i]*nums[i];
        }
        int back = 1;
        for(int i=nums.size()-1; i>=0;i--){
            res[i]*= back;      //res*1
            back*=nums[i];   //back:1-->5
        }
        return res;      
    }
    vector<int> method1(vector<int>& nums){
        
        vector<int> front(nums.size(),1);
        vector<int> back(nums.size(),1);
        vector<int> res(nums.size(),1);
        
        for(int i=0;i<nums.size()-1;i++){
            front[i+1] = front[i]*nums[i];
        }
        for(int i=nums.size()-1; i>0;i--){
            back[i-1] = back[i]*nums[i];
        }
        for(int i=0;i<nums.size();i++){
            res[i] = front[i]*back[i];
        }
        return res;           
    }
    //暴力解：O(n2)
    //題目要：O(n)
};
