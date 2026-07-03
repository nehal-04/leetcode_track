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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* beforeL=nullptr;
        ListNode* afterR=nullptr;
        ListNode* temp=head;
        int l=1;
        while(temp!=nullptr){
            if(l==left-1){
                beforeL=temp;
            }
            else if(l==right+1){
                afterR=temp;
            }
            temp=temp->next;
            l++;
        }
        ListNode* curr= (beforeL)? beforeL->next : head;
        ListNode* prev= afterR;
        ListNode* nextNode=curr->next;
        l=0;
        while(l< right-left+1){
            nextNode = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
            l++;
        }
        if(beforeL!=nullptr){
            beforeL->next=prev;
            return head;
        }
        else return prev; 
        
        
    }
};