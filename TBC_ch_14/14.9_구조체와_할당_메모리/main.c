#include <stdio.h>
#include <string.h>	// strlen(), strcmp()
#include <stdlib.h> // malloc(), free()
#define SLEN 81

struct namect {
	char* fname;	// Use malloc()
	char* lname;	// Use malloc()
	int letters;
};

void getinfo(struct namect*);		// allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);		// free memory when done
//char* s_get(char* st, int n);

int main()
{
	/*
		Dangerous usage
	*/

	//struct namect p = { "Jeong-Mo", "Hong" };
	//printf("%s %s\n", p.fname, p.lname);

	////int f1 = scanf("%[%\n]%*c", p.lname);	// read only 인 text segment에 저장된 object를 변경하려함. 런타임 에러 발생
	////printf("%s %s\n", p.lname, p.fname);

	///*
	//	Recommended usage
	//*/

	//char buffer[SLEN] = { 0, };
	//int f2 = scanf("%[^\n]&*c", buffer);
	//p.fname = (char*)malloc(strlen(buffer) + 1);	// NULL character들어갈 자리 1개
	//if (p.fname != NULL)
	//	strcpy(p.fname, buffer);
	//printf("%s %s\n", p.fname, p.lname);

	/* Problem */
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

void getinfo(struct namect* ptr_nct)
{
	char temp[SLEN] = { 0, };
	int flag;

	printf("Input your first name:\n>>");

	flag = scanf("%[^\n]%*c", temp);
	if (flag != 1)
		printf("Wrong input");
	else
	{
		ptr_nct->fname = (char*)malloc(strlen(temp) + 1);// +1 is for '\0'
		//sizeof(char) * 부분이 없는이유 : char의 size가 1이기 때문
		if (ptr_nct->fname != NULL)
			strcpy(ptr_nct->fname, temp);
		else
			printf("Malloc() failed");
	}
	printf("Input your last name:\n>>");

	flag = scanf("%[^\n]%*c", temp);

	if (flag != 1)
		printf("Wrong input");
	else
	{
		ptr_nct->lname = (char*)malloc(strlen(temp) + 1);

		if (ptr_nct->lname != NULL)
			strcpy(ptr_nct->lname, temp);
		else
			printf("Malloc() failed");
	}
}

void makeinfo(struct namect* ptr_nct)
{
	ptr_nct->letters = (int)strlen(ptr_nct->fname) + (int)strlen(ptr_nct->lname);
}

void showinfo(const struct namect* ptr_nct)
{
	printf("Hi, %s %s. Your name has %d characters.",
		ptr_nct->fname, ptr_nct->lname, ptr_nct->letters);
}

void cleanup(struct namect* ptr_nct)
{
	free(ptr_nct->fname);
	free(ptr_nct->lname);
}