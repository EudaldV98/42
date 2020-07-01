FROM alpine:3.12.0

RUN apk update \
		&& apk upgrade \
		&& apk add \
		nginx \
		openrc \
		vim 

RUN adduser -D -g 'www' www \
		&& mkdir /www \
		&& chown -R www:www /var/lib/nginx \
		&& chown -R www:www /www

RUN mkdir -p /run/nginx/

RUN rm -rf etc/nginx/conf.d/default.conf

COPY srcs/localhost5 /etc/nginx/conf.d/nginx.conf


#COPY srcs/index.html /var/lib/nginx/html/index.html
COPY srcs/index.html /usr/share/nginx/html/
#COPY srcs/index.html /www/

EXPOSE 80

#CMD /etc/init.d/nginx start
CMD ["nginx", "-g", "daemon off;"]
