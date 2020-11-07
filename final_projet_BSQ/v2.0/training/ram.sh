if [ "$1" = "" ] ; then
  echo -n "Nom du process : "
    read process
else
	  process=$1
  fi

  ps aux | grep $process | grep -v grep | awk 'BEGIN { sum=0 } {sum=sum+$6; } END {printf("Taille RAM utilisée: %s Ko\n",sum)}'
