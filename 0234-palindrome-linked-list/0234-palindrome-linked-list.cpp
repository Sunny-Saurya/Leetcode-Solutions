class Solution {
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;

        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return true;

        ListNode* middle = getMiddle(head);

        middle->next = reverse(middle->next);

        ListNode* curr = head;
        ListNode* curr2 = middle->next;

        while(curr2){
            if(curr->val != curr2->val)
                return false;

            curr = curr->next;
            curr2 = curr2->next;
        }

        return true;
    }
};