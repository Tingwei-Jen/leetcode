class Solution {
public:
    int maxArea(vector<int>& height) {
        
        //area = (right-left)*min(height[left], height[right])
        //two pointer problem: 從兩邊往中間移動
        //每次換掉 高度較小的希望得到新的較高的高度
        
        int area = 0;
        int left = 0;
        int right = height.size()-1;
        
        while(left<right){
            
            int temp = (right-left)*min(height[left], height[right]);
            area = max(area, temp);
            
            if (height[left] < height[right]){
                left++;
            } else {
                right--;
            }
            
        }
        return area;  
    }
};
