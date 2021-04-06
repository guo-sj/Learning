#!/bin/bash
# create a directory and do 'swift init'

# judge argument's number
if [ $# != 1 ]
then
    echo Usage: ./$0 [dir name you want to create]
    exit
fi

# create and swift init
mkdir $1 && cd $1 && swift package init --type executable

exit


