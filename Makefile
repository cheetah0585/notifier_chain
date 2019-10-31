ifeq ($(KERNELRELEASE), )
KERNEL_DIR ?= /home/hanch/study/runninglinuxkernel_4.0/

modules:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
install:
	cp *.ko $(KERNEL_DIR)/kmodules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

else
	obj-m += master.o slave1.o slave2.o  slave3.o send_noti.o

endif
