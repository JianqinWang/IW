#ifndef WATER_H
#define WATER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct block_s
{
	int x;
	int y;
	int height;
	int volume;
	struct block_s *prev;
	struct block_s *next;
} block_t;

#endif
