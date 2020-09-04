# day 00 Exercise 04

- Теперь, когда у вас есть билет Kerkebos, пришло время узнать, кто вы! Как вы, возможно, уже знаете, все пользователи в школе работают на `LDAP`: какая-то элементарная цифровая телефонная книга - для тех, кто помнит, что такое телефонная книга ... В файле `who_am_i.sh` введите команду, которая будет возвращать только Значение отличительного имени.

---
---
---

Создайте файл:

	touch who_am_i.sh



с этим содержимым:
```
#!/bin/sh
ldapwhoami -Q | cut -c 4-
```



ИЛИ этим:
```
#!/bin/sh
ldapwhoami -Q | cut -d ":" -f 2
```


> ldapwhoami открывает соединение с сервером `LDAP`, связывается и выполняет операцию `whoami`.


---
---
---


## Документация:

LDAP

https://habr.com/ru/company/aktiv-company/blog/170829/

https://www.f-notes.info/linux:ldap_ad

https://pro-ldap.ru/tr/zytrax/ch14/



cut 

https://itproffi.ru/komanda-cut-v-linux/