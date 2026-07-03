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
    ListNode* mergesort2sortedlists(ListNode* A, ListNode* B){
        ListNode* dummy = new ListNode(-1);
        ListNode* curr=dummy;
        while(A!=nullptr && B!=nullptr){
            if(A->val <= B->val){
                curr->next=A;
                A=A->next;
                curr=curr->next;
            }
            else{
                curr->next=B;
                B=B->next;
                curr=curr->next;
            }
        }
        while(A!=nullptr){
            curr->next=A;
            A=A->next;
            curr=curr->next;
        }

        while(B!=nullptr){
            curr->next=B;
            B=B->next;
            curr=curr->next;
        }

        curr->next=nullptr;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next ==nullptr) return head;
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while(fast!=nullptr && fast->next != nullptr){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        ListNode* mid=nullptr;
        mid=slow;
        prev->next=nullptr;
        

        ListNode* A = sortList(temp);
        ListNode* B = sortList(mid);
        return mergesort2sortedlists(A,B);



        
    }
};