#include "water.h"

int row_size = 0;
int col_size = 0;
int max = INT_MIN;

int CalcContainedWater(const int *p_data, int num_columns, int num_rows)
{
	int status[num_rows][num_columns];
	int i, j;
	block_t *head;

	head = NULL;
	row_size = num_rows;
	col_size = num_columns;
	memset(status, 0, sizeof(status));
	CreateList(&head, p_data, status);
	for (i = 0; i < row_size; i++)
	{
		for (j = 0; j < col_size; j++)
			printf("%d, ", status[i][j]);
		printf("\n");
	}
	return (1);
}
