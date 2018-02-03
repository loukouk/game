#include "player.hpp"


// TODO: Harvest block, blocked by terrain...
int Player::move_to(Chunk *ch, int x, int y)
{
	Block *dest = ch->get_block(x, y);

	delete dest;
	ch->assign_ptr(x, y, this);
	cur_chunk->assign_ptr(block_xpos, block_ypos, new EmptyBlock);
	cur_chunk = ch;
}

//TODO: what if move_to() fails??
int Player::move(int direction)
{
	if (direction == MOVE_UP) {
		if (block_ypos >= CHUNK_SIZE_Y-1) {
			move_to(u->get_chunk(chunk_xpos, chunk_ypos+1), block_xpos, 0);
			block_ypos = 0;
			chunk_ypos++;
		}
		else {
			move_to(cur_chunk, block_xpos, block_ypos+1);
			block_ypos++;
		}
	}
	if (direction == MOVE_DOWN) {
		if (block_ypos <= 0) {
			move_to(u->get_chunk(chunk_xpos, chunk_ypos-1), block_xpos, CHUNK_SIZE_Y-1);
			block_ypos = CHUNK_SIZE_Y-1;
			chunk_ypos--;
		}
		else {
			move_to(cur_chunk, block_xpos, block_ypos-1);
			block_ypos--;
		}
	}
	if (direction == MOVE_LEFT) {
		if (block_xpos <= 0) {
			move_to(u->get_chunk(chunk_xpos-1, chunk_ypos), CHUNK_SIZE_X-1, block_ypos);
			block_xpos = CHUNK_SIZE_X-1;
			chunk_xpos--;
		}
		else {
			move_to(cur_chunk, block_xpos-1, block_ypos);
			block_xpos--;
		}
	}
	if (direction == MOVE_RIGHT) {
		if (block_xpos >= CHUNK_SIZE_X-1) {
			move_to(u->get_chunk(chunk_xpos+1, chunk_ypos), 0, block_ypos);
			block_xpos = 0;
			chunk_xpos++;
		}
		else {
			move_to(cur_chunk, block_xpos+1, block_ypos);
			block_xpos++;
		}
	}
}

int Player::play()
{
	char buf[8];

	while(1) {

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
		print_chunk();
		cout << "\nplayer x,y: " << block_xpos << "," << block_ypos << endl;

		cout << endl << "> ";
		fgets(buf, 8, stdin);
		if (!strcmp(buf, "u\n") || !strcmp(buf, "up\n"))
			move(MOVE_UP);
		else if (!strcmp(buf, "d\n") || !strcmp(buf, "down\n"))
			move(MOVE_DOWN);
		else if (!strcmp(buf, "l\n") || !strcmp(buf, "left\n"))
			move(MOVE_LEFT);
		else if (!strcmp(buf, "r\n") || !strcmp(buf, "right\n"))
			move(MOVE_RIGHT);
		else if (!strcmp(buf, "exit\n") || !strcmp(buf, "quit\n"))
			break;
	}
	return 0;
}

void Player::print_chunk()
{
	cur_chunk->print_chunk();
}

int Player::get_xpos()
{
	return block_xpos;
}

int Player::get_ypos()
{
	return block_ypos;
}

Player::Player(Universe *u_ptr)
{
	Block *temp;

	id = -1;
	u = u_ptr;
	chunk_xpos = 0;
	chunk_ypos = 0;

	temp = u->get_spawn(block_xpos, block_ypos);
	cur_chunk = u->get_chunk(0,0);

	temp = cur_chunk->get_block(block_xpos,block_ypos);
	delete temp;
	cur_chunk->assign_ptr(block_xpos, block_ypos, this);

	for (int i = 0; i < NUM_BLOCK_TYPES; i++) {
		inventory[i] = 0;
	}
}


int Player::add_to_inventory(int item, int amount)
{
	if (item < 0 || item >= NUM_BLOCK_TYPES)
		return 1;

	inventory[item] += amount;
	return 0;
}

