# linux kernel module HelloWorld

## build steps

```bash
make
# check build result
ls modul.ko
```

## install/remove module

```bash
# install
sudo insmod modul.ko
# check the installation result
lsmod | grep modul
# view the printk info
dmesg | tail -2

# uninstall
sudo rmmod modul.ko
# view the printk info
dmesg | tail -2
```

