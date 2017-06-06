#include "water.h"

int row_size = 0;
int col_size = 0;
int max = 0;

int CalcContainedWater(const int *p_data, int num_columns, int num_rows)
{
	int status[num_rows][num_columns];
	int total_volume;
	block_t *head, *min;

	head = NULL;
	row_size = num_rows;
	col_size = num_columns;
	max = INT_MIN;
	total_volume = 0;
	memset(status, 0, sizeof(status));
	CreateList(&head, p_data, status);
	while (head != NULL)
	{
		min = RemoveMin(&head);
		if (min->height >= max)
			max = min->height;
		CheckNeighbor(&head, p_data, status, min->x + 1, min->y);
		CheckNeighbor(&head, p_data, status, min->x, min->y + 1);
		CheckNeighbor(&head, p_data, status, min->x - 1, min->y);
		CheckNeighbor(&head, p_data, status, min->x, min->y - 1);
		//printf("volume is %d\n", min->volume);
		total_volume += min->volume;
		free(min);
	}
	//printf("total volume is %d\n", total_volume);
	return (total_volume);
}

void CheckNeighbor(block_t **head, const int *p_data, int (*status)[col_size],
		   int x, int y)
{
	if (x < 0 || x >= row_size)
		return;
	if (y < 0 || y >= col_size)
		return;
	if (status[x][y] == 1)
		return;
	status[x][y] = 1;
	AddNode(head, p_data, x, y, x * col_size + y);
}
