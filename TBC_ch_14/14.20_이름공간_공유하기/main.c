#include <stdio.h>

int iamfunction()
{
	return 0;
}

//int a = 123;

int main()
{
	/*
		namespace
		- Identify parts of a program in which a name is recognized
		- You can use the same name for one variable and one tag.
		- C++: use 'namespace' to use the same identifiers in the duplicated scopes.
	*/

	{
		int myname = 345;
		//double myname = 3.14;//ERROR
	}

	struct rect { double x; double y; };

	//int rect = 123;	// OK in C (NOT OK in C ++)
	struct rect rect = { 1.1, 2.2 };// struct rect and rect are in different categories

	/*
	typedef struct rect rect;
	rect rect = { 1.1, 2.2 };//Not OK
	*/

	//int iamfunction = iamfunction();//ERROR

	/*
		Namespace pollution (KNK p.465)
		- Names in different files accidentally conflicting with each other
	*/

	//name scope를 가급적 작게 해둬야 변수명을 다시 쓸 수 있다.

	//printf("%d\n", a);// other.c

	return 0;
}