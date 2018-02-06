#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H


#define NUM_BLOCK_TYPES 4
#define IS_SOLID(...) (__VA_ARGS__>=1&&__VA_ARGS__<2)
#define IS_LIQUID(...) (__VA_ARGS__>=2&&__VA_ARGS__<3)
#define IS_GAS(...) (__VA_ARGS__>=3&&__VA_ARGS__<NUM_BLOCK_TYPES)

#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4

class Block{

	protected:
		int id;

	public:
		Block();
		Block(int id);
		int get_id();
};

class Solid : public Block{
	int strength;

	public:
		using Block::Block;
};

class Liquid : public Block{
	int flowrate;

	public:
		using Block::Block;
};

class Gas : public Block{
	int density;

	public:
		using Block::Block;
};

class EmptyBlock : public Block{
	public:
		EmptyBlock();
};


#endif
