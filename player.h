#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <cstring>

#include "block.h"
#include "chunk.h"


class Player : public Block{
	Chunk *cur_chunk;
	int xpos;
	int ypos;
	int inventory[NUM_BLOCK_TYPES];
	int move(int direction);
	int move_to(Chunk *ch, int x, int y);
	int get_xpos();
	int get_ypos();

	public:
		Player();
		Player(int x, int y, Chunk *cur);
		int play();
		void print_chunk();
		int add_to_inventory(int item, int amount);
};

#endif
