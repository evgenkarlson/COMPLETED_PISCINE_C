# day 00 Exercise 07


#### Создайте файл 

    touch git_commit.sh




#### с этим содержимым:
```
#!/bin/sh
git log -n 5 --pretty=format:"%H"
```



#### На выводе должно быть получится так(5 строк):
```
05cb017fddb87b588f015fbd3b44ac9b96cba760
90f900418ec48052a51a674963e6d5688fa2fe29
6bdaf71595ff90e987398059071b8f668f29abb6
26be13667edd1a882ad5093725d962bc056a9c9f
4caf2adc0b34c02c4c616e2e2673b25bad9cd2e4
```