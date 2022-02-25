#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("deepskyblue86");

static int hello_init(void)
{
	pr_info("Hello world!\n");
	return 0;
}

static void hello_exit(void)
{
	pr_info("Goodbye cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
