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
private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || left == right) return head;

        ListNode* prevLeft = NULL;
        ListNode* leftNode = head;
        ListNode* rightNode = head;

        // Move leftNode to left position
        for(int i = 1; i < left; i++){
            prevLeft = leftNode;
            leftNode = leftNode->next;
        }

        // Move rightNode to right position
        rightNode = leftNode;
        for(int i = left; i < right; i++){
            rightNode = rightNode->next;
        }

        // Save next part
        ListNode* nextNode = rightNode->next;

        // Cut the list
        rightNode->next = NULL;

        // Reverse the middle part
        ListNode* newHead = reverse(leftNode);

        // Connect first part
        if(prevLeft != NULL)
            prevLeft->next = newHead;
        else
            head = newHead;

        // Connect last part
        leftNode->next = nextNode;

        return head;
    }
};