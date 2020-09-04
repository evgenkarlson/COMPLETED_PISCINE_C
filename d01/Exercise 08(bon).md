# day 01 Exercise 07

 - Напишите командную строку, которая отображает количество пользователей компьютерного парка, чья фамилия содержит «bon». (это также включает в себя господина "bonheur")

---
---
---

Создадим файл скрипта:

	touch bon.sh




И запишем в него это:
```
#!/bin/sh
ldapsearch 'cn=*bon*' cn | grep -v '#\|dn\|search\|result\|^[[:space:]]*$' | wc -l | sed 's/ //g'
```




ИЛИ ЭТО:
```
#!/bin/sh
ldapsearch -Q -S cn "(sn=*bon*)" cn | grep "^cn: " | wc -l | sed 's# * ##'
```




ИЛИ ЭТО:
```
#!/bin/sh
ldapsearch -Q sn="*bon*" | grep "^sn" | wc -l | tr -d ' '
```




ИЛИ ЭТО:
```
#!/bin/sh
ldapsearch -LLL "last-name=*bon*" last-name 2> /dev/null | sed -n '/last-name:/p' | wc -l | sed 's/ //g' 
```

---
---
---

Документация.

Google.com :)