FROM alpine:3.10
RUN apk --no-cache add vsftpd

ARG IP

RUN echo ${IP} > ip

COPY start_vsftpd.sh /bin/start_vsftpd.sh
COPY vsftpd.conf /etc/vsftpd/vsftpd.conf

EXPOSE 21 31000

ENTRYPOINT ["/bin/start_vsftpd.sh"]

