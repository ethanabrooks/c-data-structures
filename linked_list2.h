#ifndef LINKED_LIST_H2
#define LINKED_LIST_H2
#include "tweets.h"
/* linked list node definition */

typedef struct struct_of_ints_struct {
    char* hashtag;
    int count;
    struct struct_of_ints_struct *prev ;
    struct struct_of_ints_struct *next ;
} counter ;


/* linked list helper function declarations */
counter* add    (counter* head_node, char* hashtag);
counter* add_to_top            (counter* head_node, char* name);
counter* delete_node           (counter* head_node, char* hashtag);
counter* delete_specific_node  (counter* head_node, counter* node_to_delete);
counter* search_list           (counter* head_node, char* hashtag);
counter* sort_list             (counter* head_node ) ;
counter* sort_list_rev         (counter* head_node ) ;
void     print_list            (counter* head_node ) ;
counter* delete_list           (counter* head_node ) ;
int      pmain                 ();
int      length                (counter* head);
counter* get_max (counter* node);
counter* copy    (counter* node);
#endif