1. Introduce
사칙연산을 Abstract Syntax Tree로 전환하는 프로그램입니다. + - / * 4개의 연산과 - Unary연산, 그리고 괄호까지 지원합니다.
연산의 순서는 정수 사칙연산과 동일하며 입력은 정수, 그리고 영문자만 가능합니다

2. Usage
우선 컴파일된 바이너리 생성을 위해서 다음을 입력하세요
	make
이후 ast라는 이름으로 생성된 바이너리를 실행하시면 됩니다.

입력 예시는 다음과 같습니다
	1+2*(1+2)
	3+x/(4+-y)+2

3. Grammar
본 AST Generator가 사용하는 문법은 다음과 같습니다
	
	P -> E EOF
	E -> E + E | E - E | -E | T
	T -> T * T | T / T | F
	F -> ( E ) | number | STRING
	number -> [0-9]+
	STRING -> [a-zA-Z]+


