#include "block.h"

Block::Block()
{
	id = -1;
}

Block::Block(int identifier)
{
	id = identifier;
}

int Block::get_id()
{
	return id;
}

EmptyBlock::EmptyBlock()
{
	id = 0;
}
