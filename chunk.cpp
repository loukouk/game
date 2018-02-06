#include "chunk.hpp"

matrix Chunk::create_blocks(int xsz, int ysz)
{
	matrix blocks_matrix(xsz, submatrix(ysz));
	int id;

	for (matrix::iterator it0 = blocks_matrix.begin(); it0 != blocks_matrix.end(); ++it0) {
		for (submatrix::iterator it1 = it0->begin(); it1 != it0->end(); ++it1) {
			id = (rand() % (NUM_BLOCK_TYPES-1)) + 1;
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
	blocks = create_blocks(CHUNK_SIZE_X, CHUNK_SIZE_Y);
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
//			cout << (*(it[i]))->get_id() << "\t";
			if ( (*(it[i]))->get_id() == -1)
				cout << "8 ";
			if ( (*(it[i]))->get_id() == 0)
				cout << "  ";
			if ( (*(it[i]))->get_id() == 1)
				cout << "# ";
			if ( (*(it[i]))->get_id() == 2)
				cout << "~ ";
			if ( (*(it[i]))->get_id() == 3)
				cout << ". ";
			it[i]++;
		}
		cout << endl;
	}
}
