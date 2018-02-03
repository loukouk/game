#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <cstring>

#include "block.hpp"
#include "chunk.hpp"
#include "universe.hpp"

class Player : public Block{
	Universe *u;
	Chunk *cur_chunk;
	int chunk_xpos;
	int chunk_ypos;
	int block_xpos;
	int block_ypos;
	int inventory[NUM_BLOCK_TYPES];
	int move(int direction);
	int move_to(Chunk *ch, int x, int y);
	int get_xpos();
	int get_ypos();

	public:
		Player(Universe *u);
		int play();
		void print_chunk();
		int add_to_inventory(int item, int amount);
};

#endif
