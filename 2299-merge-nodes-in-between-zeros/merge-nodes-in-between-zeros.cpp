/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        ListNode* cur = head;
        ListNode* ptr = cur;
        int s = 0;
        while(cur && cur->next){
            if(cur->val==0){
                s = 0;
                ptr = cur->next;
                while(ptr->val!=0){
                    s+=ptr->val;
                    ptr=ptr->next;
                }
                cur->val = s;
            }
            cur->next=ptr;
            cur=ptr;
        }
        cur=head;
        while(cur->next->next!=NULL){cur=cur->next;}
        delete cur->next;
        cur->next = NULL;
        return head;
    }
};