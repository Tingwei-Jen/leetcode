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
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return true;
        
        ListNode* p = head;
        ListNode* q = head;
        ListNode* start_second;
        while(p!=NULL && p->next !=NULL){    //p->next != NULL 要放後面
            p = p->next->next;               //為了找到mid p一次移動q的兩倍
            q = q->next;
        }
        
        if (!p)     //偶數個node       
            start_second = q;              //ex. 012345       q在3
                                           //ex. abccba       start_second 從3的位置開始
        else if(!p->next)     //奇數個node
            start_second = q->next;        //ex. 0123456      p在6 q在3 
                                           //ex. abcdcba      start_second 從4的位置開始
        
        q = NULL;        //切開兩個list
    
        ListNode* head2 = reverseList(start_second); //反轉
        
        while(head2){                      //比較
            
            if(head->val != head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
        
    }
    
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
