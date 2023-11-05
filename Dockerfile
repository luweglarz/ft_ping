FROM debian:buster

RUN apt-get update \
&& apt -y install build-essential \
&& apt-get install -y locales \
&& apt -y install valgrind 

#Set locale to C
ENV LC_ALL C

RUN mkdir ft_ping

CMD tail -f /dev/null