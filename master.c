/*
     Copyright (C) 2002 Chuanhua Han
  
      This program is free software; you can redistribute it and/or modify
      it under the terms of the GNU General Public License as published by
      the Free Software Foundation; either version 2 of the License, or
      (at your option) any later version.
  
      This program is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
      GNU General Public License for more details.
  
      You should have received a copy of the GNU General Public License
      along with this program; if not, write to the Free Software
      Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kernel.h>



/*
static int num =100;
module_param(num, int, 0666);
MODULE_PARM_DESC(num,"A integer val pram")
*/

static BLOCKING_NOTIFIER_HEAD(my_noti_list);



#define MASTER_STAT_INSTALL 0 


static int __init masetr_init(void)
{
	


	printk("###%s %d###\n",__func__,__LINE__);

/*	
	printk("###%s %d  send notify  before..........###\n",__func__,__LINE__);

	msleep_interruptible(2000);//sleep 2ms

	blocking_notifier_call_chain(my_noti_list, MASTER_STAT_INSTALL, &num);


	printk("###%s %d  send notify  after..........###\n",__func__,__LINE__);
*/

	return 0;
}

static void __exit master_exit(void)
{

	printk("###%s %d###\n",__func__,__LINE__);
}

//register notifier chain
int register_my_notify(struct notifier_block* nb)
{
	return blocking_notifier_chain_register(&my_noti_list, nb);
}
EXPORT_SYMBOL(register_my_notify);


//unregister notifier chain
int unregister_my_notify(struct notifier_block* nb)
{
	return blocking_notifier_chain_unregister(&my_noti_list, nb);
}
EXPORT_SYMBOL(unregister_my_notify);

//send notifier
int test_notifier_chain(unsigned long val,void *v)
{
	return blocking_notifier_call_chain(&my_noti_list, val, v);
}
EXPORT_SYMBOL(test_notifier_chain);

module_init(masetr_init);
module_exit(master_exit);
MODULE_AUTHOR("Chuanhua Han <hanchuanhua@fishsemi.com>");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a module interface that descript my notifier");
MODULE_ALIAS("my notifier interface");
MODULE_VERSION("v1.0");

