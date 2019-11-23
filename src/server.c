#include "server.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <resolv.h>
#include <errno.h>

#define LISTEN_BACKLOG 50

int run_server(int port) {
  int sfd, cfd;
  struct sockaddr_in my_addr, peer_addr;
  socklen_t peer_addr_size;
	char buffer[1024];

  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sfd == -1)
    exit(EXIT_FAILURE);

  memset(&my_addr, 0, sizeof(struct sockaddr_in));
  my_addr.sin_family = AF_INET;
  my_addr.sin_port = htons(port);
  my_addr.sin_addr.s_addr = INADDR_ANY;


  if(bind(sfd, (struct sockaddr *) &my_addr,
                sizeof(struct sockaddr_in)) == -1)
    exit(EXIT_FAILURE);

  if(listen(sfd, LISTEN_BACKLOG) == -1)
    exit(EXIT_FAILURE);

  while (1) {
    peer_addr_size = sizeof(struct sockaddr_in);
    cfd = accept(sfd, (struct sockaddr *) &peer_addr,
                  &peer_addr_size);

    if(cfd == -1)
      exit(EXIT_FAILURE);
  
		send(cfd, buffer, recv(cfd, buffer, 1024, 0), 0);

    close(cfd);
  }
  close(sfd);
  
}
