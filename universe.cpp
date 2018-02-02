#include "universe.h"


Universe::Universe() {
	int x, y;

	x = rand() % CHUNK_SIZE_X;
	y = rand() % CHUNK_SIZE_Y;

	origin = new Chunk;
	chunk_count = 1;
	spawn_xpos = x;
	spawn_ypos = y;
	player = new Player(x,y,origin);
}

Universe::Universe(int x, int y)
{
	origin = new Chunk;
	chunk_count = 1;
	spawn_xpos = x;
	spawn_ypos = y;
	player = new Player(x,y,origin);
}

int Universe::play()
{
	return player->play();
}

Chunk *Universe::get_origin()
{
	return origin;
}

Block *Universe::get_spawn(int& x, int& y)
{
	x = spawn_xpos;
	y = spawn_ypos;
}

void Universe::print_cur_chunk()
{
	player->print_chunk();
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
