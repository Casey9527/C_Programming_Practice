/*  
 *   *  hello-1.c - The simplest kernel module.
 *    */
#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

#define PDEBUG(fmt,args...)	printk(KERN_INFO "hell-1: " fmt, args)

int init_module(void)
{
	printk(KERN_INFO "Hello world 1.\n");

	PDEBUG("you : %s are my %dth son.\n", "David", 5);
	/*
	 ** A non 0 return means init_module failed; module can't be loaded.
	 **/
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_EMERG "Goodbye world 1.\n");
}
