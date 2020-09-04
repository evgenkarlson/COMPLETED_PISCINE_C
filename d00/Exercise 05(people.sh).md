# day 00 Exercise 05

- Теперь, когда вы понимаете основы `LDAP` (вроде), вы можете начать искать людей. В файле с именем `people.sh` введите команду, которая выведет список cn для всех учетных записей с идентификатором пользователя, начинающимся с `z`. В этом списке будет показан только `cn` в обратном алфавитном порядке, а НЕ с учетом регистра. Там не должно быть никаких ненужных пустых строк.


---
---
---


#### Создайте файл:

    touch people.sh



#### с этим содержимым:

```
#!/bin/sh
ldapsearch -x  -L "(uid=z*)" | grep "cn:" | sort -r --ignore-case | cut -c5-50
```


#### ИЛИ этим:

```
#!/bin/sh
ldapsearch -LLL -Q "uid=z*" cn | grep -i "cn:" | sort -r 
```






---
---
---

## Документация:


LDAP

https://www.math.utah.edu/cgi-bin/man2html.cgi?/usr/local/man/man1/ldapwhoami.1

https://pro-ldap.ru/tr/zytrax/ch14/



cut 

https://itproffi.ru/komanda-cut-v-linux/