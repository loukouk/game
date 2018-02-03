#ifndef GAME_UNIVERSE_H
#define GAME_UNIVERSE_H

#include "chunk.hpp"
#include "block.hpp"
#include "double_vec.hpp"

class Universe{
	DoubleVector< DoubleVector<Chunk *> > *chunkmap;
	int spawn_xpos;
	int spawn_ypos;
	int chunk_count;

	public:
		Universe();
		Universe(int x, int y);		//xy coordinates of spawnpoint
		Chunk *get_chunk(int x, int y);
		Block *get_spawn(int& x, int& y);
		void print_cur_chunk();
		int get_chunk_count();
		int incr_chunk_count();
		int incr_chunk_count(int val);

};

#endif
