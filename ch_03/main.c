#include <stdio.h>

int main()
{
	int arr[] = {19, 2, 25, 92, 36, 45};

	int max;

	int min;

	for(int i = 0 ; i<sizeof(arr) / sizeof(int) ; i++){
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	return 0;
}

