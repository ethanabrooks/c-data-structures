#ifndef HASH_TABLE_H2
#define HASH_TABLE_H2

#include "linked_list2.h"
#include "tweets.h"

/* hash table structure and helper function declarations */

typedef struct hash_table_struct {

	int num_of_buckets ;		/* size of hash table     */
	counter **table ;	/* array of head pointers */

} hash_table ;


/* Hash Table helper function declarations */
hash_table* 	create_hash_table (hash_table* table, int num_of_buckets) ;
hash_table* 	double_table_size (hash_table* table, int num_of_buckets) ;
counter*	    find			  (hash_table* table, char* hashtag);
unsigned int   	map               (hash_table* table, char* name);
int            	delete_from_table (hash_table* table, char* name) ;
int            	add_to_table      (hash_table* table, char* name);
void           	print_table       (hash_table* table) ;
void           	delete_table      (hash_table* table) ;
counter*        extract_max       (hash_table* table);

#endif
