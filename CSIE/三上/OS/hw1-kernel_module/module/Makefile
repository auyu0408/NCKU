.PHONY: clean
CC := gcc
override CFLAGS += -O3 -Wall

SOURCE := ../app.c
BINARY := app

MODULE_NAME := my_info
obj-m := $(MODULE_NAME).o
KERNEL_VER := $(shell uname -r)
KERNEL_DIR := /lib/modules/$(KERNEL_VER)/build
PWD := $(shell pwd)

all: $(BINARY) module ins
clean: del_module del_app

debug: CFLAGS += -DDEBUG -g
debug: $(BINARY)

$(BINARY): $(SOURCE) $(patsubst %.c, %.h, $(SOURCE))
	$(CC) $(CFLAGS) $< -o $@

del_app:
	rm -f *.o $(BINARY)

del_module:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

module:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
ins:
	sudo insmod $(MODULE_NAME).ko
rm:
	sudo rmmod $(MODULE_NAME)
