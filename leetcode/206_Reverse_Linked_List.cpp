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
    ListNode* reverseList(ListNode* head) {
       
        if (!head){
            return NULL;
        }
        
        if (!head->next){
            return head;
        }
        
        ListNode *prev = head;
        ListNode *cur = head->next;
        prev->next = NULL;
        
        //ex [3,2,1]
        //1. temp = 2, prev = 3, cur = 1   ---> 2,3,1 --> prev = temp, prev = 2
        //2. temp = 1, prev = 2,  再把2接到1的後面 -->1,2,3
        
        while(cur !=NULL){
            
            ListNode *temp = cur;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
            
        }
        
        return prev;
        

        
        
    }
};
