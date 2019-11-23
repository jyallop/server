#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"
#include "sys/types.h"
#include "sys/socket.h"

int main(int argc, char **argv) {
  char *message;
  
  if(argc > 1) {
    message = (char *) malloc(strlen(argv[1]) * sizeof(char));
    memcpy(message, argv[1], (sizeof(char) * strlen(argv[1])));
  } else {
    message = (char *) malloc(8 * sizeof(char));
    strncpy(message, "radical\0", 8 * sizeof(char));
  }

  char val = 'a';
  list *llist = create_list(&val, sizeof(char));

  val = 'b';
  add_item(llist, &val, sizeof(char));

  val = 'c';
  add_item(llist, &val, sizeof(char));

  printf("list length: %d\n", get_length(llist));

  char *get_val = (char *) get(llist, 1);

  printf("val at pos: 1 = %c\n", *get_val);

  printf("%s\n", message);

  run_server(8080);

  //getAddrInfo has example
  //need to connect (man) (also bind for server)
  //need to read (or recv) (also look up accept)
  //need to write (or send)
  //need to close

  printf("Freeing message\n");
  free(message);

  free_list(llist);

  return 0;
}
