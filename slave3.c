#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kernel.h>


typedef struct stuff_disc {
          int num;
          char *name;
}stuff_disc_t; 


static struct notifier_block my_nb;
extern int register_my_notify(struct notifier_block* nb);
extern int unregister_my_notify(struct notifier_block* nb);

static int slave3_notifier_fn(struct notifier_block *nb, unsigned long action, void *data)
{
	stuff_disc_t *stuff_dev =(stuff_disc_t *)data;	

	printk("###%s %d  action=%ld stuff_dev->name=%s, stuff_dev->num=%d###\n",__func__,__LINE__,action, stuff_dev->name, stuff_dev->num);
	return 0;
}


static int __init slave3_init(void)
{
	int ret;
	printk("###%s %d###\n",__func__,__LINE__);

	my_nb.notifier_call = slave3_notifier_fn;
	my_nb.priority =20;

		
	ret = register_my_notify(&my_nb);
	if(ret){
		printk("register_my_notify err\n");
		return -1;
	}

	return 0;
}

static void __exit slave3_exit(void)
{

	printk("###%s %d###\n",__func__,__LINE__);
	unregister_my_notify(&my_nb);
}

module_init(slave3_init);
module_exit(slave3_exit);
MODULE_LICENSE("GPL");
