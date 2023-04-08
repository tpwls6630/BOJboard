template<typename T>
class segtree {

	//implementation of segment tree
	// 
	//operationFunction must has 1. associative property
	//							 2. a identity element

private:

	unsigned int size_t;							// size of elements
	unsigned int C;									// binary ceil of size_t
	vector<T> seg;									// contatiner / [C, 2C - 1] has basic elements / [1, C - 1] has operated elements.
	T(*operationFunction)(const T& a, const T& b);	// monoid operator defined on (T, T) -> T

	const unsigned int mybit_ceil(const unsigned int x) { // bit_ceil (eg. 0110 -> 1000) // x < 2^31 
		unsigned int ret = 1 << 31;
		while (ret) {
			if (ret & x) break;
			ret >>= 1;
		}
		return ret << 1;
	}

public:
	
	segtree() : size_t(0), C(0) {}
	segtree(const unsigned int _size, const vector<T>& _initialValue, T (*_operationFunction)(const T&, const T&)) {
		build(_size, _initialValue, _operationFunction);
	}
	void build(const unsigned int _size, const vector<T>& _initialValue, T (*_operationFunction)(const T&, const T&)) { 
		size_t = _size;
		C = mybit_ceil(_size);
		seg = vector<T>(2 * C + 1);
		operationFunction = _operationFunction;
		for (unsigned int elementsIdx = 0; elementsIdx < size_t; ++elementsIdx) {
			seg[C + elementsIdx] = _initialValue[elementsIdx];
		}
		for (int i = (C << 1) - 1; i > 0; i--) {
			seg[i / 2] = operationFunction(seg[i / 2], seg[i]);
		}
	}
	T query(unsigned int q_left, unsigned int q_right) { // [q_left, q_right)
		T ret = T();
		q_left += C - 1; q_right += C - 1;
		for (; q_left < q_right; q_left /= 2, q_right /= 2) {
			if (q_left & 1) ret = operationFunction(ret, seg[q_left++]);
			if (!(q_right & 1)) ret = operationFunction(ret, seg[q_right--]);
		}
		if (q_left == q_right) ret = operationFunction(ret, seg[q_left]);
		return ret;
		
	}
	void update(const unsigned int target, const T value) {
		unsigned int idx = C + target - 1;
		seg[idx] = value;
		idx >>= 1;
		while (idx) {
			seg[idx] = operationFunction(seg[(idx << 1)], seg[(idx << 1) + 1]);
			idx >>= 1;
		}
	}
};
