#!/bin/bash

if [ ! -f "$1" ]; then
   echo "$1 doesn't exist."
else
   time=`date -r $1`
   echo "$1 file was last modified on ${time}"
fi
