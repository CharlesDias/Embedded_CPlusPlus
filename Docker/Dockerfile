FROM ubuntu:20.04

LABEL maintainer="Charles Dias <charlesdias@tecnofuturo.com.br>"

# Download Linux support tools
RUN apt update && apt clean && DEBIAN_FRONTEND=noninteractive TZ=Etc/America apt install -y \
      build-essential crossbuild-essential-armel \
      cmake ssh gdb-multiarch

# Set up a development tools directory
WORKDIR /home/pi/Book_EPMC

    