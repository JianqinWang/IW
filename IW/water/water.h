#ifndef WATER_H
#define WATER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

typedef struct block_s
{
	int x;
	int y;
	int height;
	int volume;
	struct block_s *prev;
	struct block_s *next;
} block_t;

extern int row_size;
extern int col_size;
extern int max;

/* in container.c */
int CalcContainedWater(const int *p_data, int num_columns, int num_rows);

/* in linkedlists.c */
block_t *NewNode(const int *p_data, int row, int col, int idx);
block_t *AddNode(block_t **head, const int *p_data, int row, int col, int idx);
block_t *CreateList(block_t **head, const int *p_data, int (*status)[col_size]);

#endif
