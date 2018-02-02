#include "player.h"


int Player::move_to(Chunk *ch, int x, int y)
{
	Block *dest = ch->get_block(x, y);

	delete dest;
	ch->assign_ptr(x, y, this);
	cur_chunk->assign_ptr(xpos, ypos, new EmptyBlock);
}

int Player::move(int direction)
{
	if (direction == MOVE_UP) {
		if (ypos >= CHUNK_SIZE_Y-1) {
			move_to(cur_chunk->get_top(), xpos, 0);
			ypos = 0;
			cur_chunk = cur_chunk->get_top();
		}
		else {
			move_to(cur_chunk, xpos, ypos+1);
			ypos++;
		}
	}
	if (direction == MOVE_DOWN) {
		if (ypos <= 0) {
			move_to(cur_chunk->get_bot(), xpos, CHUNK_SIZE_Y-1);
			ypos = CHUNK_SIZE_Y-1;
			cur_chunk = cur_chunk->get_bot();
		}
		else {
			move_to(cur_chunk, xpos, ypos-1);
			ypos--;
		}
	}
	if (direction == MOVE_LEFT) {
		if (xpos <= 0) {
			move_to(cur_chunk->get_left(), CHUNK_SIZE_X-1, ypos);
			xpos = CHUNK_SIZE_X-1;
			cur_chunk = cur_chunk->get_left();
		}
		else {
			move_to(cur_chunk, xpos-1, ypos);
			xpos--;
		}
	}
	if (direction == MOVE_RIGHT) {
		if (xpos >= CHUNK_SIZE_X-1) {
			move_to(cur_chunk->get_right(), 0, ypos);
			xpos = 0;
			cur_chunk = cur_chunk->get_right();
		}
		else {
			move_to(cur_chunk, xpos+1, ypos);
			xpos++;
		}
	}
}

int Player::play()
{
	char buf[8];

	while(1) {

		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
		print_chunk();
		cout << "\nplayer x,y: " << xpos << "," << ypos << endl;

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
		else if (!strcmp(buf, "h\n")) {
		}
	}
	return 0;
}

void Player::print_chunk()
{
	cur_chunk->print_chunk();
}

int Player::get_xpos()
{
	return xpos;
}

int Player::get_ypos()
{
	return ypos;
}

Player::Player()
{
	id = -1;

	for (int i = 0; i < NUM_BLOCK_TYPES; i++) {
		inventory[i] = 0;
	}
}

Player::Player(int x, int y, Chunk *cur)
{
	Block *temp;

	id = -1;
	xpos = x;
	ypos = y;
	cur_chunk = cur;

	temp = cur->get_block(x,y);
	delete temp;
	cur->assign_ptr(x, y, this);

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
	
