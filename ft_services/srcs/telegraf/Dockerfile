FROM alpine:3.12.0

RUN apk update && apk add telegraf --repository http://dl-3.alpinelinux.org/alpine/edge/testing/ --allow-untrusted --no-cache

RUN mkdir -p /etc/telegraf

COPY ./telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 8086

ENTRYPOINT ["telegraf"]
