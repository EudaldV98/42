#!/bin/bash
set -e

INFLUX_CMD="influx -host 127.0.0.1 -port 8086 -execute "

$INFLUX_CMD "CREATE DATABASE influx_db"
$INFLUX_CMD "CREATE USER influx_user WITH PASSWORD 'influx_password'"
$INFLUX_CMD "GRANT ALL ON influx_db TO influx_user"
$INFLUX_CMD 'CREATE RETENTION POLICY "one_year" ON "influx_db" DURATION 365d'
