#include "water.h"

block_t *NewNode(const int *p_data, int row, int col, int idx)
{
	block_t *new_node;

	new_node = malloc(sizeof(block_t));
	if (new_node == NULL)
		return (NULL);
	new_node->x = row;
	new_node->y = col;
	new_node->height = p_data[idx];
	if (max != INT_MIN)
		new_node->volume = max - new_node->height;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

block_t *AddNode(block_t **head, const int *p_data, int row, int col, int idx)
{
	block_t *temp, *new_node;

	new_node = NewNode(p_data, row, col, idx);

}

block_t *CreateList(block_t **head, const int *p_data)
{
	int x, y, idx;

	for (x = 0; x < row_size; x++)
	{
		for (y = 0; y < col_size; j++)
		{
			if ((x == 0 || x == row_size - 1) ||
			    (y == 0 || y == col_size - 1))
			{
				idx = x * col_size + y;
				AddNode(head, p_data, x, y, idx);
			}
		}
	}
}
