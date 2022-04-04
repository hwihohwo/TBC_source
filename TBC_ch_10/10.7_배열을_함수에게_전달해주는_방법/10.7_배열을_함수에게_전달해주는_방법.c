#include <stdio.h>

double average(double data_array[], int n);
//double average(double *data_array, int n);
//double average(double *, int n);
//double average(double [], int n);
//위 방법 모두 prototype으로 가능.(body와 형식은 맞춰줘야함.)



int main()
{
	double arr1[5] = { 10, 13, 12, 7, 8 };
	//double arr2[5] = { 1.8, -0.2, 6.3, 13.9, 20.5 };
	double arr2[3] = {1.8, -0.2, 6.3 };	//size is different

	printf("Address = %p\n", arr1);
	printf("Size = %zd\n", sizeof(arr1));
	printf("Address = %p\n", arr2);
	printf("Size = %zd\n", sizeof(arr2));

	printf("Avg = %f\n", average(arr1, 5));
	printf("Avg = %f\n", average(arr2, 3));

	return 0;
}

double average(double data_array[], int n)	//함수에서 배열을 받을때는 사실 배열을 직접 받는게 아닌
{										//포인터를 받음.
	printf("Size = %zd in function average\n", sizeof(data_array));

	double avg = 0.0;
	for (int i = 0; i < n; ++i)
	{
		avg += data_array[i];
	}
	avg /= (double)n;

	return avg;
}
// 첫 주소와 배열의 원소 수를 따로 받아준다.