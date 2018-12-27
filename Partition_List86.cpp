/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || head->next==NULL)
            return head;
        ListNode *head_new=new ListNode(0);
        head_new->next=head;
        ListNode *front=head_new,*behind=head_new;
        while(front->next!=NULL && front->next->val<x)
            front=front->next;
        if(front->next==NULL) return head;
        behind=front;
        while(behind->next!=NULL && behind->next->val>=x)
            behind=behind->next;
        if(behind->next==NULL) return head;
        while(behind->next!=NULL){
            ListNode *temp=front->next, *temp_back=behind->next->next;
            front->next=behind->next;
            behind->next->next=temp;
            behind->next=temp_back;
            front=front->next;
            while(behind->next!=NULL && behind->next->val>=x)
                behind=behind->next;
        }
        return head_new->next;
            
    }
};

or

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0);
        ListNode node2(0);
        ListNode* p1 = &node1;
        ListNode* p2 = &node2;
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = node2.next;
        return node1.next;
    }
};
