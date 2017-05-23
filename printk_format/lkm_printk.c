#include <linux/module.h>
#include <linux/if_ether.h>
#include <linux/in.h>

static int __init example_printk_init(void)
{
	u8 raw_buf[10];
	u8 mac_addr[ETH_ALEN] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06};
	struct in_addr ip_addr;
	struct in6_addr ip6_addr;
	struct sockaddr_in ip4_addr_port;

	/* primitive types */
	printk("int : %d, %x\n", 10, 10);
	printk("unsigned int : %u, %x\n", 10, 10);
	printk("long : %ld, %lx\n", 10L, 10L);
	printk("unsigned long : %lu, %lx\n", 10L, 10L);
	printk("long long : %lld, %llx\n", 10LL, 10LL);
	printk("unsigned long long : %llu, %llx\n", 10LL, 10LL);

	/* pointer */
	printk("pointer : %p\n", example_printk_init);

	/* symbol */
	printk("symbol : %pF\n", example_printk_init);

	/* hexdump */
	memset(raw_buf, 0x01, sizeof(raw_buf));
	printk("hexdump1 : %*phC\n", 10, raw_buf);
	printk("hexdump2 : %10phC\n", raw_buf);

	/* MAC address */
	printk("mac address : %pM\n", mac_addr);

	/* IPv4 address */
	printk("ipv4 address : %pI4\n", &ip_addr);

	/* IPv6 address */
	printk("ipv4 address : %pI6\n", &ip6_addr);

	/* IPv4 address with port */
	ip4_addr_port.sin_family = AF_INET;
	printk("ipv4 address w/ port : %pISpc\n", &ip4_addr_port);

	return 0;
}

static void __exit example_printk_fini(void)
{
	printk("good bye~\n");
}

module_init(example_printk_init);
module_exit(example_printk_fini);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("guruseed <guruseed@tistory.com>");
MODULE_DESCRIPTION("Examples of printk.");
