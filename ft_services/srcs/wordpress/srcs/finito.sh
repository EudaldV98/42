/etc/init.d/sano.sh &
telegraf &
php-fpm7
nginx -g 'daemon off;'
