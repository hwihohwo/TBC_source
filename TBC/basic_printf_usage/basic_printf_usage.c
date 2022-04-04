#include <stdio.h>//전처리기

int main()
{
	
	printf("The truth is ...\nI am Ironman.\n");
	// 'f'가 붙어있다. 함수를 볼때 '입력'이 뭔지 '출력'이 뭔지 생각하면 좋다.
	// escape sequence \n 의미를 살펴보면 줄을 바꾼다는 행위로 인식함.
	// ""안의 내용은 문자열로 인식함.
	printf("\"The truth is ... Ironman.\n\"");
	// "와 같이 의미를 가진 문자를 출력하고 싶을때는 그 앞에 \(백슬래시)를 붙인다.
	// print formatted 줄여서 printf.
	int x, y, z;
	x = 1;
	y = 2;

	z = x + y;

	printf("The answer is %i.\n", z);//%i, %d 둘다 printf에서는 똑같이 작동함.
	// i는 integer, d는 decimal의 약자
	printf("%i + %i = %i", x, y, z);// 순서대로 들어간다.
	printf("\a");//출력시 경고음(알람)이 나옴.즉, 소리도 출력됨.
	/*주석 블럭을 작성할때
	는 슬래시와 별을 
	활용함. 최근에는 저작권등을 표시할때 많이 사용함.*/
	return 0;
}