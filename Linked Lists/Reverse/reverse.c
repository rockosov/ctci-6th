#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 * Implement reversing of single linked list.
 */

/**
 * Time Complexity:
 * Space Complexity:
 */

typedef unsigned long long uint64;

typedef struct list_node {
    struct list_node* next;
    uint64 data;
} list_node_t;

void print_list(list_node_t* head) {
    printf("HEAD -> ");
    while (head != NULL) {
        printf("%lld -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

list_node_t* create_list_from_array(uint64* array, size_t array_size) {
    size_t i = 0;
    list_node_t* node = NULL;
    list_node_t* prev = NULL;

    i = array_size;
    while (i != 0) {
        node = malloc(sizeof(list_node_t));
        node->next = prev;
        node->data = array[i - 1];
        prev = node;
        i--;
    }

    return node;
}

void free_list(list_node_t* head) {
    list_node_t* temp = NULL;

    while (head != NULL) {
        temp = head->next;
        free(head);
        head = temp;
    }

    return;
}

void swap_xor(uint64* a, uint64* b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

list_node_t* reverse_list(list_node_t* head) {
    list_node_t* prev = NULL;

    while (head != NULL) {
        swap_xor((uint64*)&head->next, (uint64*)&prev);
        swap_xor((uint64*)&head, (uint64*)&prev);
    }

    return prev;
}

int main(int argc, char** argv) {
    uint64 array[] = {1, 2, 3, 4, 5, 6};
    list_node_t* head = create_list_from_array(array, sizeof(array) / sizeof(*array));

    print_list(head);

    head = reverse_list(head);

    print_list(head);

    free_list(head);

    return 0;
}

