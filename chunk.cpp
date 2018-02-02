#include "chunk.h"

matrix Chunk::create_blocks(int xsz, int ysz)
{
	matrix blocks_matrix(xsz, submatrix(ysz));
	int id;

	for (matrix::iterator it0 = blocks_matrix.begin(); it0 != blocks_matrix.end(); ++it0) {
		for (submatrix::iterator it1 = it0->begin(); it1 != it0->end(); ++it1) {
			id = rand() % NUM_BLOCK_TYPES;
			if (IS_SOLID(id))
				*it1 = new Solid(id);
			else if (IS_LIQUID(id))
				*it1 = new Liquid(id);
			else if (IS_GAS(id))
				*it1 = new Gas(id);
			else *it1 = nullptr;
		}
	}

	return blocks_matrix;	
}

Chunk::Chunk()
{
	xpos = 0;
	ypos = 0;
	top = nullptr;
	bot = nullptr;
	left = nullptr;
	right = nullptr;
	blocks = create_blocks(CHUNK_SIZE_X, CHUNK_SIZE_Y);
}

Chunk::Chunk(int x, int y)
{
	xpos = x;
	ypos = y;
	top = nullptr;
	bot = nullptr;
	left = nullptr;
	right = nullptr;
	blocks = create_blocks(CHUNK_SIZE_X, CHUNK_SIZE_Y);
}

Chunk::Chunk(int x, int y, Chunk *t, Chunk *b, Chunk *l, Chunk *r)
{
	xpos = x;
	ypos = y;
	set_top(t);
	set_bot(b);
	set_left(l);
	set_right(r);
	blocks = create_blocks(CHUNK_SIZE_X, CHUNK_SIZE_Y);
}

Chunk::~Chunk()
{
	if (top != nullptr) top->bot = nullptr;
	if (bot != nullptr) bot->top = nullptr;
	if (left != nullptr) left->right = nullptr;
	if (right != nullptr) right->left = nullptr;
}

Block *Chunk::get_block(int x, int y)
{
	return blocks[x][y];
}

void Chunk::assign_ptr(int x, int y, Block *addr)
{
	blocks[x][y] = addr;
}

void Chunk::print_chunk()
{
//	for (std::vector<Block *> v : blocks) {
//		for (Block *b : v) {
//			cout << b->get_xpos() << "," << b->get_ypos() << endl;
//		}
//	}

//	for (matrix::iterator it0 = blocks.begin(); it0 != blocks.end(); ++it0) {
//		for (submatrix::reverse_iterator it1 = it0->rbegin(); it1 != it0->rend(); ++it1)
//			cout << (*it1)->get_xpos() << "," << (*it1)->get_ypos() << "\t";
//		cout << endl;
//	}

	submatrix::reverse_iterator *it = new submatrix::reverse_iterator[blocks.size()];
	int ind = 0;

	for (matrix::iterator itx = blocks.begin(); itx != blocks.end(); ++itx, ind++) {
		it[ind] = itx->rbegin();
	}

	for(unsigned int j = 0; j < blocks.begin()->size(); j++) {
		for (unsigned int i = 0 ; i < blocks.size(); i++) {
			cout << (*(it[i]))->get_id() << "\t";
			it[i]++;
		}
		cout << endl;
	}
}

void Chunk::set_xpos(int x) 
{
	xpos = x;
}

void Chunk::set_ypos(int y) 
{
	ypos = y;
}

void Chunk::set_top(Chunk *addr) 
{
	top = addr;
	if (addr != nullptr) addr->bot = this;
}

void Chunk::set_bot(Chunk *addr) 
{
	bot = addr;
	if (addr != nullptr) addr->top = this;
}

void Chunk::set_left(Chunk *addr) 
{
	left = addr;
	if (addr != nullptr) addr->right = this;
}

void Chunk::set_right(Chunk *addr) 
{
	right = addr;
	if (addr != nullptr) addr->left = this;
}

int Chunk::get_xpos() 
{
	return xpos;
}

int Chunk::get_ypos() 
{
	return ypos;
}

Chunk *Chunk::get_top() 
{
	if (top == nullptr) {
		Chunk *temp = new Chunk;		
	}
	return top;
}

Chunk *Chunk::get_bot() {
	return bot;
}

Chunk *Chunk::get_left() {
	return left;
}

Chunk *Chunk::get_right() {
	return right;
}

