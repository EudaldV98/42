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
		&& tar xvf phpMyAdmin-4.9.0.1-all-languages.tar.gz -C /usr/share/nginx/ \
		&& mv /usr/share/nginx/phpMyAdmin-4.9.0.1-all-languages /usr/share/nginx/phpMyAdmin

RUN mkdir -p /var/lib/phpmyadmin/tmp \
		&& chown www-data:www-data /usr/share/nginx/html/ -R \
		&& chown www-data:www-data /usr/share/nginx/wordpress/ -R \
		&& chown -R www-data:www-data /var/lib/phpmyadmin

RUN rm -rf /etc/nginx/modules-enabled \
		&& rm -rf /usr/share/nginx/modules /usr/share/nginx/modules-available 

RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

COPY /srcs/init_db.sql /tmp/

RUN service mysql start \
		&& mysql -u root < /tmp/init_db.sql

COPY srcs/autoindex.sh /tmp/

COPY srcs/localhost /etc/nginx/conf.d/default.conf

COPY srcs/info.php /usr/share/nginx/info.php

COPY srcs/wp-config.php /usr/share/nginx/wordpress/wp-config.php

COPY srcs/config.inc.php /usr/share/nginx/phpMyAdmin/config.inc.php

EXPOSE 80

EXPOSE 443

CMD service mysql start \
		&& service php7.3-fpm start \
		&& /tmp/autoindex.sh \
		&& bash

