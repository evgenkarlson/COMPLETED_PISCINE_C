# shell 00 Exercise 07



- #### Создайте файл `b`. Файлы для работы нам предоставляется файл `a` со старой версией файла и файл `sw.diff`, который хранит информацию о новых изменениях.



#### Содержимое файла `a` при просмотре его через программу `cat` с флагом `-e` будет выглядеть так:

```
%>cat -e a
STARWARS$

Episode IV, A NEW HOPE It is a period of civil war.$

$

Rebel spaceships, striking from a hidden base, have won their first victory against the evil

Galactic Empire.$

During the battle, Rebel spies managed to steal secret plans to the Empire s ultimate weapon, the

DEATH STAR,$

an armored space station with enough power to destroy an entire planet.$

$

Pursued by the Empire s sinister agents, Princess Leia races home aboard her starship, custodian of

the stolen plans that can save her people and restore freedom to the galaxy...$

$
```
---
---

#### 1) Извлекаем архив содержащий файлы `a` и `sw.diff`:
    
    tar -xf ./'resources.tar.gz'

#### 2) Используем программу `patch`. Программа возьмет файл `sw.diff` с описанием новых изменений и совместит эти изменения с текстом из файла `a`, и создаст на их основе файл `b` хранящего восстановленную версию текста с новыми изменениями.:

    patch ./a  -o ./b < ./sw.diff

> #### Чтобы отменить изменения в файле `a` наберите в терминале:
>
>   patch ./a -R < ./sw.diff

#### Содержимое файла `b`(с восстановленной версией текста с новыми изменениями) при просмотре через программу `cat` с флагом `-e` будет выглядеть так:
```
%>cat -e ./b
Episode V, A NEW H0PE It is a period of civil war$
Rebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire. $
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the STAR DEATH, an armored space station with enough power to destroy an entire planet.$
$
$
Pursued by the Empire's sinister agents,$
Princess Mehdi races home aboard her starship, custodian of the stolen plans that can save her people and restore the dictatorship to the galaxie..$
$
$
$
$
```

#### 3) Сделаем проверку. Сравним файл с изменниями `sw.diff` полученый в задании и файл `sw.diff2`, который мы получим сравнив файлы `a` и файл `b` с новой версией текста созданный программой `patch`. Если при сравнении файлов `sw.diff` и `sw.diff2` вывод программы будет пустым - значит файлы идентичны и восстановление новой версии текста, с помощью сохраненных измениений в файле `sw.diff` и старой версии текста из файла `a`, прошло успешно:

    diff ./a ./b > ./sw.diff2

    diff ./sw.diff ./sw.diff2



---
---


## Документация:

man diff:
https://ru.wikipedia.org/wiki/Diff


man patch:
https://man7.org/linux/man-pages/man1/patch.1.html

Google.com
