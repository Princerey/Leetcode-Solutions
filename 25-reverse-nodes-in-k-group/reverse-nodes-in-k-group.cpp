class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int cnt = 0;
        ListNode* counter = head;
        ListNode* temp = head;
        ListNode* ans = head;
        while(counter!=NULL){
            cnt++;
            counter = counter->next;
        }
        cnt /= k;
        stack<int> st;
        int k1 = k;

        while(temp!=NULL){
            st.push(temp->val);
            k1--;
            temp = temp->next;
            if(k1==0){
                while(!st.empty()){
                    ans->val = st.top();
                    st.pop();
                    ans = ans->next;
                }
                cnt--;
                k1 = k;
            }
            
        }
        return head;
    }
};