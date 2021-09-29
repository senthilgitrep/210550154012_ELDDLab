##ifneq($(KERNELRELEASE),)
	obj-m:=p1.o
##else 
	KDIR=/lib/modules/$(shell uname -r)/build/
	PWD:=$(shell pwd)
default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm read1 write1

install:
	$(MAKE) -C $(KDIR) M=$(PWD) modules_install
        
Read1:
	$(shell make read1)

Write1:
	$(shell make write1)

#endif
