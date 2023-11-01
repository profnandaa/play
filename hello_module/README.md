## Quick Guide

- Build: `make`
- Clean-up: `make clean`
- Install: `sudo insmod hello_module.ko`
- View the kernel logs: `sudo dmesg | grep hello`
- Uninstall: `sudo rmmod hello_module`


## Sample Output

```
[74767.159049] hello_module: loading out-of-tree module taints kernel.
[74767.159082] hello_module: module verification failed: signature and/or required key missing - tainting kernel
[86079.964848] hello: parent process = sudo [17115]
[86079.964850] hello: current process = insmod [17116]
[86079.964852] hello: init process = systemd [1]
[86079.964853] hello: child(0): systemd-journal [263]
[86079.964855] hello: child(1): systemd-udevd [318]
[86079.964856] hello: child(2): hv_kvp_daemon [399]
[86079.964858] hello: child(3): rpcbind [534]
[86079.964859] hello: child(4): systemd-oomd [536]
[86079.964861] hello: child(5): systemd-resolve [537]
[86079.964862] hello: child(6): systemd-timesyn [538]
[86079.964864] hello: child(7): accounts-daemon [545]
[86079.964865] hello: child(8): acpid [546]
[86079.964867] hello: child(9): avahi-daemon [549]
```
