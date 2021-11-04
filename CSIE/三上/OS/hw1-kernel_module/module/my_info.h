//public
#include<linux/fs.h>
#include<linux/module.h>
#include<linux/proc_fs.h>
#include<linux/seq_file.h>
//version
#include<generated/utsrelease.h>
//memory
#include <linux/mm.h>
#include <linux/mmzone.h>
#include <linux/vmstat.h>
//time
#include<linux/time.h>
#include<linux/kernel_stat.h>

/*
version_show()
Put Version information into file

argument:
m- Sequence file we read
variable:
UTS_RELEASE- kernel version

return: no
*/
static void version_show(struct seq_file *m)
{
    //put version information into sequence input
    seq_puts(m, "\n=============Version=============\n");
    seq_printf(m, "Linux version %s\n", UTS_RELEASE);
    seq_puts(m, "\n=============CPU=============\n");
}

/*
cpu_show()
Put cpu information into file

argument:
m- Sequence file we read
cpuinfo_x86- Information about processor, get from &cpu_data()

return: no
*/
static void cpu_show(struct seq_file *m, struct cpuinfo_x86 *c)
{
    seq_printf(m, "processor\t\t: %u\n"
               "model name\t\t: %s\n"
               "physical id\t\t: %d\n"
               "core id\t\t\t: %d\n"
               "cpu cores\t\t: %d\n"
               "cache size\t\t: %u KB\n"
               "clflush size\t: %u\n"
               "cache_alignment\t\t: %d\n"
               "address sizes\t\t: %u bits physical, %u bits virtual\n\n"
               , c->cpu_index, c->x86_model_id[0] ? c->x86_model_id : "unknown", c->phys_proc_id
               , c->cpu_core_id, c->booted_cores, c->x86_cache_size, c->x86_clflush_size
               , c->x86_cache_alignment, c->x86_phys_bits, c->x86_virt_bits);
}

//define memory and time show
/*
other_show()
Put memory and time information into file
Memory show in kB

argument:
m- Sequence file we read
variable:
my_sys- System infomation
pages[]- Other memory information
uptime- System Uptime
idle- System Idletime
nesc, rem, i- Variable help us get Idle time

return: no
*/
static void other_show(struct seq_file *m)
{
    //Memory variable
    struct sysinfo my_sys;
    unsigned long pages[NR_LRU_LISTS];
    int lru;//count
    //Time variable
    struct timespec64 uptime;
    struct timespec64 idle;
    u64 nsec;
    u32 rem;
    int i;
    //Get my_sys
    si_meminfo(&my_sys);
    //Get other memory
    for (lru = LRU_BASE; lru < NR_LRU_LISTS; lru++)
        pages[lru] = global_node_page_state(NR_LRU_BASE + lru);
    //Get Uptime Idletime
    nsec = 0;
    for_each_possible_cpu(i)
    nsec += (__force u64) kcpustat_cpu(i).cpustat[CPUTIME_IDLE];
    get_monotonic_boottime(&uptime);
    idle.tv_sec = div_u64_rem(nsec, NSEC_PER_SEC, &rem);
    idle.tv_nsec = rem;

    seq_puts(m, "\n=============Memory=============\n");
    seq_printf(m, "MemTotal\t\t: %8lu kB\n", my_sys.totalram << (PAGE_SHIFT - 10));
    seq_printf(m, "MemFree\t\t\t: %8lu kB\n", my_sys.freeram << (PAGE_SHIFT - 10));
    seq_printf(m, "Buffers\t\t\t: %8lu kB\n", my_sys.bufferram << (PAGE_SHIFT - 10));
    seq_printf(m, "Active\t\t\t: %8lu kB\n", (pages[LRU_ACTIVE_ANON] + pages[LRU_ACTIVE_FILE])<< (PAGE_SHIFT - 10));
    seq_printf(m, "Inactive\t\t: %8lu kB\n", (pages[LRU_INACTIVE_ANON] + pages[LRU_INACTIVE_FILE]) << (PAGE_SHIFT - 10));
    seq_printf(m, "Shmem\t\t\t: %8lu kB\n", my_sys.sharedram << (PAGE_SHIFT - 10));
    seq_printf(m, "Dirty\t\t\t: %8lu kB\n", global_node_page_state(NR_FILE_DIRTY) << (PAGE_SHIFT - 10));
    seq_printf(m, "Writeback\t\t: %8lu kB\n", global_node_page_state(NR_WRITEBACK) << (PAGE_SHIFT - 10));
    seq_printf(m, "KernelStack\t\t: %8lu kB\n", global_zone_page_state(NR_KERNEL_STACK_KB));
    seq_printf(m, "PageTables\t\t: %8lu kB\n", global_zone_page_state(NR_PAGETABLE) << (PAGE_SHIFT - 10));
    seq_puts(m, "\n=============Time=============\n");
    seq_printf(m, "Uptime\t\t\t: %lu.%02lu(s)\nIdletime\t\t: %lu.%02lu(s)\n"
               , (unsigned long) uptime.tv_sec, (uptime.tv_nsec / (NSEC_PER_SEC / 100))
               , (unsigned long) idle.tv_sec, (idle.tv_nsec / (NSEC_PER_SEC / 100)));
}