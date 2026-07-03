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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
            //this will ensure when second loop completes , slow will be 1 behinc the one we want to eliminate
        }
        ListNode* prev = nullptr;
        if(fast==nullptr){
            ListNode* new_n=head->next;
            delete(head);
            return new_n;
        }
        while(fast != nullptr){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        delete(slow);
        return head;


    }
};