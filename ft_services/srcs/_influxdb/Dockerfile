FROM alpine:3.12.0

RUN apk update && apk add influxdb

EXPOSE 8086

COPY ./init-influxdb.sh /init-influxdb.sh

CMD ["/init-influxdb.sh"]

CMD influxd run -config /etc/influxdb.conf
