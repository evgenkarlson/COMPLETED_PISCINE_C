# day 01 Exercise 01


Создадим файл скрипта:

	touch print_groups.sh


Запишем в срипт это:
```
#!/bin/sh
groups $FT_USER | tr -s ' ' ',' | awk '{printf $0}'
```



или это:
```
#!/bin/sh
groups $FT_USER | tr ' ' ',' | tr -d '\n'
```



или это:
```
#!/bin/sh
groups $FT_USER | sed 's/ /,/g' | tr -d '\n'
```


---
---
---


##  Документация.

Google.com :)
