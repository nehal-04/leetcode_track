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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        priority_queue<pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>> pq;
        ListNode* head=nullptr;
        ListNode* curr=nullptr;
        for(int i=0;i<lists.size();i++){
            if(lists[i]==nullptr) continue;
            pq.push({lists[i]->val , lists[i]});
        }
        while(!pq.empty()){
            pair<int,ListNode*> p =pq.top();
            pq.pop();
            ListNode* node=p.second;
            if(head==nullptr){
                head=node;
                curr=node;
            }
            else{
                curr->next=node;
                curr=curr->next;
            }
            if(node->next!=nullptr){
                pq.push({node->next->val , node->next});
            }

        }
        if(curr!=nullptr) curr->next=nullptr;
        return head;

        
    }
};