#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k);

int main(void)
{

}

struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode *p = head;

    if(!p){
        return NULL;
    }

    int len = 1;    //length of the list
    while (p->next)
    {
        p = p->next;
        len++;
    }
    p->next = head;         //link the tail and the head to form a circular list
    
    struct ListNode *new_head = head;
    int m = len - k%len;    //rotate k places right is equal to m places left
    while (m-- != 0)
    {
        new_head = new_head->next;    //rotating the list left means moving the head right
        p = p->next;
    }
    p->next = NULL;     //cut the link between the new head and tail

    return new_head;
}