#include <stdio.h>

int main()
{
	FILE* fp;
	int ch;

	///* ungetc() */
	//fp = fopen("input.txt", "r");

	//ch = fgetc(fp);
	//fputc(ch, stdout);

	//ungetc((int)'A', fp);		//try another characters

	//ch = fgetc(fp);
	//fputc(ch, stdout);

	//ch = fgetc(fp);
	//fputc(ch, stdout);

	//fclose(fp);

	/* setvbuf() */

	fp = fopen("input.txt", "r");

	char buffer[32] = { '\0', };

	setvbuf(fp, buffer, _IOFBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF
	//buffer를 버퍼로 사용하게 하는 함수.

	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%hhd", buffer[i]);
	printf("\n");

	ch = fgetc(fp);	// Read just only a single character!
	//buffer는 프로그램이 파일에서 계속 읽어들일 것으로 예상이 되면 미리 읽어 들인다.
	//buffer로부터 가져오는 것이 더 빠르기 때문에 미리 채워두는 것.
	
	//dump buffer
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n");

	fclose(fp);

	/* fflush() */

	// Writing a large amount of data
	// fflush(fp);
	// buffer가 빌때까지 전부 다 처리하도록 하는 함수.

	return 0;
}