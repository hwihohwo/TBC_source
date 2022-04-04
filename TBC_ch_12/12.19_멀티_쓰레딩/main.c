#include <stdio.h>
#include <windows.h>

//_Atomic int acnt = 0; //NA

DWORD WINAPI ThreadFunc(void)
{
	int n = 1;
	Sleep(1000);

	//acnt += n;	//NA
	printf("Printing from Thread \n");
	return 0;
}

int main()
{
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	if (thread)
		WaitForSingleObject(thread, INFINITE);
}


//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>		// sleep().
//#include <pthread.h>
//#include <stdatomic.h>
//
//_Atomic int acnt = 0;//	atomic type qualifer (C11)
////여러 쓰레들에서 함부로 변수를 바꾸지 못하도록.
//// A normal C function that i s executed as a thread
//// when its name is specified in pthread_create()
//void* myThreadFun(void* vargp)
//{
//	int n = 1;// thread storage duration
//	for (int j = 0; j < 10; ++j)
//	{
//		sleep(1);
//		acnt += n;	// 일반적인 연산에 비해 느림.
//		printf("Printing from Thread %d %llu\n", acnt, (unsigned long long) & n);
//	}
//
//	return NULL;
//}
//
//int main()
//{
//	pthread_t thread_id1, thread_id2;
//
//	printf("Before Thread\n");
//
//	pthread_create(&thread_id1, NULL, myThreadFun, NULL);
//	pthread_create(&thread_id2, NULL, myThreadFun, NULL);
//
//	pthread_join(thread_id1, NULL);
//	pthread_join(thread_id2, NULL);
//
//	printf("After Thread\n");
//	printf("Atomic %d\n", acnt);
//	return 0;
//}
