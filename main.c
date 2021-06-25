#include<linux/module.h>

#ifdef kernel_build 
#include <linux/ftrace.h>
#include <linux/kallsyms.h>
#include <linux/kernel.h>
#include <linux/linkage.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/buffer_head.h>
#include <linux/kprobes.h>
#include <linux/init.h>
#include <linux/fs.h>
#endif

#if defined(linux) || defined(windows) && windows>3 //yes fuck windows
#else 
#define linux "kernel<no>"
#define linux_(str) str"nigger"
#endif

#ifdef kernel_build 
struct structs {
	struct kprobe *kp;
	struct  page pg;
	int(*fp)(void);
};

struct structs testlib(int x) {
#ifdef GFP_KERNEL
	struct structs *l = NULL;
	l->kp = (struct kprobe*)kmalloc(sizeof(struct kprobe), GFP_KERNEL);
	struct kprobe **addr = &l->kp;
	char *k[sizeof(struct kprobe)];
#endif
	for(int i=0; i<sizeof(struct kprobe); i++) k[i] = (char*)l->kp;
	int (*fp)(void) = (int(*)(void))k;
	l->fp= fp;
	l->kp->addr = (unsigned char*)(addr+sizeof(l->kp));
	return *l;
}

struct structs prepare_sturcts(struct structs k){ 
	k = testlib(10);
	printk("%d", (int)k.fp());
	//struct file_system_type fst;
	//put_filesystem(&fst);
	kmap(&k.pg);
	return k;
}
#endif


