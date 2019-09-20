from turtle import *
import sys, enum, queue


class Mode(enum.Enum):
    inst = 0
    num = 1
    both = 2

class compiler:
    def __init__(self):
        self.prologue = "from turtle import *\n" \
                        "def main():\n" \
                        "    t = Turtle()\n"
        self.epilogue = "    t.hideturtle()\n" \
                        "    exitonclick()\n" \
                        "if __name__ == '__main__':\n" \
                        "    main()\n"
        self.middle = ''

    def compile(self, ir):
        self.middle += self.prologue
        self.middle += ir
        self.middle += self.epilogue

        fd = open("a.out.py", "w")
        fd.write(self.middle)
        fd.close()

q = queue.Queue()
output = ''
NoneType = type(None)

def goTurtle():
    global q
    ir = ''

    while q.qsize() > 0:
        inst, num = q.queue.pop()

        if inst == "F":
            ir += '    t.forward(' + num + ')\n'
        elif inst == "R":
            ir += '    t.right(' + num + ')\n'
        else:
            ir += '    t.left(' + num + ')\n'

    return ir

def printError(inp, count):
    print("---------------------------------------------------------------------------")
    print("Error position :")
    print("    " + inp)
    print("    " + " " * count + "↑")
    print("---------------------------------------------------------------------------\n")


def parser(inp):
    global q
    q.queue.clear()
    mode = Mode.inst
    cnt = ''
    inst = ''

    str = list(inp)
    leng = len(str)
    for i in range(leng):
        c = str[0]
        str.pop(0)

        if c.isalpha():
            # case 1. Last character is inst or something else
            if (len(str) == 0):
                print('ErrorSyntax error near input ' + c + '. Can\'t find pair number.\n')
                printError(inp, i)
                return

            # case 2. Continuous instructions
            if mode == Mode.num:
                print(
                    'Syntax error near instruction "' + inst + '". Instructions can\'t be continuous. Given input was ' + c + "\n")
                printError(inp, i)
                return

            # Next instruction given. push current instruction to q
            elif mode == Mode.both:
                q.put((inst, cnt))
                cnt = ''
                inst = ''
                mode = Mode.inst

            if c == "F":
                inst = "F"
            elif c == "L":
                inst = "L"
            elif c == "R":
                inst = "R"

            # case 3. can't match any instructions.
            else:
                printError(inp, i)
                print('Syntax error near ' + c + '. Not supported instruction.\n')
                return
            mode = Mode.num

        elif c.isdigit():
            # case 4. First input was number.
            if mode == Mode.inst:
                printError(inp, i)
                print('Syntax error near ' + c + '. No instruction given.\n')
                return

            cnt += c

            if (len(str) == 0):
                q.put((inst, cnt))
            mode = Mode.both
        else:
            # case 5. Can't find such syntax.
            printError(inp, i)
            print('Syntax error near ' + c + '. Invalid input.\n')
            return

    return goTurtle()


def solver():
    result = ''

    # read from file mode
    if len(sys.argv) > 1:
        file = sys.argv[1]
        fd = open(str(sys.argv[1]), 'r')

        while True:
            inp = fd.readline()
            if not inp: break

            tmp = parser(inp)
            if isinstance(tmp, NoneType):
                continue
            result += parser(inp)

        fd.close()

        c = compiler()
        c.compile(result)

    # read from stdin mode
    else:
        while True:
            print("> ", end="")
            inp = input()
            if inp == "exit" :
                c = compiler()
                c.compile(result)
                break

            tmp = parser(inp)
            if isinstance(tmp, NoneType):
                continue
            else:
                result += tmp
                q.queue.clear()


if __name__ == '__main__':
    if (sys.platform == "win32" or sys.platform == "win64"):
        import os, msvcrt
        msvcrt.setmode(sys.stdin.fileno(), os.O_BINARY)
    solver()
