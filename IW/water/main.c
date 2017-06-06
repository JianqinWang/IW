#include "water.h"

int main(void)
{
	int array[] = {1, 2, 3, 5,
		       7, 12, 34, 1,
		       11, 9, 81, 2,
		       15, 1, 1, 2};

	CalcContainedWater(array, 4, 4);
	return (0);
}
