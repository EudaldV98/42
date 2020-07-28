FROM alpine:3.12.0

# We install packages
RUN apk update && apk add --no-cache --upgrade bash \
&& apk add --no-cache --repository=http://dl-cdn.alpinelinux.org/alpine/edge/main libc6-compat
RUN wget https://dl.grafana.com/oss/release/grafana-6.7.2.linux-amd64.tar.gz \
&& tar -zxvf grafana-6.7.2.linux-amd64.tar.gz

# We copy all data: users, dashboards, data sources...
#COPY ./grafana.db ./grafana-6.7.2/data/
COPY start.sh /start.sh

#Here we go
COPY start.sh /start.sh
RUN chmod +x /start.sh
EXPOSE 3000
CMD ./start.sh
