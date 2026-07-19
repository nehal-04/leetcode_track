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
    ListNode* getkthnode(ListNode* curr , int k){
        k--;
        while(curr!=nullptr && k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseList(ListNode*curr){
        ListNode* prev=nullptr;
        ListNode* nextnode=nullptr;
        while(curr!=nullptr){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
        
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev=nullptr;
        ListNode* nextnode = nullptr;
        while(temp!=nullptr){
            ListNode* kthnode = getkthnode(temp,k);
            if(kthnode == nullptr){
                if(prev) prev->next = temp;
                break;
            }

            nextnode = kthnode->next;
            kthnode->next = nullptr;
            ListNode* first = reverseList(temp);
            if(prev == nullptr){
                head=first;
                prev = temp;
            }
            else{
                prev->next=first;
                prev=temp;
            }
            temp = nextnode;
        }
        return head;


    }
};