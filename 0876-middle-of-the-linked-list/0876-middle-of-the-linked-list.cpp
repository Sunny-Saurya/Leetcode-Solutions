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
    int getLen(ListNode* head){
        int count = 0;
        while(head != NULL){
            count++;
            head = head -> next;
        }
        return count;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int len = getLen(head);
        int mid = len/2;

        while(mid--){
            head = head -> next;
        }
        return head;
    }
};