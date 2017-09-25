/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head ==NULL || head->next==NULL)
            return head;
        
        ListNode *cur = head;
        
        while(cur->next != NULL){
            
            if(cur->val == cur->next->val){      // 如果相同的話 跳過 直接指到下一個
             
                cur->next = cur->next->next;        
            
            } else {                             // 如果不一樣 就將current 的指針 指到下一個位置 繼續run 迴圈
            
                cur = cur->next;
            
            }
            
        }
        
        return head;
        
    }
};
