#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ctype.h>

#define SIZE 512
#define BUF_SIZE 128
#define INVALID_CMD "Invalid command. Try again!"
#define SEND_ERR "There was an error sending information from the server. Try again!"
#define RECV_ERR "There was an error receiving information from the server. Try again!"
#define INFO_ERR "There was an error collecting information from the server. Try again!"

/* -------------------- client_main -------------------- */
int is_alphanumerical(char* s, int flag);
int is_correct_arg_size(char* arg, int size);
int has_correct_arg_sizes(char* arg1, int size1, char* arg2, int size2);
int digits_only(char *s);
void parse(int fd, char* command, char* uid, char* password);
int main(int argc, char* argv[]);

/* -------------------- client_udp -------------------- */
int send_and_receive(int fd, struct addrinfo *res, char* message, char* buffer, int size);
void reg(char* IP_ADDRESS, char* UID, char* password, struct addrinfo *res, int fd);
void unreg(char* IP_ADDRESS, char* UID, char* password, struct addrinfo *res, int fd);
int login(char* IP_ADDRESS, char* UID, char* password, struct addrinfo *res, int fd);
int logout(char* IP_ADDRESS, char* UID, char* password, struct addrinfo *res, int fd);
void groups(char* IP_ADDRESS, struct addrinfo *res, int fd);

/* -------------------- client_tcp -------------------- */

#endif