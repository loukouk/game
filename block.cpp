#include "block.h"



void Block::set_xpos(int x) {
	xpos = x;
}

void Block::set_ypos(int y) {
	ypos = y;
}

void Block::set_top(Block *addr) {
	top = addr;
}

void Block::set_bot(Block *addr) {
	bot = addr;
}

void Block::set_left(Block *addr) {
	left = addr;
}

void Block::set_right(Block *addr) {
	right = addr;
}

int Block::get_xpos() {
	return xpos;
}

int Block::get_ypos() {
	return ypos;
}

Block *Block::get_top() {
	return top;
}

Block *Block::get_bot() {
	return bot;
}

Block *Block::get_left() {
	return left;
}

Block *Block::get_right() {
	return right;
}

