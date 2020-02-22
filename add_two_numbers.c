#include<stdio.h>
#include<stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

void initList(struct ListNode* l){
    struct ListNode* l = (struct ListNode* )malloc(sizeof(struct ListNode));
    l->next = NULL;
}

void insertList(struct ListNode* l, int value){
    struct ListNode* p = (struct ListNode* )malloc(sizeof(struct ListNode));
    p->val = value;
    p->next = l->next;
    l->next = p;
}

struct ListNode* reverseList(struct ListNode* l){
    struct ListNode* l_rev = (struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* p = l->next;
    struct ListNode* pre = l;

    while (p){
        pre->next = l_rev->next;
        l_rev->next = pre;
        pre = p;
        p = p->next;
    }
    return l_rev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* l1_rev;
    struct ListNode* l2_rev;
    l1_rev = reverseList(l1);
    l2_rev = reverseList(l2);

    int x;
    int y = 0;
    struct ListNode* l = (struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* l_rev = (struct ListNode* )malloc(sizeof(struct ListNode));
    struct ListNode* p1 = l1_rev;
    struct ListNode* p2 = l2_rev;

    while (p1&&p2)
    {
        x = (p1->val + p2->val) % 10 + y;
        y = (p1->val + p2->val) / 10;
        insertList(l_rev, x);
        p1 = p1->next;
        p2 = p2->next;
    }

    if (p1)
        while (p1)
        {
            insertList(l_rev, p1->val);
            p1 = p1->next;
        }

    if (p2)
        while (p2)
        {
            insertList(l_rev, p2->val);
            p2 = p2->next;
        }

    l = reverseList(l_rev);
    return l;
}