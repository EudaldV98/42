FROM debian:buster

WORKDIR /

RUN  apt-get update && apt-get upgrade -y && apt-get install -y apache2

COPY index.html var/www/html/

CMD etc/init.d/apache2 start

EXPOSE 80
