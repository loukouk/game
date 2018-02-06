#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include <iostream>
#include <cstring>
#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <limits>

#include "block.hpp"
#include "chunk.hpp"
#include "universe.hpp"

#define INPUT_TIMEOUT_S 1
#define INPUT_TIMEOUT_NS 100000000UL

using namespace std;

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
		int play_real_time();
		void print_chunk();
		int add_to_inventory(int item, int amount);
};

#endif
