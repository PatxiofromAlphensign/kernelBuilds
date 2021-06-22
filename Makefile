ccflags-y := \
  -std=gnu99 \
  -Werror \
  -Wno-declaration-after-statement \
  $(CCFLAGS)

module=test.ko
module_dir=build/test.ko

obj-m+=test.o
#obj-y+=tree.o types.o 
KBUILD_DIR=/lib/modules/$(shell uname -r)/build
Local_DIR=build
#OBJECTS=$(patsubst "%.c", "%.o", $(subst "%.o", "%.c", $(obj-y)))

# Kernel module build dependency

all: test $(module_dir) 

test:  $(Local_DIR) prepare
	make -C $(KBUILD_DIR) M=$(PWD) modules
prepare:
	make -C $(KBUILD_DIR) M=$(PWD) prepare
$(module_dir): 
	mv $(module) $@
partial_clean:
	rm -f *.mod.c *.mod.o *.mod  *.o || true
$(Local_DIR):
	mkdir $@
clean: 
	make -C $(KBUILD_DIR) M=./ clean
	rm -rf $(Local_DIR) || true
	rm -rf *.o || true
