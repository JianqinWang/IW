#include "water.h"

int main(void)
{
	int array[] = {1, 2, 3, 5,
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

	CalcContainedWater(array, 4, 4);
	CalcContainedWater(array2, 4, 3);
	CalcContainedWater(array3, 3, 3);
	CalcContainedWater(array4, 7, 7);
	return (0);
}
