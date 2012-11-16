/*
 * FILE:    net_udp.h
 * AUTHORS: Colin Perkins
 * 
 * Copyright (c) 1998-2000 University College London
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, is permitted provided that the following conditions 
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the names of the copyright holders nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS
 * IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _NET_UDP
#define _NET_UDP

typedef struct _socket_udp socket_udp; 

#if defined(__cplusplus)
extern "C" {
#endif

int         udp_addr_valid(const char *addr);
socket_udp *udp_init(const char *addr, uint16_t rx_port, uint16_t tx_port, int ttl);
socket_udp *udp_init_if(const char *addr, const char *iface, uint16_t rx_port, uint16_t tx_port, int ttl);
void        udp_exit(socket_udp *s);

int         udp_recv(socket_udp *s, char *buffer, int buflen);
int         udp_send(socket_udp *s, char *buffer, int buflen);
#ifndef WIN32
int	    udp_sendv(socket_udp *s, struct iovec *vector, int count);
#endif

uint32_t    udp_socket_addr4(socket_udp *s);
uint16_t    udp_socket_txport(socket_udp *s);
int         udp_socket_ttl(socket_udp *s);

const char *udp_host_addr(socket_udp *s);
int         udp_fd(socket_udp *s);

int         udp_select( fd_set *readset, int max_fd, struct timeval *timeout);
void        udp_fd_zero( fd_set *readset, int *max_fd );
void        udp_fd_set( fd_set *readset, int *max_fd, socket_udp *s);
int         udp_fd_isset( fd_set *readset, int *max_fd, socket_udp *s);

#if defined(__cplusplus)
}
#endif

#endif

