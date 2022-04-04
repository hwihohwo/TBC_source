#include <stdio.h>
#include "MyLibrary.h"
// 릴리즈 모드에서 빌드할때도 설정을 잘 맞춰줘야함.
// 릴리즈/디버그 모드에 따라 헤더 파일은 공통이지만 lib나 dll파일은 다름.
int main()
{
	say_hello();
	say_world();

	return 0;
}