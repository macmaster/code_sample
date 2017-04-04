/*
 * a simple kernel module.
 */

#include <linux/module.h> 
#include <linux/kernel.h>

int init_module(){
	printk(KERN_INFO "Hello World (1) \n");
	return 0;
}

void cleanup_module(){
	printk(KERN_INFO "Goodbye world (1) \n");
	return;
}
