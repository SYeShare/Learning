/*****************************************************************************
   模块名      : kdv net address 
   文件名      : kdvnetaddr.h
   相关文件    : 
   文件实现功能: 和网络地址有关的底层定义，仅用于kdv平台
   作者        : 曾昭鸣
   版本        : V1.1  Copyright(C) 2020 Kedacom, All rights reserved.
-----------------------------------------------------------------------------
   修改记录:
   日  期      版本        修改人      修改内容
   2020/02/18  1.0         曾昭鸣      新增 
   2017/07/27  1.1         曾昭鸣      kdv_netaddr 修改为struct
******************************************************************************/
#ifndef _KDV_NETADDR_
#define _KDV_NETADDR_

#ifdef _MSC_VER
#include <Winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif

#define KDV_MAX_IPADDR_STR_LEN	48
//buffer used to convert to string
//static _thread char tmpAddrBuf[KDV_MAX_IPADDR_STR_LEN];

#define _KDV_NETADDR_V4_ONLY_	1

#ifdef _KDV_NETADDR_V4_ONLY_
typedef unsigned int  kdv_netaddr;

#define KDV_NET_ANYADDR 	"0.0.0.0"
static const kdv_netaddr kdv_net_anyaddr = 0;

#define str2netaddr(str, strlen, paddr)	{	\
	if (!(strlen) || !(str))	\
		*paddr = kdv_net_anyaddr;					\
	else							\
		*paddr = inet_addr(str);	\
}

#ifdef _MSC_VER
static inline char* netaddr2str(kdv_netaddr *paddr)
{
	struct in_addr in;
	in.s_addr = *paddr;
	return inet_ntoa(in);
}

#else
#define netaddr2str(paddr)	({	\
	struct in_addr in;	\
	in.s_addr = *(paddr);	\
	inet_ntoa(in);		\
})
#endif

//addr (kdv_netaddr), sa(struct sockaddr_storage*)
#define netaddr2inet(paddr, sa)	{	\
	struct sockaddr_in *ia = (struct sockaddr_in*)(sa);	\
	(ia)->sin_family = AF_INET;		\
	if (*(paddr) == kdv_net_anyaddr) {	\
		(ia)->sin_addr.s_addr = INADDR_ANY;	\
	} else {						\
		(ia)->sin_addr.s_addr = *(paddr);	\
	}								\
}

#else
typedef struct {
	char addr[KDV_MAX_IPADDR_STR_LEN];
} kdv_netaddr;

#define KDV_NET_ANYADDR		"::"
#define KDV_NET_ANYADDR_LEN	2
static const char *const kdv_net_anyaddr_ =  KDV_NET_ANYADDR;
static const kdv_netaddr kdv_net_anyaddr = {.addr = KDV_NET_ANYADDR};

#define str2netaddr(kdvstr, kdvstr_len, paddr) { 	\
	if (!(kdvstr) || !(kdvstr_len)) {	\
		*paddr = kdv_net_anyaddr;		\
	} else {								\
		int netaddr_len__ = (kdvstr_len) < (KDV_MAX_IPADDR_STR_LEN - 1)  ? kdvstr_len : (KDV_MAX_IPADDR_STR_LEN - 1);	\
		memcpy(&((paddr)->addr[0]), kdvstr, netaddr_len__);	\
		(paddr)->addr[netaddr_len__] = '\0';		\
	}	\
}

#define netaddr2str(paddr)	((char*)&((paddr)->addr[0]))

//kdvnetaddr convert to os sockaddr_in*;
//addr(kdv_netaddr), sa(struct sockaddr_storage*)
//if sa->ss_family = AF_UNSPEC, addr format not support.
#define netaddr2inet(paddr, sa)	{	\
    struct sockaddr_in *ia = (struct sockaddr_in *)(sa);	\
    struct sockaddr_in6 *ia6 = (struct sockaddr_in6 *)(sa);	\
    ia->sin_family = AF_UNSPEC;			\
	if (!strncmp(&((paddr)->addr[0]), kdv_net_anyaddr_, KDV_NET_ANYADDR_LEN)) {	\
		ia6->sin6_family = AF_INET6;	\
		ia6->sin6_addr = in6addr_any;	\
	} else if (inet_pton(AF_INET, (char*)&(paddr)->addr[0], &(ia->sin_addr))) {	\
        ia->sin_family = AF_INET;		\
    } else if (inet_pton(AF_INET6, (char*)&(paddr)->addr[0], &(ia6->sin6_addr))) {	\
        ia6->sin6_family = AF_INET6;	\
    }	\
}

#endif	//endof _KDV_NETADDR_V4_ONLY_

#endif //endof _KDV_NETADDR_
