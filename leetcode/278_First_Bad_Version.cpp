// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        // 000000111111   find first "1"
        int target;
        int left = 0;
        int right = n;
        
        while(left<right){
            int mid = left+ (right-left)/2;
            if(isBadVersion(mid) == 1 && isBadVersion(mid-1) == 0) return mid;
            if(isBadVersion(mid) == 1)  
                right = mid;
            else if (isBadVersion(mid) == 0)
                left = mid+1;
        }
        //最後 left = right
        return left;    
    }
};
