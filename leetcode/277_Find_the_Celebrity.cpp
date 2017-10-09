// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        
        //問兩遍 第一遍找出 candidate 
        // if (i knows j) i not candidate
        // else j not candidate
        // time complexity : O(n)
        
        int candidate = 0; 
        
        for(int i=1;i<n;i++){
            if(knows(candidate, i)) //candidate not celebrity 
                candidate = i;
        }
        
        //whether candidate is real
        for(int i=0;i<n;i++){
            if(i != candidate && knows(candidate, i) || !knows(i, candidate)) return -1;
        }
        return candidate;
        
        
        //O(n2) method
        /*vector<bool> can(n, true);
        
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(can[i] && i!=j){
                    if(knows(i,j) || !knows(j,i)){
                        can[i] = false;
                        break;
                    } else
                        can[j] = false;
                }
                
            }
            if(can[i]) return i;                      //遍歷完一個i 就 檢查一次
        }
        return -1;*/
    }
};
