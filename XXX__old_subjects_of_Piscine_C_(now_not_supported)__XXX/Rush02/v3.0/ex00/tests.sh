#!/bin/bash

echo -n "outout   : "
echo "Something" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "o" | ./colle-2
echo "expected : [colle-00] [1] [1] || [square] [1] [1] || [rectangle] [1] [1]"
echo ""

echo -n "outout   : "
echo "o--o" | ./colle-2
echo "expected : [colle-00] [4] [1] || [rectangle] [4] [1]"
echo ""

echo -n "outout   : "
echo "o--0" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "o--o
|  |
o--o" | ./colle-2
echo "expected : [colle-00] [4] [3] || [rectangle [4] [3]"
echo ""

echo -n "outout   : "
echo "o-o
| |
| |
| |
o-o" | ./colle-2
echo "expected : [colle-00] [3] [5] || [rectangle [3] [5]"
echo ""

echo -n "outout   : "
echo "o--o
|  |
|  |
o--o" | ./colle-2
echo "expected : [colle-00] [4] [4] || [square] [4] [4] || [rectangle [4] [4]"
echo ""

echo -n "outout   : "
echo "o--o
| 	|
|  |
o--o" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "o
|
|
o" | ./colle-2
echo "expected : [colle-00] [1] [4] || [rectangle [1] [4]"
echo ""

echo -n "outout   : "
echo "/" | ./colle-2
echo "expected : [colle-01] [1] [1] || [square] [1] [1] || [rectangle] [1] [1]"
echo ""

echo -n "outout   : "
echo "/**\\" | ./colle-2
echo "expected : [colle-01] [4] [1] || [rectangle] [4] [1]"
echo ""

echo -n "outout   : "
echo "/****" | ./colle-2
echo "expected : aucune"
echo ""

#BUG
echo -n "outout   : "
echo "/**\\
*  *
\\**/" | ./colle-2
echo "expected : [colle-01] [4] [3] || [rectangle [4] [3]"
echo ""

echo -n "outout   : "
echo "/*\\
* *
* *
* *
\\*/" | ./colle-2
echo "expected : [colle-01] [3] [5] || [rectangle [3] [5]"
echo ""

echo -n "outout   : "
echo "/**\\
*  *
*  *
\\**/" | ./colle-2
echo "expected : [colle-01] [4] [4] || [square] [4] [4] || [rectangle [4] [4]"
echo ""

echo -n "outout   : "
echo "/**\\
*  *
** *
\\**/" | ./colle-2
echo "expected : aucune"
echo ""

#BUG
echo -n "outout   : "
echo "/
*
*
\\" | ./colle-2
echo "expected : [colle-01] [1] [4] || [rectangle [1] [4]"
echo ""

#BUG
echo -n "outout   : "
echo "A" | ./colle-2
echo "expected : [colle-02] [1] [1] || [colle-03] [1] [1] || [colle-04] [1] [1] || [square] [1] [1] ||[rectangle] [1] [1]"
echo ""

echo -n "outout   : "
echo "B" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "C" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "X" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "AB" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "A
B" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "AA" | ./colle-2
echo "expected : [colle-02] [2] [1] || [rectangle] [2] [1]"
echo ""

echo -n "outout   : "
echo "AC" | ./colle-2
echo "expected : [colle-03] [2] [1] || [colle-04] [2] [1] || [rectangle] [2] [1]"
echo ""

echo -n "outout   : "
echo "A
A" | ./colle-2
echo "expected : [colle-03] [1] [2] || [rectangle] [1] [2]"
echo ""

echo -n "outout   : "
echo "A
C" | ./colle-2
echo "expected : [colle-02] [1] [2] || [colle-04] [1] [2] || [rectangle] [1] [2]"
echo ""

echo -n "outout   : "
echo "ABBC" | ./colle-2
echo "expected : [colle-03] [4] [1] || [colle-04] [4] [1] || [rectangle] [4] [1]"
echo ""

echo -n "outout   : "
echo "ABBA" | ./colle-2
echo "expected : [colle-02] [4] [1] || [rectangle] [4] [1]"
echo ""

echo -n "outout   : "
echo "AA
CC" | ./colle-2
echo "expected : [colle-02] [2] [2] || [square] [2] [2] ||[rectangle] [2] [2]"
echo ""

echo -n "outout   : "
echo "AC
AC" | ./colle-2
echo "expected : [colle-03] [2] [2] || [square] [2] [2] ||[rectangle] [2] [2]"
echo ""

echo -n "outout   : "
echo "AC
CA" | ./colle-2
echo "expected : [colle-04] [2] [2] || [square] [2] [2] ||[rectangle] [2] [2]"
echo ""

echo -n "outout   : "
echo "AA
AA" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo "A
B
B
C" | ./colle-2
echo "expected : [colle-02] [1] [4] || [colle-04] [1] [4] || [rectangle] [1] [4]"
echo ""

echo -n "outout   : "
echo "A
B
B
A" | ./colle-2
echo "expected : [colle-03] [4] [1] || [rectangle] [4] [1]"
echo ""

echo -n "outout   : "
echo "AA
BB
BB
CC" | ./colle-2
echo "expected : [colle-02] [2] [4] || [rectangle] [2] [4]"
echo ""

echo -n "outout   : "
echo "AC
BB
BB
AC" | ./colle-2
echo "expected : [colle-03] [2] [4] || [rectangle] [2] [4]"
echo ""

echo -n "outout   : "
echo "AC
BB
BB
CA" | ./colle-2
echo "expected : [colle-04] [2] [4] || [rectangle] [2] [4]"
echo ""

echo -n "outout   : "
echo "
AC
BB
BB
CA" | ./colle-2
echo "expected : aucune"
echo ""

echo -n "outout   : "
echo -n "" | ./colle-2
echo "expected : aucune"
