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
$ ./expr
-123
= -123
10 + 20
= 30
100/4 + 37 * (42-29)
= 506
```

## Known bug

Ambiguousity of minus unary multiplication with brackets

```
-(1 + 2)
= 1
syntax error
```

if you want to unary minus mutiplication with brackets, you should type like this.
```
- (1 + 2) // be careful whitespace pos
= -3
```

