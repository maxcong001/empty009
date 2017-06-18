#pragma once
#include <zmq.hpp>
#include "zhelpers.hpp"
#include "zmsg.hpp"
#include <memory>
#include <functional>
/*
this file contains the util functions

*/
#define EPOLL_TIMEOUT 500
typedef std::shared_ptr<zmsg> zmsg_ptr;
typedef void USR_CB_FUNC(const char *, size_t, void *);
typedef void SERVER_CB_FUNC(const char *, size_t, void *);
typedef void MONITOR_CB_FUNC(int, int, std::string &);


//typedef void* MONITOR_CB_FUNC_CLIENT(int, int, std::string &);
typedef std::function<void(int, int, std::string &)> MONITOR_CB_FUNC_CLIENT;
/*
Supported events
ZMQ_EVENT_CONNECTED
The socket has successfully connected to a remote peer. The event value is the file descriptor (FD) of the underlying network socket. Warning: there is no guarantee that the FD is still valid by the time your code receives this event.
ZMQ_EVENT_CONNECT_DELAYED
A connect request on the socket is pending. The event value is unspecified.
ZMQ_EVENT_CONNECT_RETRIED
A connect request failed, and is now being retried. The event value is the reconnect interval in milliseconds. Note that the reconnect interval is recalculated at each retry.
ZMQ_EVENT_LISTENING
The socket was successfully bound to a network interface. The event value is the FD of the underlying network socket. Warning: there is no guarantee that the FD is still valid by the time your code receives this event.
ZMQ_EVENT_BIND_FAILED
The socket could not bind to a given interface. The event value is the errno generated by the system bind call.
ZMQ_EVENT_ACCEPTED
The socket has accepted a connection from a remote peer. The event value is the FD of the underlying network socket. Warning: there is no guarantee that the FD is still valid by the time your code receives this event.
ZMQ_EVENT_ACCEPT_FAILED
The socket has rejected a connection from a remote peer. The event value is the errno generated by the accept call.
ZMQ_EVENT_CLOSED
The socket was closed. The event value is the FD of the (now closed) network socket.
ZMQ_EVENT_CLOSE_FAILED
The socket close failed. The event value is the errno returned by the system call. Note that this event occurs only on IPC transports.
ZMQ_EVENT_DISCONNECTED
The socket was disconnected unexpectedly. The event value is the FD of the underlying network socket. Warning: this socket will be closed.
ZMQ_EVENT_MONITOR_STOPPED
Monitoring on this socket ended.
ZMQ_EVENT_HANDSHAKE_FAILED
The ZMTP security mechanism handshake failed. The event value is unspecified. NOTE: in DRAFT state, not yet available in stable releases.
ZMQ_EVENT_HANDSHAKE_SUCCEED

#define ZMQ_EVENT_CONNECTED         0x0001
#define ZMQ_EVENT_CONNECT_DELAYED   0x0002
#define ZMQ_EVENT_CONNECT_RETRIED   0x0004
#define ZMQ_EVENT_LISTENING         0x0008
#define ZMQ_EVENT_BIND_FAILED       0x0010
#define ZMQ_EVENT_ACCEPTED          0x0020
#define ZMQ_EVENT_ACCEPT_FAILED     0x0040
#define ZMQ_EVENT_CLOSED            0x0080
#define ZMQ_EVENT_CLOSE_FAILED      0x0100
#define ZMQ_EVENT_DISCONNECTED      0x0200
#define ZMQ_EVENT_MONITOR_STOPPED   0x0400
#define ZMQ_EVENT_ALL               0xFFFF
*/
int get_monitor_event(void *monitor, int *value, std::string &address);

// utill function