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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1){
            return head;
        }

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;

        ListNode* first = NULL;
        ListNode* nextfirst = NULL;

        int n = 0;

        while(temp != NULL){
            n++;
            temp = temp -> next;
        }

        temp = head;
        first = temp;

        for(int i = 0 ; i < (n/k) ; i++){
            nextfirst = temp;

            for(int j = 0 ; j < k ; j++){
                nextNode = temp->next;
                temp->next = prev;

                prev = temp;
                temp = nextNode;
            }

            if(i == 0){
                head = prev;
            }
            else{
                first -> next = prev;
            }

            first = nextfirst;
        }

        first -> next = temp;

        return head;
    }
};