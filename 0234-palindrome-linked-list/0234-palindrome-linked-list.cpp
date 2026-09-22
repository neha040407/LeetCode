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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = NULL;
        ListNode *nextNode = NULL;
        while(fast != NULL && fast -> next != NULL){
            fast = (fast -> next) -> next;
            nextNode = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = nextNode;
        }

        if(fast != NULL && prev != NULL){
            slow = slow -> next;
        }
        
        //now the frst half is reversed and in case of odd number of elements, got rid of middle one

        while(prev != NULL && slow != NULL){
            if(prev -> val != slow -> val){
                return 0;
            }
            prev = prev -> next;
            slow = slow -> next;
        }

        return 1;

    }
};