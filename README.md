# Fork of SimplestLKM

This is a very simple Linux Kernel Module.

## Install

Build the module:
```
make
```

Wait for the messages in a shell:
```
journalctl -f -k
```

In another shell, insert, wait a bit and remove the module:
```
sudo insmod hello.ko; sleep 10; sudo rmmod hello
```