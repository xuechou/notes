#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

// module desctiption infomation
MODULE_DESCRIPTION("My kernel module");
MODULE_AUTHOR("Me");
MODULE_LICENSE("GPL");

// entry point function must be like this : int func(void)
static int dummy_init(void)
{
        printk(KERN_ALERT "Hi\n");
        return 0; // succeed
}


// exit point function must be like this : void func(void)
static void dummy_exit(void)
{
        printk(KERN_ALERT "Bye\n");
        pr_debug("Bye\n");
}

module_init(dummy_init);        // module entry point
module_exit(dummy_exit);        // moudle exit point
