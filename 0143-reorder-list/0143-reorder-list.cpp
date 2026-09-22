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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *nextNode;

        if(head == NULL || head->next == NULL)
        return;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = (fast -> next) -> next;
        }

        while(slow != NULL){
            st.push(slow);
            slow = slow -> next;
        }

        while(!st.empty()){
            nextNode = head -> next;
            head -> next = st.top();
            (head -> next) -> next = nextNode;
            head = (head -> next) -> next;
            st.pop();
        }

        head -> next = NULL;
    }
};