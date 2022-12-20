FROM debian

WORKDIR /home/

RUN apt-get update && \
	apt-get install -y gcc-10 make build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev valgrind

RUN apt-get clean

CMD ["bash"]