## About ##

As part of CSC 502 Principles of OS & Distributed Systems course, I have customized an open source operating system, MINIX 3, to display custom banner on startup and shutdown, add a new system command that can be used on terminal and add a new system call and user library that can be used for calling internal kernel methods.

## Introduction ##

MINIX 3 is a free Open-Source Operating System designed to be highly flexible, secure and reliable. MINIX runs on x86 and ARM CPUs. It is compatible with NetBSD and runs numerous NetBSD packages. It is designed as a tiny microkernel (kernel mode) running with rest of Operating System which is running as numerous isolated and protected processes (user mode). 

## Installation ##

In order to install MINIX 3 Operating System on local machine over a Virtual Machine, following are steps:
1.	Download latest MINIX 3 image from its official website
2.	Install VirtualBox (https://www.virtualbox.org/wiki/Downloads)
3.	Start the VirtualBox, select General tab under Preferences and change Default Machine Folder to your choice of folder. This helps in creating multiple host machines.
4.	Create a new Virtual Machine by clicking on New Button
5.	Enter name as Minix3.2.1, Type as Other and Version as Other/unknown
6.	Enter 256 MB for the memory size on the Memory size screen
7.	On the Hard Drive screen, select following size and properties of Virtual Hard Disk as follows:
    -	Create VHD and choose vdi (Virtual Box disk image) as hard disk type
    -	For storage on physical hard drive select dynamically allocated
    -	Type a name (say Minix3.2.1) for the new virtual disk
    -	Slide to 1.2GB for the size of the disk
8.	Create Disk Image and Virtual Machine
9.	Click on Minix3.2.1 and start the VM
10.	Select Settings tab on main screen of VirtualBox, select System tab and select Hardware Clock in UTC Time checkbox.
11.	You are all set to install MINIX 3.

Here is how VirtualBox main screen will look like and you can see new Minix3.2.1 VM listed in left panel.




Below are the installation steps for MINIX 3 Operating System.

1.	Choose Minix3.2.1 and under Storage, click on [Optical Drive] Empty. On prompt, choose a disk image. Navigate to and select ISO image (*.iso)
2.	Click on green Start arrow and virtual machine will boot from ISO image.
3.	A terminal window i.e. minix login prompt, will show up.
4.	Type root and then type setup command
5.	Follow setup instructions and select default for all options except the following:
    -	Choose uk for keyboard type
    -	Enter 5 for How big do you want your /home to be in MB (0-614)?

Once installation completes, you can select Ethernet card and network configuration (select default). Once setup is completed, type poweroff at MINIX VM prompt. Now it is time to boot from the VM disk and not the CD ISO image so do the following:
1.	Select MINIX3.2.1 in VirtualBox
2.	Select Settings on main screen, click on Storage and in storage tree, select .iso file and remove it.

Now it will boot into newly installed MINIX 3 operating system.

As MINIX console does not have scroll bars, you can use ssh and sftp to login to MINIX for file editing, lets first install openssh.

1.	Select Minix3.2.1 VM and start it
2.	At the MINIX prompt, login in as root (no password will be asked)
3.	Type passwd command at the prompt and enter root as password. 
4.	Use Minix package manager pkgin to install openssh. Type pkgin at the MINIX prompt to check package manager commands.
5.	Type pkgin update to initialize package manager database. If update fails then you can use alternative locations as follows:
    -	PKG_REPOS=http://homepages.cs.ncl.ac.uk/nick.cook/csc2025/minix/3.2.1/packages;
    -	export PKG_REPOS at the prompt, or by editing /usr/pkg/etc/pkgin/repositories.conf 
6.	At the MINIX prompt, type pkgin install openssh to install openssh, 
7.	After installation has finished, type shutdown -r to reboot the system. 
8.	On boot up, a ssh keypair is generated and sshd service starts running.

Use ssh (e.g. Putty), scp (e.g. WinScp) or remote connect eclipse to connect to VirtualBox VM. Configure VM port forwarding in VirtualBox VM settings as follows:

1.	Navigate to Settings  Network  Adapter 1  Advanced  Port Forwarding
2.	Select + for adding port forwarding configuration
3.	Use below port forwarding attributes:
  -	Name		    : jgosalia
  -	Host Port	  : 2222
  -	Guest IP	  : 10.0.2.15
  -	Guest Port	: 22
  -	Host IP		  : 127.0.0.1
  -	Protocol	  : TCP

Using ipconfig command at the MINIX command prompt, Guest IP address of VM can be found. ssh to the VM from host machine after setting up the port forwarding.

**ssh -p 2222 root@127.0.0.1**


Type the above command in a terminal on host machine or in a ssh/scp client. With this configuration, port forwarding will enable the VM to start listening on port #2222 on the local host (127.0.0.1). If port 2222 is in use, then some other high port number.

**NOTE:** these instructions were executed on Mac OS (Sierra Version 10.12.6) but it should work on Windows OS (Windows 10) machine too.

## Tree Hierarchy ##

Below are the tree hierarchy of the files, which were modified for this project




## Custom startup and shutdown banner ##


## Custom system command ##


## Custom system call ##


## Build Kernel and Libraries ##

When making changes for following, use the highlighted commands at /usr/src/releasetools
  -	customizing startup and shutdown banner
  -	system command
  -	system call (access system call directly)

```
  -	make clean install
  -	reboot
```

When making changes for following, use the highlighted commands at /usr/src
  -	system call (access system call through user library)

```
  -	make build
  -	reboot
```


## References & Credits ##

I have taken help from the following websites and links for the installation of MINIX and understanding the operating system files but all the implementations are entirely done by me.

-	https://www.virtualbox.org/wiki/Downloads
-	http://homepages.cs.ncl.ac.uk/nick.cook/csc2025/minix/ 
-	http://www.minix3.org/
      -	http://wiki.minix3.org/doku.php?id=developersguide:eclipsetutorial 
      -	http://wiki.minix3.org/doku.php?id=releases:3.2.0:developersguide:rebuildingsystem


## Disclaimer ##

This is just a course project and it is not a replica or replacement of the MINIX 3 Operating System.

It is just an attempt by a student to learn and customize an open source operating system.

Please do not use this as a replacement for publicly published MINIX 3 operating system. 
