#include <linux/module.h> 
#include <linux/kernel.h>    
#include <linux/init.h>      
#include <linux/moduleparam.h> 
#include <linux/timer.h>

#define TIMER_INTERVAL (500)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ravi");
MODULE_DESCRIPTION("Timer Module for Problem 4");

static int	count = -1;
static char	*name = "John Doe";

module_param(count,int,S_IRUGO);
module_param(name,charp,S_IRUGO);

static struct timer_list timer;

void timer_callback(struct timer_list *d){
	int ret;
	count++;
	//printing info
	printk(KERN_INFO "Name:%s Timer Count: %i\n",name,count);
	//reprime the timer
	ret = mod_timer(&timer,jiffies+msecs_to_jiffies(TIMER_INTERVAL) );
	if(ret) printk(KERN_INFO "Error reinitializing the timer\n");        
}

static int __init timer_init(void)
{
	int ret;
        printk(KERN_INFO "Starting Timer kernel Module\n");
	timer_setup(&timer,&timer_callback,0);    
	ret =mod_timer(&timer,jiffies+msecs_to_jiffies(TIMER_INTERVAL) );
	if(ret) printk(KERN_INFO "Error initializing the timer\n");        
	return 0;    
}

static void __exit timer_cleanup(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
	del_timer(&timer);
}

module_init(timer_init);
module_exit(timer_cleanup);


