Pwn language

1. Introduce
pwn language는 pwnable 플레이어를 위해 제작된 언어입니다.
Python을 기반으로 하며 
내장 연산자로 =, ^(xor), +, -, * 연산을 지원합니다.
또한 분기 및 
floating point는 지원하지 않습니다.

2. Input and Output
간단히 print (variable)을 통해 출력할 수 있습니다. 
또한 int a = input()으로 입력을 받을 수 있습니다.
입력, 출력은 모두 stdin, stdout을 기반으로 합니다.
단, debug모드 일 때는 debug 중인 process의 symbol을 기반으로 출력합니다.

3. Data types
int : 정수형 타입입니다. 사용되는 환경의 Register size와 같은 크기를 가집니다.
*int : 정수형의 주소를 가지는 포인터입니다. 

4. structure
pwn language는 structure를 지원합니다. structure는 여러개의 변수를 묶어 하나의 데이터형 처럼 취급할 수 있습니다.
'.'연산자를 통해 structure의 member에 접근할 수 있습니다.

5. branches and loop
branch인 if문을 제공합니다. if(a == b) 와 같이 사용할 수 있으며 괄호 안의 연산이 참일(1) 경우에만 조건 분기를 실행합니다.
또한 while를 통해 반복을 사용할 수 있습니다. while(a == b)와 같이 괄호 안의 연산이 참이 될 때 까지 반복을 수행합니다.

6. example
아래는 사용자에게 크기를 입력받아 그 횟수만큼 반복을 하는 pwn language 예제입니다.

size = input()
int a = 0
int *arr;

while(a < size){
	a = size;
	*(arr + a) = a;
	a = a + 1;
}
