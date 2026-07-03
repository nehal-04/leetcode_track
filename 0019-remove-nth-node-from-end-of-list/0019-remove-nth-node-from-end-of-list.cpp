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
        ListNode* temp=head;
        int ct=0;
        while(temp!=nullptr){
            ct++;
            temp=temp->next;
        }
        int ct_todel= ct-n+1;
        if(ct_todel == 1){
            ListNode* new_one=head->next;
            delete(head);
            return new_one;
        }
        ListNode* prev=nullptr;
        temp=head;
        for(int i=1;i<=ct_todel-1;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete(temp);
        return head;

    }
};