# AK Laboratory Work 5
 [![MIT License](https://img.shields.io/pypi/l/aiogram.svg?style=flat-square)](https://opensource.org/licenses/MIT)
 <br>
Main.cpp contains implementation of one layer perceptron with only two weights and one bias. Output of executable is steps of perceptron training.
Getopt/getopt_long instructions could be found [here](https://www.ibm.com/developerworks/ru/library/au-unix-getopt/index.html).
<br>
List of valid keys:
+ -h, --help, no arguments required;
+ -c, --cycles, arguments required in range (2, 4);
+ -t, --target, arguments optional list of 4 integers of 0's and 1's;
+ -l, --learning-rate, arguments optional, one positive integer, the little the better;<br>
### Commands for assembly<br>
`$ git clone https://github.com/chyzhyk16/AK_LW5.git`
<br>
`$ cmake ~/AK-LW5`
<br>
### Usage examples<br>
`$ ./main`
<br>
`$ ./main -h`
<br>
`$ ./main --help`
<br>
`$ ./main --cycles=4`
<br>
`$ ./main --cycles=3 --training-rate=1`
<br>
`$ ./main --cycles=2 --training-rate=2 --target=0,1,1,1`
<br>
`$ ./main -c 2 -l 2 --target=0,1,1,1`
<br>
`$ ./main --cycles=2 -t 0,1,1,1`
<br>
### Handling wrong keys<br>
`$ ./main -r --verbose`
<br>
`./main: invalid option -- 'r'`
<br>
`./main: unrecognized option '--verbose'`
