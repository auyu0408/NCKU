#include "my_info.h"

#define PROC_NAME "my_info"//procfilename 

/*
my_info_show()
Sequence show operation
Print version when we inside first time
Print cpu information each time until printed all

argument:
m- Sequence file we read from kernel
v- Information from start function, origin: &cpu_data()

variable:
c- change v's type into x86's cpuinfo

return: 0
*/
static int my_info_show(struct seq_file *m, void *v)
{
    //CPU variable
    struct cpuinfo_x86* c = v;

    if(c->cpu_index == 0)
        version_show(m);
    cpu_show(m, c);
    return 0;
}

/*
my_info_start()
Sequence start operation, change cpu_data according *pos

argument:
m- Sequence file we read from kernel
pos- pointed to the cpu we will print the next

variable:
nr_cpu_ids- total process we have

return:
NULL- All processor printed, then go to Stop operation
&cpu_data(*pos)- CPU data we havn't print
*/
static void *my_info_start(struct seq_file *m, loff_t *pos)
{
    *pos = cpumask_next(*pos - 1, cpu_online_mask);
    if ((*pos) < nr_cpu_ids)
        return &cpu_data(*pos);
    return NULL;
}

/*
my_info_show()
Sequence next operation
Change pos

argument:
m- Sequence file we read from kernel
pos- pointed to processor we print now

return:
my_info_start(m, pos)
*/
static void *my_info_next(struct seq_file *m, void *v, loff_t *pos)
{
    (*pos)++;
    return my_info_start(m, pos);
}

/*
my_info_stop()
Sequence stop operation
Print Memory and time information then exit

argument:
m- Sequence file we read

return: no
*/
static void my_info_stop(struct seq_file *m, void *v)
{
    other_show(m);
}

// This structure gather "function" to manage the sequence
const struct seq_operations my_info_ops =
{
    .start = my_info_start,
    .next = my_info_next,
    .stop = my_info_stop,
    .show = my_info_show,
};

// This function called when the /proc file is open.
static int procfile_open(struct inode *inode, struct file *file)
{
    return seq_open(file, &my_info_ops);
}

//This structure is procfile operation
static const struct file_operations my_file_ops =
{
    .open = procfile_open,
    .read = seq_read,
    .llseek = seq_lseek,
    .release = seq_release,
};

//Init module
static int __init my_info_init(void)
{
    struct proc_dir_entry *entry;
    entry = proc_create(PROC_NAME, 0644, NULL, &my_file_ops);
    if (entry == NULL)
    {
        remove_proc_entry(PROC_NAME, NULL);
        pr_debug("Error: Could not build /proc/%s.\n", PROC_NAME);
        return -ENOMEM;
    }
    return 0;
}

//Exit module
static void __exit my_info_exit(void)
{
    remove_proc_entry(PROC_NAME, NULL);
    printk("/proc/%s removed\n", PROC_NAME);
}

module_init(my_info_init);
module_exit(my_info_exit);

//Module license declaration
MODULE_LICENSE("GPL");