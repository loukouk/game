#ifndef GAME_CHUNK_H
#define GAME_CHUNK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstddef>

#include "block.h"


#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16

//terraria-like 2d game where abunch of blocks spawn random
//subclasses: solid liquid gas blocks
//solids hard, but can collapse
//liquid fall but volume is constant
//gas expands to take all open volume but loses effectiveness
//player must reach gold avoiding dying suffocation/drowning/collapse to win


typedef std::vector< std::vector<Block *> > matrix;
typedef std::vector<Block *> submatrix;


using std::cout;
using std::endl;

class Chunk {
	int xpos;
	int ypos;
	Chunk * top;
	Chunk * bot;
	Chunk * left;
	Chunk * right;
	matrix blocks;
	matrix create_blocks(int xsz, int ysz);

	public:
		Chunk();
		Chunk(int x, int y);
		Chunk(int x, int y, Chunk *t, Chunk *b, Chunk *l, Chunk *r);
		~Chunk();
		Block *get_block(int x, int y);
		void assign_ptr(int x, int y, Block *addr);
		void print_chunk();
		void set_xpos(int x);
		void set_ypos(int y);
		void set_top(Chunk *addr);
		void set_bot(Chunk *addr);
		void set_left(Chunk *addr);
		void set_right(Chunk *addr);
		int get_xpos();
		int get_ypos();
		Chunk *get_top();
		Chunk *get_bot();
		Chunk *get_left();
		Chunk *get_right();
};


#endif
