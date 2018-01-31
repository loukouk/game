#include <iostream>

#include "block.h"

using std::cout;
using std::endl;

int main ()
{
	Block my_block;

	my_block.set_xpos(5);
	my_block.set_ypos(7);

	cout << my_block.get_xpos() << endl << my_block.get_ypos() << endl;

	return 0;
}
