#include <stdio.h>

int main()
{
	char c = 'A'; //홑따옴표로 문자를 감쌀 수 있다.
	char d = '*';  

	/*printf("%c %hhd\n", c, c);
	printf("%c %hhd\n", d, d);*/

	//printf("%c \n", c + 1);

	char a = '\a';   // \a or \n과같은 표현들은 하나의 문자처럼 행동
	/*printf("%c", a);*/ // 보통 단순 문자가 아닌 행위를 표현함.(ex. 줄바꿈, 알람..)

	/*printf("\07");*/ //\7
	/*printf("\x23");*/
	//printf("$______");

	//float salary;
	//printf("$______\b\b\b\b\b\b");// \b는 백스페이스. 커서가 그만큼 뒤로감.
	//scanf("%f", &salary);

	printf("abdd\bf\n");
	//printf("AB\tCDEF\n");
	//printf("ABC\tDEF\n");
	// \t은 tap을 뜻함. 출력할때 줄을 맞춰준다.

	//printf("\\ \'HA+\' \"Hello\" \?\n");
	//이미 약속된 기호들을 출력할때 앞에 \붙여준다.
	return 0;
}