#ifndef __NETWORKING_SOCKET_INCLUDED_H__
#define __NETWORKING_SOCKET_INCLUDED_H__

#include "function_attributes.h"
#include <stdint.h>

#ifdef _WIN32
#include <winsock2.h>
#else
#include <poll.h>
#endif

#ifndef MAX_SERVER_EVENTS
#define MAX_SERVER_EVENTS 32
#endif

#ifndef MAX_CLIENT_EVENTS
#define MAX_CLIENT_EVENTS 1024
#endif

struct event_sock {
	int fd;
	uint32_t ev;
};

struct event_batch {
	struct event_sock server[MAX_SERVER_EVENTS];
	struct event_sock client[MAX_CLIENT_EVENTS];
	int server_cnt;
	int client_cnt;
};

typedef int socket_t;

typedef enum { TCP_SOCKET, UDP_SOCKET, UNIX_SOCKET, RAW_SOCKET } socket_type_t;

extern socket_t socket_create(socket_type_t type);

extern int socket_listen_local(socket_t sd, const char *path, int backlog)
	__attr_nonnull_arg__(2);

extern int socket_listen_tcp(socket_t sd, const char *addr, unsigned short port,
			     int backlog) __attr_nonnull_arg__(2);

extern socket_t socket_accept(socket_t sd);

extern int socket_connect_tcp(socket_t sd, const char *addr,
			      unsigned short port) __attr_nonnull_arg__(2);

extern int socket_bind_connect_tcp(socket_t sd, const char *saddr,
				   unsigned short sport, const char *daddr,
				   unsigned short dport)
	__attr_nonnull_arg__(2, 4);

extern int socket_connect_local(socket_t sd, const char *path)
	__attr_nonnull_arg__(2);

extern int socket_events(struct pollfd *fds, int n, int timeout,
			 int server_sock, struct event_batch *batch)
	__attr_nonnull_arg__(1, 5);

#endif // __NETWORKING_SOCKET_INCLUDED_H__
