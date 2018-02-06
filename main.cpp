#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstddef>

#include "block.hpp"
#include "chunk.hpp"
#include "player.hpp"
#include "universe.hpp"

using std::cout;
using std::endl;

int main ()
{
	srand(time(NULL));
	Universe u;
	Player p1(&u);
//	return p1.play();
	return p1.play_real_time();
}
