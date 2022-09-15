# Embedded_CPlusPlus

In this repository, there are examples of codes, some tips, and part of the information presented in the book Embedded Programming with Modern C++ Cookbook.

&nbsp;
# Setting up the enviroment

For more details and information, sees Chapter 2 of Embedded Programming with Modern C++ Cookbook.

&nbsp;
## Build system in a Docker container 


1. Install Docker. See the information about to install docker in the link in https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository.

2. Add the current user to a Docker group. This will allow you to use Docker commands without sudo privilege:

```console
sudo usermod -aG docker ${USER}
```

3. Make the log out or restart the machine.

4. To pull the Docker image, run this command below:

```console
docker pull ubuntu:bionic
```

5. Access the folder that you will use for this project and create a working directory. For example:

```console
mkdir ./Book_EPMC
```

6. And run the downloaded image in the container and create a volume to the Book_EPMC folder:

```console
docker run -it -v $PWD/Book_EPMC:/home/pi/Book_EPMC -w /home/pi/Book_EPMC ubuntu:bionic
```

The output have to be something like this:

```console
root@567702b8688b:/# 
```

7. Finaly, run the uname -a command to get information about the system:

```console
uname -a
```

The output expected is similar to:

```console
Linux e465469a6d72 5.13.0-48-generic #54~20.04.1-Ubuntu SMP Thu Jun 2 23:37:17 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
```

### Install cross-compilation on Docker Host PC

1. Inside the root Git repository, runs the docker container.
```console
docker run -it -v $PWD/Book_EPMC:/home/pi/Book_EPMC -w /home/pi/Book_EPMC ubuntu:bionic
```

2. And install the packages.
On docker run

```console
apt update -y && apt install -y crossbuild-essential-armel cmake ssh gdb-multiarch
```

3. Check if the compiler was installed.

```console
arm-linux-gnueabi-g++ --version
```

4. And the CMake version.

```console
cmake --version
```

&nbsp;
## Working with emulators
### Installing QEMU ARM on Ubuntu

```console
sudo apt update
sudo apt install qemu-system-arm
```

**Note:** To return mouse focus to Host PC press Ctrl + Alt + G.

&nbsp;
### Running Raspberry on QEMU
```console
qemu-system-arm -M versatilepb -dtb versatile-pb.dtb -cpu arm1176 -kernel kernel-qemu-4.14.79-stretch -m 256 -drive file=2019-07-10-raspbian-buster-lite.img,format=raw -append "rw console=ttyAMA0 rootfstype=ext4 root=/dev/sda2 loglevel=8" -net user,hostfwd=tcp::22023-:22,hostfwd=tcp::9090-:9090 -net nic -serial stdio
```

Entre with the login and password when the Raspberry finish the boot process 
Login: pi
Password: rapberry

&nbsp;
## Setup
### Starting SSH on QEMU Raspberry
```console
sudo systemctl start ssh
```

## Connecting

### Docket Host

### Establish a connection with QEMU Raspberry

1. First, starting SSH on QEMU Raspberry
```console
sudo systemctl start ssh
```

2. After this, is possible to connect by SSH use the Host PC
```console
ssh pi@192.168.122.1 -p22023
```

3. Or copy file to Raspberry
```console
scp -P22023 /chapter_02/hello/hello pi@192.168.122.1:~
```

## Debugging embedded applications

1. On QEMU Raspberry run the command to debugging the hello executable
Open the executable with GDB
```console
gdb ./hello
```

Run the GDB
```console
run
```

Exit
```console
q
```

## Remote debugging

1. Install gdb-multiarch on host

```console
sudo apt-get install gdb-multiarch
```

2. Install gdbserver on Raspberry Pi

```console
sudo apt-get install gdbserver
```

3. Inside the target run the hello application under gdbserver

```console
gdbserver 0.0.0.0:9090 ./hello
```

4. Inside the build system terminal acess the hello folder and run the command, passing the application binary as a parameter

```console
gdb-multiarch -q hello
```

5. Configure a remote connection by typing the following command in the GDB command line

```console
target remote X.X.X.X:9090
```

6. Type the continue command

```console
continue
```
