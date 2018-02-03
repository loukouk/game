#ifndef GAME_DOUBLE_VEC_H
#define GAME_DOUBLE_VEC_H

#include <iostream>
#include <vector>


template <typename obj_t>
class DoubleVector{
	std::vector<obj_t> positives;
	std::vector<obj_t> negatives;

	public:
		DoubleVector();
		obj_t& operator[](int i);
		int p_size();
		int n_size();
		int size();
};


template <typename obj_t>
DoubleVector<obj_t>::DoubleVector()
{
	positives.resize(2);
	negatives.resize(1);
}

template <typename obj_t>
obj_t& DoubleVector<obj_t>::operator[](int i)
{
	if (i >= 0) {
		unsigned p = i;
		if (positives.size() <= p)
			positives.resize(p+1);
		return positives[p];
	}
	else {
		unsigned n = (i*-1) - 1;
		if (negatives.size() <= n)
			negatives.resize(n+1);
		return negatives[n];
	}
}

template <typename obj_t>
int DoubleVector<obj_t>::p_size()
{
	return positives.size();;
}

template <typename obj_t>
int DoubleVector<obj_t>::n_size()
{
	return negatives.size();
}

template <typename obj_t>
int DoubleVector<obj_t>::size()
{
	return (n_size() + p_size() - 1);
}

#endif
