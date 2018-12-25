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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp1=head, *temp2=head;
        if(!head)
            return head;
        for(int i=0;i<n;i++)
            temp2=temp2->next;
        if(temp2==NULL)
            return head->next;
        while(temp2->next != NULL){
            temp1=temp1->next;
            temp2=temp2->next;
        }
        ListNode* temp3=temp1->next;
        temp1->next=temp3->next;
        delete temp3;
        return head;
    }
};
