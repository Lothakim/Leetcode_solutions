#include<stdio.h>
#include<stdlib.h>

#define HASH_SIZE 99

struct HashNode {
    int key;
    int val;
    struct HashNode *next;
};

struct Hash {
    int size;
    struct HashNode *hash;
};
//采用链地址法解决冲突


void hash_init(struct Hash *self);

void hash_insert(struct Hash *self, int key, int val);

int hash_find(const struct Hash *self, int key);

void hash_free(struct Hash *self);

int hash_get_key_index(struct Hash *self, int key);

int *twoSum(int *nums, int numsSize, int target) {
    struct Hash hash;
    hash_init(&hash);
    for (int i = 0; i < numsSize; ++i) {
        int index = hash_find(&hash, target - nums[i]);
        if (index != -1) {
            int *result = (int *) malloc(sizeof(int) * 2);
            result[0] = index;
            result[1] = i;
            hash_free(&hash);
            return result;
        }
        hash_insert(&hash, nums[i], i);
    }
    hash_free(&hash);
    return NULL;
}

void hash_init(struct Hash *self) {
    self->size = HASH_SIZE;
    self->hash = (struct HashNode *) malloc(sizeof(struct HashNode) * self->size);
    for (int i = 0; i < self->size; ++i)
        self->hash[i].next = NULL;
}

int hash_get_key_index(struct Hash *self, int key) {
    return abs(key) % self->size;
}

void hash_insert(struct Hash *self, int key, int val) {
    struct HashNode *p = self->hash + hash_get_key_index(self, key);
    struct HashNode *new_node = (struct HashNode *) malloc(sizeof(struct HashNode));
    new_node->key = key;
    new_node->val = val;
    new_node->next = p->next;
    p->next = new_node; //将新结点插入每个链表的头部
}

int hash_find(const struct Hash *self, int key) {
    struct HashNode *p = self->hash + hash_get_key_index(self, key);
    while (p->next != NULL) {
        p = p->next;
        if (p->key == key)
            return p->val;
    }
    return -1;
}

void hash_free(struct Hash *self) {
    for (int i = 0; i < self->size; ++i)
        if (self->hash[i].next != NULL) {
            struct HashNode *p = self->hash[i].next;
            self->hash[i].next = p->next;
            free(p);
        }
}

int main() {
    int a[6] = {1, 4, 5, 8, 2, 9};
    int *result;
    result = twoSum(a, 6, 19);

    if (result)
        for (int i = 0; i < 2; ++i) {
            printf("%d ", result[i]);
        }
    else
        printf("Not find!");

    return 0;
}