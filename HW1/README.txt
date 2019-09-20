Interpreter
- python 내장 모듈인 turtle의 인터프리터입니다. 

0. 공통 요구사항
- python 버전 3 이상이 필요합니다.

1. 실행
	python interpreter.py {input}
 
  - 본 스크립트를 실행 시 명령창을 통해 실행하고자 하는 명령을 입력할 수 있습니다. 
  - Turtle 윈도우의 종료 버튼을 누를 시 종료됩니다. 또는 명령창에 "exit"을 입력하여 종료할 수 있습니다.

  Optional :
  - input : 미리 제작된 input 파일을 제공합니다. input 파일은 아래 명령 구조를 따라야합니다.
 	 여러 줄에 걸쳐 입력해도 동작합니다. 단, 최소 하나의 명령과 숫자가 입력되어야 합니다.

2. 명령 구조

	{instruction} {number}

  - 모든 입력은 명령어를 입력한 후 숫자를 연속해서 입력해야합니다.

  Examples:
	F12R44F45L12F10
            
	위 명령은 python 스크립트의 다음 기능을 수행합니다. 
	
	t = Turtle()
	t.forward(12)
	t.right(44)
	t.forward(45)
	t.left(12)
	t.forward(10)

  - 제공되는 명령은 아래와 같습니다.
 
     F : 앞으로 전진합니다. Turtle의 forward와 같습니다. 이후 입력되는 숫자만큼 전진합니다.
     R : 오른쪽으로 회전합니다. Turtledml right와 같습니다. 이후 입력되는 숫자의 각도로 회전합니다.
     L : 왼쪽으로 회전합니다. Turtle의 left와 같습니다. 이후 입력되는 숫자의 각도로 회전합니다.


Compiler
- python 내장 모듈인 turtle의 컴파일러 입니다.

1. 실행 
	python compiler.py {input}

  - 본 스크립트를 실행 시 명령창을 통해 컴파일 하고자 하는 명령을 입력할 수 있습니다. 
  - Turtle 윈도우의 종료 버튼을 누를 시 종료됩니다. 또는 명령창에 "exit"을 입력하여 종료할 수 있습니다.

  Optional :
  - input : 미리 제작된 input 파일을 제공합니다. input 파일은 아래 명령 구조를 따라야합니다.
 	 여러 줄에 걸쳐 입력해도 동작합니다. 단, 최소 하나의 명령과 숫자가 입력되어야 합니다.
	 Interpreter와는 달리 input 파일의 모든 명령을 컴파일 한 후, 종료합니다.

2. 명령 구조

	{instruction} {number}

  - 모든 입력은 명령어를 입력한 후 숫자를 연속해서 입력해야합니다.

  Examples:
	F12R44F45L12F10
            
	위 명령은 python 스크립트의 다음 기능을 수행하는 스크립트를 제작합니다. 
	
	from turtle import *
	def main():
		t = Turtle()
		t.forward(12)
		t.right(44)
		t.forward(45)
		t.left(12)
		t.forward(10)
	if __name__ == '__main__':
		main()

  - 제공되는 명령은 아래와 같습니다.
 
     F : 앞으로 전진합니다. Turtle의 forward와 같습니다. 이후 입력되는 숫자만큼 전진합니다.
     R : 오른쪽으로 회전합니다. Turtledml right와 같습니다. 이후 입력되는 숫자의 각도로 회전합니다.
     L : 왼쪽으로 회전합니다. Turtle의 left와 같습니다. 이후 입력되는 숫자의 각도로 회전합니다.

3. 컴파일
  - 컴파일은 input 파일을 제공하지 않으면, 명령창에 exit을 입력하여 수행할 수 있습니다.
  - 본 스크립트가 실행된 디렉토리의 a.out.py로 생성됩니다.
