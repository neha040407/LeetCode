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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1;

        if(head == NULL){
            return NULL;
        }

        ListNode *temp = head;

        while(temp -> next != NULL){
            n++;
            temp = temp -> next;
        }

        k = k % n;
        temp -> next = head;

        for(int i = 0 ; i < n-k ; i++){
            head = head -> next;
            temp = temp -> next;
        }

        temp -> next = NULL;

        return head;
    }
};