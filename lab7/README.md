CS104 Lab 7 Code Base                         {#mainpage}
======================

###Build
type `make` to build the program.

###Run
To run the program type `./ListGame <sequence>`.

###Test
To run all tests, type `make tests`.

The ListGame:
Enter a set of characters to represent animals and food.
You can type 'M' or 'L' for monkey or lion.  Animals that enter the queue will stay there until fed their favorite food.
Monkeys like 'B' bananas and lions like 'S' steaks.  
If you give them their favorite food, they will leave the queue and give you a point.
If you give them the wrong food, they will stay in the queue and you will lose a point.
If you waste food by giving it to an empty queue, you'll lose a point.
If animals are still in the queue that are unfed, you lose nothing.

Examples:
MMLBS = -1 points
State of queue at end: ML

MBLS = 2 points
State of queue at end:

LBSMBB = 0 points
State of queue at end: