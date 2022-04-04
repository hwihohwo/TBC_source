#include <stdio.h>
#include <stdlib.h> // exit()

int main()
{
	int c;
	FILE *file = NULL;
	char file_name[] = "my_file.txt"; //TODO: use scanf(...)
	
	file = fopen(file_name, "r"); 
	//"r"은 read의 약자. file에 저장되어있는 data를 읽어들이여 할때 사용.
	//반대로 저장하려고 한다면 "w"를 사용하면 적을 수 있는 mode로 열 수 있음.
	if (file == NULL)
	{
		printf("Failed to open file.\n");
		exit(1);
	}

	while ((c = getc(file)) != EOF)
		putchar(c);
	fclose(file);	//file stream을 닫아주어야함. 운영체제에서 다른 프로그램도 해당 파일접근 할 수도.

	return 0;
}

