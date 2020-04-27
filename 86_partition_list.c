#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* partition(struct ListNode* head, int x);

int main(void)
{

}

struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode* p = head, *pre, *pivot, *pivot_pre;
    while (p->val < x)
    {
        p = p->next;
    }
    if (p == head)
    {
        pivot = p;
    }
    else
    {
        pivot = p;
        p = head;
        while (p->next != pivot)
        {
            p = p->next;
        }
        pivot_pre = p;
    }
    
    struct ListNode* new_head;
    p = head;
    while (p->val >= x)
    {
        p = p->next;
    }
    new_head = p;
    
    pre = new_head;
    p = pre->next;
    while (p)
    {
        if (p->val < x)
        {
            pre->next = p->next;
        }
        
    }
    
}