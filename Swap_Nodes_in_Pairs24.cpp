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
    ListNode* swapPairs(ListNode* head) {
        ListNode *front=head, *back=head, *front_b=head, *temp;
        if(!head || head->next==NULL)
            return head;
        back=front->next;
        head=back;
        while(back != NULL){
            temp=back->next;
            front_b->next=back;
            back->next=front;
            front->next=temp;
            front_b=front;
            front=temp;
            back=(front!=NULL? front->next:NULL);
        }
        return head;
        
//         if (head == NULL || head->next == NULL) return head;
//         ListNode *ptr1, *ptr2, *temp, *ptr3;
//         ptr1 = head;  //1
//         ptr3 = ptr1;
//         head = ptr1->next; //2
//         while(ptr1 != NULL && ptr1->next != NULL) //ptr1->next->next != NULL)
//         {            
//             ptr2 = ptr1->next; //2
//             temp = ptr2->next; //3
//             ptr2->next = ptr1;
//             ptr3->next = ptr2;
//             ptr1->next = temp; //3
//             ptr3 = ptr1; //keep one more ref
//             ptr1 = temp; //3
//         }
        

//         return head;
    }
};
