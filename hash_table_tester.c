#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
  hash_table *htable = create_hash_table(4);
  print_table(htable);
  puts("\nshould be abc");
  add_to_table(htable, "abc");
  print_table(htable);
  add_to_table(htable, "test2");
  add_to_table(htable, "test2");
  puts("\nshould be abc, test2");
  print_table(htable);
  linked_list* list = to_linked_list(htable);
  puts("\nshould be abc, test2");
  print_list(list);
  delete_list(&list);
  delete_table(htable);
  puts("\nshould be nothing");
  /*print_table(htable);*/
}

