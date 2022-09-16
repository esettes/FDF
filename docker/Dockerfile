FROM debian:testing

WORKDIR /home/

RUN apt-get update && \
	apt-get install -y vim gcc-11 git make build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev

RUN apt-get clean
	
CMD ["bash"]
