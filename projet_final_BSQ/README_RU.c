/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************

Subject
Предмет

• The biggest square :
◦ The aim of this project is to find the biggest square on a map, avoiding 
obstacles.
◦ A file containing the map will be provided. It’ll have to be passed as an
argument for your program.
◦ The first line of the map contains information on how to read the map :
   ∗ The number of lines on the map;
   ∗ The "empty" character;
   ∗ The "obstacle" character;
   ∗ The "full" character.
◦ The map is made up of ’"empty" characters’, lines and ’"obstacle" characters’.
◦ The aim of the program is to replace ’"empty" characters’ by ’"full"
characters’ in order to represent the biggest square possible.
◦ In the case that more than one solution exists, we’ll choose to represent the 
square that’s closest to the top of the map, then the one that’s most to the left.

• Definition of a valid map :
◦ All lines must have the same length.
◦ There’s at least one line of at least one box.
◦ At each end of line, there’s a line break.
◦ The characters on the map can only be those introduced in the first line.
◦ In case of an invalid map, your program should display map error on the error 
output followed by a line break. Your program will then move on to the next map



• Самая большая площадь:
◦ Цель этого проекта - найти самую большую площадь на карте, избегая препятствий.
◦ Будет предоставлен файл, содержащий карту. Это должно быть передано в качестве 
аргумента для вашей программы.
◦ Первая строка карты содержит информацию о том, как читать карту:
   ∗ количество линий на карте;
   ∗ «пустой» символ;
   ∗ характер «препятствие»;
   ∗ «полный» характер.
«Карта состоит из« пустых »символов, линий и« препятствий ».
◦ Цель программы - заменить «пустые» символы на «полный»
символов, чтобы представить максимально возможный квадрат.
◦ В случае, если существует более одного решения, мы выберем представление 
квадрата, который находится ближе всего к верхней части карты, а затем квадрата,
который расположен наиболее слева.

• Определение действительной карты:
Lines Все строки должны иметь одинаковую длину.
◦ Есть хотя бы одна строка хотя бы из одной рамки.
◦ На каждом конце строки есть разрыв строки.
Characters Символы на карте могут быть только теми, которые введены в первой строке.
◦ В случае неверной карты ваша программа должна отобразить ошибку карты в выводе ошибки с последующим переводом строки. Ваша программа перейдет к следующей карте


• Here’s an example of how it should work :
• Вот пример того, как это должно работать:

%>cat example_file
9.ox
...........................
....o......................
............o..............
...........................
....o......................
...............o...........
...........................
......o..............o.....
..o.......o................

%>./bsq example_file
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxxo..............
.....xxxxxxx...............
....oxxxxxxx...............
.....xxxxxxx...o...........
.....xxxxxxx...............
......o..............o.....
..o.......o................
%>


   **************************************************************************   
   **************************************************************************   
   **************************************************************************   


Instructions
Инструкции

• The executable must be called bsq and be present in the main directory.
• You must respect the Norm.
• You may only use methods learnt during the Piscine.
• The submission directory must have an author file containing your logins :

$>cat auteur
login_1:login_2
$>

• Your program must handle 1 to n files as parameters.
• When your program receives more than one map in argument, each solution or error 
must be followed by a line break.
• Should there be no passed arguments, your program must be able to read on the
standard input.
• You should have a valid Makefile that’ll compile your project.
• You may only use the following functions : exit, open, close, write, read, malloc
and free.
• You may ask questions on the forum.



• Исполняемый файл должен называться bsq и присутствовать в главном каталоге.
• Вы должны уважать Норму.
• Вы можете использовать только методы, изученные во время Piscine.
• В каталоге отправки должен быть файл автора, содержащий ваши логины:

$>cat auteur
login_1:login_2
$>

• Ваша программа должна обрабатывать от 1 до n файлов в качестве параметров.
• Когда ваша программа получает более одной карты в качестве аргумента, каждое 
решение или ошибка должны сопровождаться переводом строки.
• Если не будет переданных аргументов, ваша программа должна быть в состоянии 
читать на стандартный ввод.
• У вас должен быть действующий Makefile, который скомпилирует ваш проект.
• Вы можете использовать только следующие функции: выход, открытие, закрытие, 
запись, чтение, malloc
и бесплатно.
• Вы можете задавать вопросы на форуме.


   **************************************************************************   
   **************************************************************************   
   **************************************************************************   


Grading
Оценивание

BSQ evaluation info :
◦ We’ll start by testing las funcionalidades (out of 10 points). Your program 
must be functional.
◦ If you get all of those 10 points, we’ll then check la optimización of your 
code. Two things will be evaluated here : execution speed (5 points) and memory 
usage (5 points).
      ∗ Those two aspects will be checked only if the first part has been validated.
      ∗ All BSQs that have passed the first part of this evaluation will be competing 
for the two optimisation tests.
      ∗ The best BSQ will be rewarded with all optimisation points.
      ∗ Other BSQs will get extra points depending on how they’re ranked : the faster 
the execution, and/or the the least used memory, the more points it gets; the 
slower the execution and/or the more used memory, the fewer points it gets.
      ∗ TL;DR: Only one group should get all 20 points. You’ll be graded de pending on 
your BSQ’s rank compared to other BSQs.



Информация об оценке BSQ:
◦ Начнем с тестирования las funcionalidades (из 10 баллов). Ваша программа должна 
быть функциональной.
◦ Если вы получите все эти 10 баллов, мы проверим оптимизацию вашего кода. 
Здесь будут оцениваться две вещи: скорость выполнения (5 баллов) и использование 
памяти (5 баллов).
      * Эти два аспекта будут проверены, только если первая часть была проверена.
      * Все BSQ, прошедшие первую часть этой оценки, будут участвовать в двух тестах по 
оптимизации.
      * Лучший BSQ будет вознагражден всеми точками оптимизации.
      * Другие BSQ получат дополнительные очки в зависимости от того, как они 
ранжируются: чем быстрее выполнение и / или чем меньше используется памяти, 
тем больше очков она получает; чем медленнее выполнение и / или чем больше 
используемой памяти, тем меньше очков она получает.
      * TL; DR: только одна группа должна получить все 20 баллов. Вы будете оценены в 
зависимости от ранга вашего BSQ по сравнению с другими BSQ.


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
