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
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *nextNode = NULL;
        ListNode *prev = NULL;

        if(head == NULL || head->next == NULL)
        return;

        while(fast != NULL && fast -> next != NULL){
            prev = slow;
            slow = slow -> next;
            fast = (fast -> next) -> next;
        }

        prev -> next = NULL;

        prev = NULL;

        while(slow != NULL){
            nextNode = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = nextNode;
        }        

        fast = prev;
        nextNode = head;

        while(nextNode != NULL){
            prev = fast;
            nextNode = head -> next;
            fast = prev -> next;   //just using fast as a var for the next link in 2nd LL
            head -> next = prev;
            prev -> next = nextNode;
            head = (head -> next) -> next;
        }

        prev -> next = fast;

        if(fast != NULL){
            fast -> next = NULL;
        }
    }
};