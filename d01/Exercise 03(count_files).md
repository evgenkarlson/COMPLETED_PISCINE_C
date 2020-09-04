# day 01 Exercise 03

- Напишите командную строку, которая отображает количество обычных файлов и каталогов в текущем каталоге и во всех его подкаталогах, включая «.», Из начального каталога.

---
---
---

Создадим файл скрипта:

	touch count_files.sh



Запишем в срипт это:
```
#!/bin/sh
find . -type f -o -type d | wc -l | sed 's# * ##'
```



или это:
```
#!/bin/sh
find . \( -type f -o -type d \) | wc -l | tr -d ' '
```




или это:
```
#!/bin/sh
find . -type f -o -type d | wc -l | tr -d ' '
```




или это:
```
#!/bin/sh
( find . -type d && find . -type f ) | wc -l | sed 's/ //g'
```


---
---
---

Документация.

Google.com :)