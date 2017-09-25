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
    
    //merge 兩個排序過後的list   ex [1,2,2,3] and [1,3]  --> [1,1,2,2,3]
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
     
        ListNode *result = new ListNode(0);       //這邊記得要給值 “ListNode * result” pointer 指向null 
        ListNode *cur = result;   
        
        while(l1 && l2){
            
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        cur->next = l1? l1:l2;
        return result->next;
        
    }
};
