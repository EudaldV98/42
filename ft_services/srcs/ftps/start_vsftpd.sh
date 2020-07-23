#!/bin/sh

USERS='user|password|/ftp/user|1000'

for i in $USERS ; do
    NAME=$(echo $i | cut -d'|' -f1)
    PASS=$(echo $i | cut -d'|' -f2)
  FOLDER=$(echo $i | cut -d'|' -f3)
     UID=$(echo $i | cut -d'|' -f4)

FOLDER="/ftp/user"

if [ ! -z "$UID" ]; then
  UID_OPT="-u $UID"
fi

echo -e "$PASS\n$PASS" | adduser -h $FOLDER -s /sbin/nologin $UID_OPT $NAME
mkdir -p $FOLDER
chown $NAME:$NAME $FOLDER
unset NAME PASS FOLDER UID
done

ADDR=$(cat ip)

exec /usr/sbin/vsftpd -opasv_address=$ADDR /etc/vsftpd/vsftpd.conf
