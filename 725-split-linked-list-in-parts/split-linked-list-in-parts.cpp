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
    vector<ListNode*> v;
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz=0; ListNode * temp=head, *tempHead=head;
        for(ListNode * cur = head ; cur ; cur = cur->next) sz++;
        int split=0, ctr=0; ListNode * cur = head;
            
        while(sz){ 
            split=ctr=ceil((double)sz/(double)k);
            sz-=split; k--;
                while(ctr>0){
                    if(split == ctr) {tempHead=cur; temp=cur;}
                    ctr--;
                    if(ctr!=0) { cur=cur->next; temp=temp->next;} 
                    else{ cur=cur->next; temp->next=nullptr; v.push_back(tempHead);}
                }
            }
        if(k!=0){
            while(k--){
                ListNode * extra=nullptr;
                v.push_back(extra); 
            }
        } 
        return v;
    }
};