#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>

static int hello_init(void) {
	struct task_struct *my_parent;
	struct task_struct *init_task;
        struct list_head *plist;
        struct task_struct *child;
        int count = 0;

	printk(KERN_INFO "Hello from my kernel module!\n");
	// more experiemental code here
	// experimenting with the processes
        my_parent = current->parent;
	printk(KERN_INFO "hello: parent process = %s [%d]\n",
		my_parent->comm, my_parent->pid);
	printk(KERN_INFO "hello: current process = %s [%d]\n",
		current->comm, current->pid);

	// init task
        init_task = pid_task(find_vpid(1), PIDTYPE_PID);
	if (init_task != NULL) {
		printk(KERN_INFO "hello: init process = %s [%d]\n",
	                init_task->comm, init_task->pid);
                // let's print the first 10 children of pid1
                list_for_each(plist, &init_task->children) {
                        child = list_entry(plist, struct task_struct, sibling);
                        printk(KERN_INFO "hello: child(%d): %s [%d]\n",
                                count, child->comm, child->pid);
                        if (++count == 10)
                                break;
                }
        }
        
	return 0;
}

static void hello_exit(void) {
  printk(KERN_INFO "hello: Goodbye from my kernel module!\n");
  // clean up code if needed
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anthony Nandaa");
MODULE_DESCRIPTION("This is a simple hello-world module");


