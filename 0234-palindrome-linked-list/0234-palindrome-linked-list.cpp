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
        

        // reversing

        ListNode* reversedHead = NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            ListNode* newNode = new ListNode(temp -> val);
            newNode -> next = reversedHead;
            reversedHead = newNode;
            temp = temp -> next;
        }

        ListNode* curr = head;
        ListNode* curr2 = reversedHead;

        while(curr != NULL && curr2 != NULL){
            if(curr -> val != curr2 -> val){
                return false;
            }

            curr = curr -> next;
            curr2 = curr2 -> next;
        }
        return true;
    }
};