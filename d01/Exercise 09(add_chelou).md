# day 01 Exercise 06

 - Напишите командную строку, которая принимает числа, содержащиеся в переменных `FT_NBR1`  И `FT_NBR2`, и отображает сумму двух 

---
---
---


Создадим файл скрипта:

	touch add_chelou.sh




И Запишем в него это:

	echo $FT_NBR1 + $FT_NBR2 | sed "s/\'/0/g" | tr '\\\"\?\!' 1234 | tr 'mrdoc' 01234 | xargs echo 'obase=13; ibase=5;' | bc | tr 0123456789ABC 'gtaio luSnemf'





ИЛИ ЭТО:

	echo $FT_NBR1 + $FT_NBR2 | sed 's/\\/1/g' | sed 's/?/3/g' | sed 's/!/4/g' | sed "s/\'/0/g" | sed "s/\"/2/g" | tr "mrdoc" "01234" | xargs echo "ibase=5; obase=23;" | bc | tr "0123456789ABC" "gtaio luSnemf"





ИЛИ ЭТО:

```
echo $FT_NBR1 + $FT_NBR2 | sed "s/\'/0/g" | tr '\\\"\?\!' 1234 \
| tr 'mrdoc' 01234 | xargs echo 'obase=13; ibase=5;' | bc \
| tr 0123456789ABC 'gtaio luSnemf'
```





> Для проверки работы скрипта перед его выполнением добавьте в самое начало две переменные для обработки и уже после > > этого запускайте скрипт
> ```
> FT_NBR1=\"\"!\"\"!\"\"!\"\"!\"\"!\"\"
> 
> FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
> ```

---
---
---

Документация.

Google.com :)