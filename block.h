#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H

//terraria-like 2d game where abunch of blocks spawn random
//subclasses: solid liquid gas blocks
//solids hard, but can collapse
//liquid fall but volume is constant
//gas expands to take all open volume but loses effectiveness
//player must reach gold avoiding dying suffocation/drowning/collapse to win


class Block {
	int xpos;
	int ypos;
	Block * top;
	Block * bot;
	Block * left;
	Block * right;

	public:
		void set_xpos(int x);
		void set_ypos(int y);
		void set_top(Block *addr);
		void set_bot(Block *addr);
		void set_left(Block *addr);
		void set_right(Block *addr);
		int get_xpos();
		int get_ypos();
		Block *get_top();
		Block *get_bot();
		Block *get_left();
		Block *get_right();
};


#endif
