#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/workqueue.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("deepskyblue86");

/*
 * Declare the delayed work
 */
static struct delayed_work hello_work;
static void hello_routine(struct work_struct *work);
static DECLARE_DELAYED_WORK(hello_work, hello_routine);

static int g_shutdown = 0;
static struct workqueue_struct *hello_workqueue;

static void hello_routine(struct work_struct *work)
{
	pr_warn_ratelimited("Supposedly annoying message\n");

	if (g_shutdown == 0) {
		queue_delayed_work(hello_workqueue, &hello_work, 50);
	}
}

static int hello_init(void)
{
	hello_workqueue = create_workqueue("hello_workqueue");
	queue_delayed_work(hello_workqueue, &hello_work, 0);

	pr_info("Hello world!\n");

	return 0;
}

static void hello_exit(void)
{
	pr_info("Goodbye cruel world\n");

	g_shutdown = 1;
	cancel_delayed_work(&hello_work);
	flush_workqueue(hello_workqueue);
	destroy_workqueue(hello_workqueue);
}

module_init(hello_init);
module_exit(hello_exit);
