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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* newNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = newNode;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode* newHead = reverse(head);
        if(n == 1){
            newHead = newHead -> next;
            return reverse(newHead);
        }

        ListNode* prev  = NULL;
        ListNode* curr = newHead;
        while(n > 1){
            prev = curr;
            curr = curr -> next;
            n--;
        }

        prev -> next = curr -> next;
        curr -> next = nullptr;
        delete curr;
        return reverse(newHead);
    }
};