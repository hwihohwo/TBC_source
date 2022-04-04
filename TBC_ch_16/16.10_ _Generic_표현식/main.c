/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

//visual studio에서는 지원해주지 않음. 근데 C11로 바꾸니까 됨.

#include <stdio.h>

/*
    Generic selection expression
    - Generic programming : code is not specific to a particular type

    _Generic : C11 keyword
*/

#define MYTYPE(X) _Generic((X), \
    int : (X + 123), \
    float : "float", \
    double : "double", \
    long : "long", \
    int* : "int*", \
    default: "other"\
)

int main()
{
    int d = 5;

    printf("%d\n", MYTYPE(d));
    printf("%s\n", MYTYPE(2.0 * d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d));

    return 0;
}
