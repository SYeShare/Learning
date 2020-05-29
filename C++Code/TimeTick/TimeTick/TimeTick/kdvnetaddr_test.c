#include <stdio.h>
#include <string.h>
#include "kdvnetaddr.h"

static const char *ips[] = {"10.1.1.1", "127.0.0.1", "254.255.255.255", "300.1.1.1",
					"::1", "fe80::e658:2589:a97:139a", ":::172"};
	
static int test_str2addr()
{
	for (int i = 0; i < sizeof(ips) / sizeof(ips[0]); i++) {
		kdv_netaddr addr;
		int len;
		if (ips[i] == NULL || ((len = strlen(ips[i])) == 0)) {
			printf("ip %s format error\n", ips[i]);
			continue;
		}

		str2netaddr(ips[i], len, &addr);

		char *buf;

		buf = netaddr2str(addr);
		if (!buf || strncmp(buf, ips[i], len))
			printf("ip addr %s test failed, result %s\n", ips[i], buf);
		else
			printf("ip addr %s test pass, result %s\n", ips[i], buf);
	}

	return 0;
}

static int test_addr2str()
{
	return 0;
}

static int test_addr2inet()
{
	for (int i = 0; i < sizeof(ips) / sizeof(ips[0]); i++) {
		kdv_netaddr addr;
		int len;
		if (ips[i] == NULL || ((len = strlen(ips[i])) == 0)) {
			printf("ip %s format error\n", ips[i]);
			continue;
		}

		str2netaddr(ips[i], len, &addr);

		struct sockaddr_storage sa;
		netaddr2inet(addr, &sa);

		if (sa.ss_family == AF_UNSPEC)
			printf("ip addr %s test failed\n", ips[i]);
		else
			printf("ip addr %s test pass, result %s address\n", ips[i], sa.ss_family == AF_INET? "IPv4": "IPv6");
	}

	return 0;
}

int main(int argc, char *argv[])
{
	test_str2addr();
	test_addr2str();
	test_addr2inet();
	return 0;
}
