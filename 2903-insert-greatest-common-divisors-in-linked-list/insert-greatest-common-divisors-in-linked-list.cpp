class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* cur = head;

        while(cur != NULL && cur->next != NULL){
            prev = cur;
            cur = cur->next;
            int d = __gcd(prev->val, cur->val);
            ListNode* newNode = new ListNode(d);
            newNode->next = cur;
            prev->next = newNode;
        }
        return head;
    }
};