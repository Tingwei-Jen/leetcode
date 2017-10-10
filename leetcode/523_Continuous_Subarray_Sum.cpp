class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //return method1(nums,k);
        return method2(nums,k);
    }
    
    //遍歷全部組合
    bool method1(vector<int>& nums, int k){
        
        for(int i=0; i<nums.size();i++){            
            int sum = nums[i];
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k) return true;
                if(k!=0 && sum%k==0) return true;     //整除return true
            }
        }
        return false;
    }
    bool method2(vector<int>& nums, int k){
        
        //若数字a和b分别除以数字c，若得到的余数相同，那么(a-b)必定能够整除c。
        //a = cx+ r1
        //b = cy+ r2
        //(a-b) = c(x-y);
        //那么我们用一个集合set来保存所有出现过的余数，如果当前的累加和除以k得到的余数在set中已经存在了，
        //那么说明之前必定有一段子数组和可以整除k。
        //ex. [a,b,c,d,e], (a+b+c)%k = (a+b+c+d+e)%k 餘數相同
        //所以 (a+b+c+d+e)-(a+b+c) 為k的倍數
        
        int remainning = 0;
        int sum =0;
        int pre = 0;                            //規定 Continuous Subarray least 等於2
        unordered_set<int> set;    //記錄餘數
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(k==0) remainning =sum;                             //k =0, 看sum 會不會等於0
            else remainning = sum%k;
            if(set.find(remainning) != set.end()) return true;
            set.insert(pre);
            pre = remainning;
        }
        
        return false;
    }
};
