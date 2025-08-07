#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    ListNode *next;
    char *value;
} ListNode;

ListNode* create_node(const char* value){
    ListNode *list_node = malloc(sizeof(ListNode));
    list_node->next = NULL;
    list_node->value = value;
    return list_node;
}

ListNode* add_start(ListNode* head, char* value){
    ListNode* new_head = (value);
    new_head->next = head;
    return new_head;
}

//TODO: if Node is NULL it will not work
void add_end(ListNode* node, char* value){
    assert(node != NULL);
    if (node->next == NULL){
        ListNode* new_node = create_node(value);
        node->next = new_node;
        return;
    } else {
        add_end(node->next, value);
    }
}


//searching
    //by_name
ListNode* search_by_value(ListNode* node, char* value){
    if (node == NULL){
        return NULL;
    }
    if(strcmp(node->value, value) == 0){
        return node;
    } else {
        return search_by_value(node->next, value);
    }
}

//deleting
    //by_value
    //by_position
ListNode* delete_node(ListNode* node, ListNode* previous_node, char* value){
    if (strcmp(node->value, value) == 0){

        if(previous_node != NULL){
            ListNode* next = node->next;
            free(node->value);
            free(node);
            previous_node->next = next;
            return previous_node;
        } else {
            ListNode* next = node->next;
            free(node->value);
            free(node);
            return next;
        }
    } else if (node->next != NULL){
        delete_node(node->next, node, value);
        return node;
    } else {
        return node;
    }
}

//print whole List

