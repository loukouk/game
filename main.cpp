#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstddef>

#include "block.h"
#include "chunk.h"
#include "player.h"
#include "universe.h"

using std::cout;
using std::endl;

int main ()
{
	srand(time(NULL));
	Universe u;
	return u.play();
}
