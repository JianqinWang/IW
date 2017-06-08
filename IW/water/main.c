#include "water.h"

/**
 * main - main function that is used to test input
 * Return: 0 for success;
 */
int main(void)
{
	int array1[] = {1, 2, 3, 5,
		       7, 12, 34, 1,
		       11, 9, 81, 2,
		       15, 1, 1, 2};
	int array2[] = {1, 1, 1, 1,
			1, 0, 0, 1,
			1, 1, 1, 1};
	int array3[] = {1, 0, 1,
			1, 0, 1,
			1, 1, 1};
	int array4[] = {3, 10, 8, 12, 2, 7, 9,
			7, 1, 11, 3, 8, 1, 10,
			9, 7, 3, 10, 2, 5, 6,
			7, 11, 1, 4, 6, 11, 9,
			4, 5, 8, 12, 3, 4, 2,
			12, 2, 12, 1, 5, 9, 6,
			6, 5, 8, 12, 4, 11, 10};
	int array5[] = {0, 1, 0,
			1, 0, 1,
			0, 1, 0};
	int array6[] = {1, 4, 3, 1, 3, 2,
			3, 2, 1, 3, 2, 4,
			2, 3, 3, 2, 3, 1};
	int i;

	i = CalcContainedWater(array1, 4, 4);
	printf("array1 holds volume %d\n", i);
	i = CalcContainedWater(array2, 4, 3);
	printf("array2 holds volume %d\n", i);
	i = CalcContainedWater(array3, 3, 3);
	printf("array3 holds volume %d\n", i);
	i = CalcContainedWater(array4, 7, 7);
	printf("array4 holds volume %d\n", i);
	i = CalcContainedWater(array5, 3, 3);
	printf("array5 holds volume %d\n", i);
	i = CalcContainedWater(array6, 6, 3);
	printf("array6 holds volume %d\n", i);
	return (0);
}
