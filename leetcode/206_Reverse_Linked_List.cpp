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
       
        if (head==NULL || head->next==NULL) return head;
        
        // 順序：prev cur next 一次移動一格
        ListNode* prev = NULL;             
        ListNode* cur = head;
        ListNode* next = cur->next;
        
        while(cur!=NULL){           
            cur->next = prev;          //ex. [3,2,1] 3原先指向2  變成指向null
            prev = cur;                //prev 往前移動 現在是3的位置
            cur = next;                //cur 往前移動 現在是2的位置
            if(cur != NULL){
                next = cur->next;
            }           
        }
        return prev;
    }
};
