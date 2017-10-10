class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int c1 = INT_MAX;
        int c2 = INT_MAX;
        
        for(int num: nums){
            if(num<=c1)             //num比c1小
                c1 = num;
            else if (num<=c2)       //num比c1大 比c2小
                c2 = num;
            else                    //num 比c1 c2 大
                return true;
        }
        return false;
    }
};

// ex. 1  2  3           --> 123
//     c1 c2 true;
// ex. 2  1  3  4        --> 134
//     c1 c1 c2 true
// ex. 5  3  4  2  5     --> 345
//     c1 c1 c2 c1 true  
