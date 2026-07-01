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
    ListNode* swapPairs(ListNode* head) {
        // for 1 element if its null
        if(head == NULL || head -> next == NULL) return head;

        // swaping first 2 element

        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        int count = 0;

        while(temp != NULL && count < 2){
            forward = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = forward;
            count++;
        }

        // for the remaining element i am doing recursion

        if(forward != NULL){
            head -> next = swapPairs(forward);
        }

        return prev;

    }
};