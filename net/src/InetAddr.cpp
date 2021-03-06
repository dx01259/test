/*
 * InetAddr.cpp
 *
 *  Created on: 2015年9月4日
 *      Author: dengxu
 */

#include"InetAddr.h"
#include<string.h>
#include<netdb.h>
#include<sys/socket.h>

namespace lynetx {

namespace net {

CInetAddr::CInetAddr(u_short usPort, const char *addr) {
	// TODO Auto-generated constructor stub
	m_socktype = -1;
	memset(&m_addr, 0, sizeof(m_addr));
	struct hostent *hp;
	if((hp = gethostbyname(addr)))
	{
		m_addr.sin_family = AF_INET;
		m_addr.sin_addr = *(struct in_addr *)hp->h_addr_list[0];
		m_addr.sin_port = usPort;
	}
}

CInetAddr::CInetAddr(const sockaddr_in &addr)
{
	this->m_socktype = -1;
	this->m_addr = addr;
}

CInetAddr::~CInetAddr() {
	// TODO Auto-generated destructor stub
}

void CInetAddr::SetSockType(const int socktype)
{
	this->m_socktype = socktype;
}

int  CInetAddr::GetSockType() const
{
	return this->m_socktype;
}

void CInetAddr::GetInetAddr(sockaddr_in &addr)
{
	addr = this->m_addr;
}

} /* namespace net */

} /* namespace lynetx */
