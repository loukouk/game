#ifndef GAME_CHUNK_H
#define GAME_CHUNK_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstddef>

#include "block.hpp"


#define CHUNK_SIZE_X 16
#define CHUNK_SIZE_Y 16


typedef std::vector< std::vector<Block *> > matrix;
typedef std::vector<Block *> submatrix;


using std::cout;
using std::endl;

class Chunk {
	matrix blocks;
	matrix create_blocks(int xsz, int ysz);

	public:
		Chunk();
		Block *get_block(int x, int y);
		void assign_ptr(int x, int y, Block *addr);
		void print_chunk();
};


#endif
