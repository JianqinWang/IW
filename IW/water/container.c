#include <water.h>

int row_size = 0;
int col_size = 0;
int max = INT_MIN;

int CalcContainedWater( const int *p_data, int num_columns, int num_rows)
{
	int status[num_rows][num_columns];
	int x, y, index;
	block_t *head;

	head = NULL;
	row_size = num_rows;
	col_size = num_columns;
	CreateList(&head, p_data);
}
