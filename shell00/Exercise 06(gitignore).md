# shell 00 Exercise 06

- #### В этом упражнении вы напишете короткий сценарий оболочки, который перечислит все существующие файлы, игнорируемые вашим репозиторием `Git`. Пример:
```
%> bash git_ignore.sh | cat -e
.DS_Store$
mywork.c~$
%

```

> #### RTFM!


---
---


#### 1) Создайте файл 

    touch gitignore.sh




#### 2) с этим содержимым:
```
#!/bin/sh
find . -exec git check-ignore {} + | xargs -I{} basename {}
```

