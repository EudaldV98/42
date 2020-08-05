FROM alpine:latest

RUN apk update
RUN apk add mysql mysql-client openrc

RUN apk add telegraf --repository http://dl-cdn.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

RUN mkdir -p /run/mysqld && openrc \
	&& touch /run/openrc/softlevel
COPY srcs/init.sh /tmp/init.sh
COPY srcs/my.cnf /etc/mysql/my.cnf

RUN mkdir -p /etc/telegraf
COPY ./srcs/telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 3306

CMD sh /tmp/init.sh ; /usr/bin/mysqld -u root ;
