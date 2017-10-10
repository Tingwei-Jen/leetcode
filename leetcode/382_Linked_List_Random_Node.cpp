/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
  S has items to sample, R will contain the result
*/
/*ReservoirSample(S[1..n], R[1..k])
  // fill the reservoir array
  for i = 1 to k
      R[i] := S[i]

  // replace elements with gradually decreasing probability
  for i = k+1 to n
    j := random(1, i)   // important: inclusive range
    if j <= k
        R[j] := S[i]
*/

class Solution {
    
private:
    ListNode* head;
    
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        //read discuss!!
        //因為不能提前知道長度 所以用Reservoir Sampling
        this->head = head;
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
     
        int res = head->val;
        ListNode* node = head->next;
        int i=2;                            //因為 rand()%2 = [0,1] 選擇一個
        while(node){
            
            int j=rand()%i;                //i=2 p(j) = 1/2;   i=3 p(j) = 1/3;
                                           //means p (we don't touch number in R) 
                                           //is 1/2 and 2/3 = (k/k+i)
            if(j==0) res = node->val;      //然后我们随机数生成为0的话，我们交换水塘中的值和当前遍历到底值
            i++;
            node = node->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
