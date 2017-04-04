/*
 * a simple kernel module.
 */

#include <linux/module.h> 
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_2_init(void){
	printk(KERN_INFO "Hello World (3) \n");
	return 0;
}

static void __exit hello_2_exit(void){
	printk(KERN_INFO "Goodbye world (3) \n");
	return;
}

module_init(hello_2_init);
module_exit(hello_2_exit);

/* kernel documentation */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ronald Macmaster");
MODULE_DESCRIPTION("Simple test driver to learn kernel development...");
MODULE_SUPPORTED_DEVICE("test device");
