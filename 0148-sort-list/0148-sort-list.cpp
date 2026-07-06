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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode dummy;
        ListNode* tail = &dummy;

        while(head1 != NULL && head2 != NULL){
            if(head1 -> val < head2 -> val){
                tail -> next = head1;
                head1 = head1 -> next;
            }
            else{
                tail -> next = head2;
                head2 = head2 -> next;
            }
            tail = tail -> next;
        }

        if(head1 != NULL) tail -> next = head1;
        if(head2 != NULL) tail ->next = head2;


        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head -> next == NULL) return head;
        
        // 1. Finding middle

        ListNode* middle = getMiddle(head);
        ListNode* rightHead = middle -> next;
        middle -> next = NULL;

        // 2. sort recursively both part
        ListNode*  left = sortList(head);
        ListNode* right = sortList(rightHead);

        // 3. merge these two
        return merge(left, right);
    }
};