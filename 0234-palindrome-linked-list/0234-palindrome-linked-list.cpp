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
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast != nullptr && fast->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }

        if(fast != nullptr){
            slow=slow->next; // the LL is odd length
        }
        ListNode* prev=nullptr;
        ListNode* nextnode=nullptr;
        while(slow){
            nextnode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextnode;
        }
        ListNode * sec=prev;
        ListNode* first=head;
        while(sec!=nullptr){
            if(sec->val != first->val) return false;
            sec=sec->next;
            first = first->next;
        
        }
        return true;

    }
    
};