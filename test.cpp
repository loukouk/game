#include <iostream>
#include <cstddef>

#include "double_vec.hpp"


using namespace std;

int main()
{
	DoubleVector<int> v;


	for (int i=0; i < 5; i++)
		v[i] = i*2;

	for (int i = 0; i < 5; i++)
		cout << v[i] << endl;

	return 0;
}
