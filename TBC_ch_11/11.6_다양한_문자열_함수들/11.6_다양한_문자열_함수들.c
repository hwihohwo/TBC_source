#include <stdio.h>
#include <string.h>

void fit_str(char*, unsigned int);
void my_strcat(char* str, const char* str2);
int my_strcmp(const char* str1, const char* str2);

int main()
{
	/*strlen() : returns length of the string*/

	//char msg[] = "Just,"" do it!";
	//puts(msg);
	//printf("Length %zd\n", strlen(msg));
	//fit_str(msg, 4);
	//puts(msg);
	//printf("Length %zd\n", strlen(msg));

	/*strcat() and strncat() : string concatenation*/
	//concatenation : 연쇄, 연속

	//char str1[100] = "First string";
	//char str2[] = "Second string";

	////strcat(str1, ", ");
	////strcat(str1, str2);
	////strncat(str1, str2, 2);	// Append 2 characters
	////puts(str1);
	//my_strcat(str1, str2);
	//puts(str1);

	/*strcmp() and strncmp() : compare strings (not characters)*/
	//앞의 string이 크면 양수, 둘이 완전히 같으면0, 뒤가 더 크면 음수를 return

	//printf("%d\n", strcmp("A", "A"));
	//printf("%d\n", strcmp("A", "B"));
	//printf("%d\n", strcmp("B", "A"));
	//printf("%d\n", strcmp("Hello", "Hello"));
	//printf("%d\n", strcmp("Banana", "Bananas"));
	//printf("%d\n", strcmp("Bananas", "Banana"));
	//printf("%d\n", strncmp("Bananas", "Banana", 6));

	printf("%d\n", my_strcmp("Hello", "Hello"));
	printf("%d\n", my_strcmp("Banana", "Bananas"));
	printf("%d\n", my_strcmp("Bananas", "Banana"));

	/*strcpy() and strncpy()*/

	//char dest[100] = "";	// make sure memory is enough
	//char source[] = "Start programming!";
	////dest = source;					// Error
	////dest[100] = "Start something";	// Error	//배열의 선언이 끝나면 배열을 한꺼번에 초기화 할 수  없다.
	//strcpy(dest, source);
	//strncpy(dest, source, 5);			//'\0' is NOT added
	//strcpy(dest, source + 6);
	//strcpy(dest, source);
	//strcpy(dest + 6, "coding!");
	//puts(dest);

	/*sprintf()*/
	//printf의 출력값을 문자열에 저장해 주는 함수.
	//char str[100] = "";
	//int i = 123;
	//double d = 3.14;
	//sprintf(str, "%05d.png %f", i, d);
	//puts(str);

	/*There are more functions...*/

	printf("%s\n", strchr("Hello, World", 'W'));

	printf("%s\n", strpbrk("Hello, World", "ABCDE"));
	printf("%s\n", strpbrk("Hello, World", "abcde"));

	printf("%s\n", strrchr("Hello, World, Hello, World", 'l'));// last occurrence

	printf("%s\n", strstr("Hello, World", "wor"));
	printf("%s\n", strstr("Hello, World", "Wor"));

	return 0;
}

void fit_str(char* str, unsigned int size)
{
	if (strlen(str) > size)
		str[size] = '\0';
}

void my_strcat(char* str, const char* str2)
{
	while (*str != '\0')
		str++;
	if (*str == '\0')
	{
		while (*str2 != '\0')
		{
			*str++ = *str2++;
		}
		*str = '\0';	// null terminate destination string
	}
}

//// Function to implement `strcat()` function in C
//char* my_strcat(char* destination, const char* source)
//{
//	// make `ptr` point to the end of the destination string
//	char* ptr = destination + strlen(destination);
//
//	// appends characters of the source to the destination string
//	while (*source != '\0') {
//		*ptr++ = *source++;
//	}
//
//	// null terminate destination string
//	*ptr = '\0';
//
//	// the destination is returned by standard `strcat()`
//	return destination;
//}

//// Function to implement `strcat()` function in C
//char* my_strcat(char* destination, const char* source)
//{
//	int i, j;
//
//	// move to the end of the destination string
//	for (i = 0; destination[i] != '\0'; i++);
//
//	// `i` now point to terminating null character in the destination
//
//	// Appends characters of the source to the destination string
//	for (j = 0; source[j] != '\0'; j++) {
//		destination[i + j] = source[j];
//	}
//
//	// null terminate destination string
//	destination[i + j] = '\0';
//
//	// the destination is returned by standard `strcat()`
//	return destination;
//}

int my_strcmp(const char* str1, const char* str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}