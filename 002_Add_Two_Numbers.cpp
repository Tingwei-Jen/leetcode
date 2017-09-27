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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        //其实做这种大数加减的题目不管是用的大数组还是链表，都是一样的：
        //首先做个大循环，对每一位进行操作：
        //当前位：(A[i]+B[i])%10
        //进位：（A[i]+B[i]）/10
        
        
        
        ListNode *list = new ListNode(0);   //儲存輸出的結果，因為list的指針要不斷往後移，因此用一個假節點方便操作 
        ListNode *res = list;               // 使用一個ListNode來儲存相加的結果
        
    
        int sum;
        int carry = 0;                        //carry 處理進位
        
        
        while(l1 || l2 || carry>0){           //當 list1, list2 都沒有值，而且carry也為0的時候才結束迴圈
            
            sum = 0;
            
            if (l1){                          // list1與list2長度可能不同，分開處理
                sum += l1->val;
                l1 = l1->next;                //尋訪
            } 
            if (l2){
                sum+=l2->val;
                l2 = l2->next;
            }
            
            sum += carry;                      //如果之前有進位 carry =1, 如果沒有 carry =0
            
    
            int n = sum%10; 
            list->next = new ListNode(n);      //相加如果超過9，只能留下個位數放入結果list，十位數的地方進位 
            carry = sum/10;
            
            list = list->next;
    
        }
        
        return res->next;
        
    
    }
};
