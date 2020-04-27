#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);

int main(void)
{

    return 0;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* p = head->next;
    int len = 1;
    while (p->next)
    {
        len++;
        p = p->next;
    }
    int pos = len-n;
    int i = 1;
    p = head;
    while (i < pos)
    {
        p = p->next;
        i++;
    }
    struct ListNode* q = p->next;
    p->next = q->next;
    free(q);
    return head;
}