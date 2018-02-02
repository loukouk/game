#ifndef GAME_UNIVERSE_H
#define GAME_UNIVERSE_H

#include "chunk.h"
#include "block.h"
#include "player.h"

class Universe{
	Player *player;
	Chunk *origin;
	int spawn_xpos;
	int spawn_ypos;
	int chunk_count;

	public:
		Universe();
		Universe(int x, int y);		//xy coordinates of spawnpoint
		int play();
		Chunk *get_origin();
		Block *get_spawn(int& x, int& y);
		void print_cur_chunk();
		int get_chunk_count();
		int incr_chunk_count();
		int incr_chunk_count(int val);

};

#endif
