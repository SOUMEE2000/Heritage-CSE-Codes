#!/bin/bash

echo "Enter the word to be deleted"
read word
`grep -v ${word} $1 > tmpfile && mv tmpfile $1`
