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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        
        //C++ code O(NlogK) in time, O(1) in space, Divide_Conquer
        
        
        if(lists.size()==0)
            return NULL;
        if(lists.size()==1)
            return lists[0];
    
        //控制每隔多少
        for(int step=1;step<lists.size();step*=2){          //1,2,4,8.....
            
            //遍历所有可以合并的选项
            for(int i=0; i<lists.size(); i+=step*2){         // [01][23](step=1, i一次跳2).... [02][46](step=2, i一次跳4)...  ..
                                                             // ( step=4 i 一次跳8 )
                if(i+step >= lists.size()) break;            //   ">="   超過長度 break;
                lists[i] = merge2list(lists[i],lists[i+step]);
                
            }
        }
        
        return lists[0];
        
    }
    
    
    ListNode* merge2list(ListNode* l1, ListNode* l2){
        
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
