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
        ListNode* check = head;

        for(int i = 0; i < k; i++){
            if(check == NULL) return head;
            check = check -> next;
        }

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* newNode = NULL;
        
        int count = 0;
        while(curr != NULL && count < k){
            newNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = newNode;
            count++;
        }

        if(newNode != NULL){
            head -> next = reverseKGroup(newNode, k);
        }

        return prev;
    }
};