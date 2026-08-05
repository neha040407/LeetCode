/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int val1, val2 , carryover = 0 , sum;
    struct ListNode *l3 = NULL;
    struct ListNode *temp1 , *temp2 , *temp3;
    temp1 = l1;
    temp2 = l2;
    temp3 = l3;

    while(temp1 != NULL || temp2 != NULL){

        if(temp1 != NULL){
            val1 = temp1 -> val;
        }
        else{
            val1 = 0;
        }
        
        if(temp2 != NULL){
            val2 = temp2 -> val;
        }
        else{
            val2 = 0;
        }


        sum = val1 + val2 + carryover;
        carryover = sum / 10;
        sum = sum % 10;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;

        newNode -> val = sum;
        if (l3 == NULL) {
            l3 = newNode;
            temp3 = newNode;
        } else {
            temp3->next = newNode;
            temp3 = newNode;
        }

        if (temp1 != NULL)
            temp1 = temp1->next;

        if (temp2 != NULL)
            temp2 = temp2->next;
    }

    if(carryover > 0){
        struct ListNode *newNode = malloc(sizeof(struct ListNode));
        newNode->next = NULL;
        newNode -> val = carryover;
        temp3->next = newNode;
        temp3 = newNode;
    }


    return l3;
}


