#ifndef WATER_H
#define WATER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct block_s - a structure to hold all info on a data point in matrix
 * @x: row that the value 'height' is from
 * @y: column that the value 'height' is from
 * @height: the value at x, y in the given matrix
 * @volume: the volume of water that is held at the data point in the matrix
 * @prev: previous node in linked list
 * @next: next node in linked list
 */
typedef struct block_s
{
	int x;
	int y;
	int height;
	int volume;
	struct block_s *prev;
	struct block_s *next;
} block_t;

/**
 * 3 global variables
 * row_size: the number of rows in the matrix, as input in function CalcContainedWater
 * col_size: the number of columns in the matrix, as input in function CalcContainedWater
 * max: the max height of water relative to the 'barrier' (the linked list)
 */
extern int row_size;
extern int col_size;
extern int max;

/* in container.c */
int CalcContainedWater(const int *p_data, int num_columns, int num_rows);
void CheckNeighbor(block_t **head, const int *p_data, int (*status)[col_size],
		   int x, int y);

/* in linkedlists.c */
block_t *NewNode(const int *p_data, int row, int col, int idx);
block_t *AddNode(block_t **head, const int *p_data, int row, int col, int idx);
void CreateList(block_t **head, const int *p_data, int (*status)[col_size]);
block_t *RemoveMin(block_t **head);
#endif
