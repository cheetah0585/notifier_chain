#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kernel.h>

#define TYPE_BOOK 0
#define TYPE_CAT  1
#define TYPE_PHONE 2

static int num=100;
module_param(num, int, 0444);
MODULE_PARM_DESC(num, "this is the number of books");

static char *name="linux kernel";
module_param(name, charp, 0444);
MODULE_PARM_DESC(name, "this is a the name of book");

typedef struct stuff_disc {
	int num;
	char *name;
}stuff_disc_t; 


stuff_disc_t stuff_dev;

extern int test_notifier_chain(unsigned long val,void *v); 


static int __init send_noti_init(void)
{
	
	printk("###%s %d###\n",__func__,__LINE__);
		
	stuff_dev.num = num;
	stuff_dev.name = name;

	test_notifier_chain(TYPE_BOOK, &stuff_dev);

	return 0;
}

static void __exit send_noti_exit(void)
{

	printk("###%s %d###\n",__func__,__LINE__);
}

module_init(send_noti_init);
module_exit(send_noti_exit);
MODULE_LICENSE("GPL");
