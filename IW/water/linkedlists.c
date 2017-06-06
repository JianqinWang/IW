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
	if (max == INT_MIN || new_node->height > max)
	{
		new_node->volume = 0;
	}
	else
	{
		new_node->volume = max - new_node->height;
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

block_t *AddNode(block_t **head, const int *p_data, int row, int col, int idx)
{
	block_t *temp, *new_node;

	if (head == NULL)
		return (NULL);
	new_node = NewNode(p_data, row, col, idx);
	temp = *head;
	if (temp == NULL)
	{
		*head = new_node;
		return (new_node);
	}
	if (temp != NULL && temp->height > new_node->height)
	{
		new_node->next = temp;
		temp->prev = new_node;
		*head = new_node;
		return (new_node);
	}
	while (temp != NULL)
	{
		if (temp->height <= new_node->height)
		{
			if (temp->next == NULL)
			{
				temp->next = new_node;
				new_node->prev = temp;
				break;
			}
		}
		else
		{
			new_node->next = temp;
			new_node->prev = temp->prev;
			temp->prev->next = new_node;
			temp->prev = new_node;
			break;
		}
		temp = temp->next;
	}
	return (new_node);
}

void CreateList(block_t **head, const int *p_data, int (*status)[col_size])
{
	int x, y, idx;

	for (x = 0; x < row_size; x++)
	{
		for (y = 0; y < col_size; y++)
		{
			if ((x == 0 || x == row_size - 1) ||
			    (y == 0 || y == col_size - 1))
			{
				//printf("Position at %d, %d\n", x, y);
				idx = x * col_size + y;
				status[x][y] = 1;
				AddNode(head, p_data, x, y, idx);
			}
		}
	}
}

block_t *RemoveMin(block_t **head)
{
	block_t *temp, *min;

	if (head == NULL)
		return (NULL);
	min = *head;
	if (min == NULL)
		return (NULL);
	temp = min->next;
	if (temp != NULL)
		temp->prev = NULL;
	*head = temp;
	min->next = NULL;
	return (min);
}
