#include "universe.hpp"
#include <iostream>

Universe::Universe() {
	int x, y;

	x = rand() % CHUNK_SIZE_X;
	y = rand() % CHUNK_SIZE_Y;

	chunkmap = new DoubleVector< DoubleVector<Chunk *> >;
	(*chunkmap)[0][0] = new Chunk;
	chunk_count = 1;
	spawn_xpos = x;
	spawn_ypos = y;
}

Universe::Universe(int x, int y)
{
	chunkmap = new DoubleVector< DoubleVector<Chunk *> >;
	(*chunkmap)[0][0] = new Chunk;
	chunk_count = 1;
	spawn_xpos = x;
	spawn_ypos = y;
}

Chunk *Universe::get_chunk(int x, int y)
{
	Chunk *ret = (*chunkmap)[x][y];
	if (ret == 0) {
		ret = new Chunk;
		(*chunkmap)[x][y] = ret;
	}
	return ret;
}

Block *Universe::get_spawn(int& x, int& y)
{
	x = spawn_xpos;
	y = spawn_ypos;
	return ((*chunkmap)[0][0]->get_block(x,y));
}

int Universe::get_chunk_count()
{
	return chunk_count;
}

int Universe::incr_chunk_count()
{
	chunk_count++;
}

int Universe::incr_chunk_count(int val)
{
	chunk_count += val;	
}
