// main file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // for close
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../inc/sock_util.h"

#define PORT 7890

int main(int argc, char **argv) {
	int sockfd, new_sockfd;  // listen on sockfd, new connection on new_sockfd
	struct sockaddr_in host_addr, client_addr;  // address information
	socklen_t sin_size;
	int recv_length = 1, yes = 1;
	unsigned char buffer[1024];

	// make connection(set up socket)
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		fatal("in socket");

	// set options
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1)
		// SO_REUSEADDR will allow us to reuse the a given address for binding
		fatal("setting socket option SO_REUSEADDR");

	host_addr.sin_family = AF_INET;
	// since 0 is '0' in both network order(big-endian) and host order(little-endian mostly), so no conversion
	host_addr.sin_addr.s_addr = 0;
	host_addr.sin_port = htons(PORT);
	memset(&(host_addr.sin_zero), '\0', 8);  // zero the rest of the struct(it's just padding)

	if (bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr)) == -1)
		// conversion of host_addr is done to "struct sockaddr" from "struct sockaddr_in"
		fatal("binding the socket");

	// listen incoming connections and queues connection upto size of 'backlog_queue_size'
	if (listen(sockfd, 5) == -1)
		fatal("listening on socket");

	while (1) {  // loop to accept connecitons
		sin_size = sizeof(struct sockaddr_in);
		new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
		if (new_sockfd == -1)
			fatal("accepting connection");
		printf("server: got connection from %s port %d\n",
				inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		char send_buffer[1024];
		strcpy(send_buffer, "Hello Client ");
		strncat(send_buffer, inet_ntoa(client_addr.sin_addr), 32);
		strncat(send_buffer, ": ", 2);
		char client_addr_port[6];
		// itoa is no longer supported(I think, so sprintf/snprintf are the option)
		if (sprintf(client_addr_port, "%d", ntohs(client_addr.sin_port)) == -1)
			fatal("Port conversion failed");
		strncat(send_buffer, client_addr_port, strlen(client_addr_port));
		strncat(send_buffer, "\r\n", 2);
		send(new_sockfd, send_buffer, strlen(send_buffer), 0);  // send the message to connected client(accepted connection)

		recv_length = recv(new_sockfd, (void *)&buffer, 1024, 0);  // recieve message
		while (recv_length > 0) {
			printf("RECV: %d bytes\n", recv_length);
			dump(buffer, recv_length);
			recv_length = recv(new_sockfd, (void *)&buffer, 1024, 0);
		}
		close(new_sockfd);
	}
	return 0;
}