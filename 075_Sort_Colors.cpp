class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        //method1 : counting sort(計數排序)
        /*int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        for(int i=0; i<nums.size();i++){    
            if(nums[i]==0)
                count1++;
            else if (nums[i]==1)
                count2++;
            else
                count3++;    
        }
        for(int i=0;i<count1;i++){
            nums[i] = 0;
        }
        for(int i=0;i<count2;i++){
            nums[i+count1] = 1;
        }
        for(int i=0;i<count3;i++){
            nums[i+count1+count2] = 2;
        }*/
        
        //method2: two pointers
        if(nums.empty() || nums.size()<=1) return; 
        int nFirst = 0;                //nFirst 以左都是0
        int nSecond = nums.size()-1;   //nSecond 以右都是2
        
        while(nFirst < nums.size() && nums[nFirst]==0) nFirst++;   //此時nFirst 指到一個不是0的位置 ex. 001 nFirst 在1的地方
        while(nSecond>=0 && nums[nSecond]==2) nSecond--;           //此時nSecond 指到一個不是2的位置
        
        //遇到2 把2跟nsecond 的值互換 nsecond 往左 
        //同樣遇到0 把0跟nFirst 的值互換 nFirst 往右
        int index = nFirst;
        while(index<=nSecond){
            if(nums[index]==1) 
                index++;
            else if (nums[index]==0){
                nums[index] = nums[nFirst];
                nums[nFirst] = 0;
                nFirst++;
                index++;                                //交換前 index指到的數已經看過了所以index++
            } else {
                nums[index] = nums[nSecond];
                nums[nSecond] = 2;
                nSecond--;                              //交換後 index指到的數是新的值 所以index 不++ 下次loop 再看一次這個index
            }
        }
    }
};
