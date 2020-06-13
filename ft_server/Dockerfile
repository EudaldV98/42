FROM debian:buster-slim

RUN  apt-get update \
		&& apt-get upgrade -y \
		&& apt-get install -y \
		nginx \
		mariadb-server mariadb-client \
		php7.3-fpm php7.3-mysql \
		vim \
		unzip \
		wget \
		php-mbstring php-zip php-gd

RUN wget https://wordpress.org/latest.zip \
		&& unzip latest.zip -d /usr/share/nginx/ \
		&& wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-all-languages.tar.gz \
		&& tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz -C /usr/share/nginx/

RUN chown www-data:www-data /usr/share/nginx/html/ -R \
		&& chown www-data:www-data /usr/share/nginx/wordpress/ -R

RUN rm /etc/nginx/sites-enabled/default

COPY /srcs/init_db.sql /tmp/

RUN service mysql start \
		&& mysql -u root --password= < /tmp/init_db.sql

COPY srcs/localhost /etc/nginx/conf.d/default.conf

COPY srcs/info.php /usr/share/nginx/html/info.php

COPY srcs/wp-config.php /usr/share/nginx/html/wordpress/wp-config.php

EXPOSE 80

CMD service nginx restart \
		&& service mysql start \
		&& service php7.3-fpm start
