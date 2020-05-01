#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head);
void reverseList(struct ListNode* head);

int main(void){

}

void reorderList(struct ListNode* head)
{
    struct ListNode *slow = head, *fast = head;
    while (slow->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode *headtmp = slow->next;
    slow->next = NULL;
    reverseList(headtmp);
    
    struct ListNode *p1 = head, *p2 = headtmp, *tmp;
    while (p2)
    {
        tmp = p2->next;
        p2->next = p1->next;
        p1->next = p2;
        p1 = p2->next;
        p2 = tmp;
    }
}

void reverseList(struct ListNode* head)
{
    struct ListNode *p = head, *q = head, *tmp;
    while (q->next)
    {
        q = q->next;
    }
    head = q;
    while (p != head)
    {
        tmp = p->next;
        q->next = p;
        q = p;
        p = tmp;
    }
}