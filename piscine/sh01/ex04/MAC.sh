#!/usr/bin/env bash

ifconfig | grep ether | awk '{print $2}'
