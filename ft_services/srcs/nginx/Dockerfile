FROM alpine:3.12.0

RUN apk update \
		&& apk upgrade \
		&& apk add \
		nginx \
#		openrc \
		openssl 

RUN adduser -D -g 'www' www \
		&& mkdir /www \
		&& chown -R www:www /var/lib/nginx \
		&& chown -R www:www /www

RUN mkdir -p /run/nginx/

RUN rm -rf etc/nginx/conf.d/default.conf

#RUN yes "" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
#		-keyout /etc/ssl/private/nginx-selfsigned.key \
#		-out /etc/ssl/certs/nginx-selfsigned.crt

COPY localhost /etc/nginx/conf.d/nginx.conf

COPY index.html /usr/share/nginx/html/

EXPOSE 80

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
