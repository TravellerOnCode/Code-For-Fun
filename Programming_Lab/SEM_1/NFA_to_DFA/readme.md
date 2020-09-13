# Programming Nondeterministic Finite Automata

Input:
1. Number of States
2. Transition table for a NFA which is a three column input.
    The columns are separated by blanks.
    First column is the state-label, the second columns
    is a set of comma separated values indicating target states on input 0
    Like wise the third column is for input 1
3. This table is followed by binary strings, one per line

Task:
Build NFA and using dynamic subset construction technique report whether the input binary strings belong to the language of the Automation or not
Perform the binary strings recognition using the DFA constructed from NFA using subject construction technique.
Compare the performance of both.

Eg.,
4
1    2,4    2
2    3       1
3    4       1
4    0        0
10101010100010101010001
11100011001001010010010
1010100010
10010
0
1