## About

Simple calculator supports arithmetic.
Surpports +, -, *, / and brackets
all arithmetics left associative except brackets.

## How to install and Compile ?

Makefile included. you can make binary just run make.
```
sudo apt install bison flex gcc git -y
make
```
## How can i calculate?

```
$ ./a
1 + 2
= 3
10 + 20
= 30
100/4 + 37 * (42-29)
= 509
```

## Known bug

Ambiguousity of minus multiplication with brackets

```
-(1 + 2)
= 1
syntax error
```
