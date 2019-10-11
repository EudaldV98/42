#!/usr/bin/env bash

git log | grep ^commit | awk '{print $2}' | head -5
