#!/bin/sh
var=$(ifconfig | grep "inet " | cut -d ' ' -f2)
if test -z "$var"
then
	echo "Je suis perdu!"
else
	echo $var | tr ' ' '\n'
fi

