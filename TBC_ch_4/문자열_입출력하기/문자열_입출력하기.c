#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char fruit_name[40]; // stores only one character.
	//[40]를 붙이면 char타입 1바이트짜리 40개를 확보할 수 있다.
	printf("What is your favorite fruit?\n");

	scanf("%s", fruit_name); // be careful with &
	//string의 약자 s로 %s를 씀. 그리고 &를 쓰지 않는다.
	//이유는 fruit_name자체가 이미 주소이기 때문.
	printf("You like %s!\n", fruit_name);

	return 0;
}