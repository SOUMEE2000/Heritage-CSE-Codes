#!/bin/bash
SRC="$1"
DST="$2"
if [ $# -ne 2 ]
then
  echo "$(basename $0) dir1 dir2"
  exit 1
fi
 
if [ ! -d $SRC ]
then
    echo "Directory $SRC does not exists!"
    exit 2
fi
 
 
if [ ! -d $DST ]
then
    echo "Directory $DST does not exists!"
    exit 2
fi
 
for f in $DST/*
do
#echo Processing $f
    if [ -f $f ]
    then
         tFile="$SRC/$(basename $f)"
    if [ -f $tFile ]
    then
        echo -n "Deleting $tFile..."  
	/bin/rm $tFile  
	[ $? -eq 0 ] && echo "done" || echo "failed"
														 
    fi
    fi
 done
