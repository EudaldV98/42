#!/bin/bash

if [ -z "$index" ]
then
	sed -i 's/autoindex off/autoindex on/' /etc/nginx/conf.d/default.conf
	service nginx restart
	echo "Autoindex is activated by default"
elif [ "$index" = "on" ]
then
	sed -i 's/autoindex off/autoindex on/' /etc/nginx/conf.d/default.conf
	service nginx restart
	echo "Autoindex is on"
elif [ "$index"	= "off" ]
then
	sed -i 's/autoindex on/autoindex off/' /etc/nginx/conf.d/default.conf
	service nginx restart
	echo "Autoindex is off"
else
	sed -i 's/autoindex off/autoindex on/' /etc/nginx/conf.d/default.conf
	service nginx restart
	echo "Autoindex is activated by default"
fi
