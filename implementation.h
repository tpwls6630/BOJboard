#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class segtree {

	//implementation of segment tree
	// 
	//operationFunction must has 1. associative property
	//							 2. a identity element
	//1 based numbering
private:

	unsigned int 	size_t;											// size of elements
	unsigned int 	C;												// binary ceil of size_t
	vector<T> 		seg;											// contatiner / [C, 2C - 1] has basic elements. / [1, C - 1] has operated elements. / [0] has identity element.
	T				(*operationFunction)(const T& a, const T& b);	// monoid operator defined on (T, T) -> T
	T 				identity;										// identity element for operationFunction. This is located at seg[0]
	
	const unsigned int mybit_ceil(const unsigned int x);
	T pQuery(const unsigned int q_left, const unsigned int q_right);
	void build(const unsigned int _size, const vector<T>& _initialValue, T (*_operationFunction)(const T&, const T&), const T _identityElement);

public:
	
	segtree() : size_t(0), C(0) {}
	segtree(const unsigned int _size, const vector<T>& _initialValue, T (*_operationFunction)(const T&, const T&), const T _identityElement = T()) {
		build(_size, _initialValue, _operationFunction, _identityElement);
	}

	T query(unsigned int q_left, unsigned int q_right);
	void update(const unsigned int target, const T value);
	T get(const unsigned int target);
};

template<typename T>
const unsigned int segtree<T>::mybit_ceil(const unsigned int x){ 

	// bit_ceil (eg. 0110 -> 1000) // x < 2^31 

	if(x == 1) return 1;
	unsigned int ret = 1 << 31;
	while (ret >= x && ret) 
		ret >>= 1;
	
	return ret << 1;
}

template<typename T>
T segtree<T>::pQuery(const unsigned int q_left, const unsigned int q_right) {

	// for i in [q_left, q_right] return seg[q_left] + ... seg[q_i] + ... seg[q_right] / + means the operator 

	T leftRet = identity, rightRet = identity;
	unsigned left = C + q_left - 1, right = C + q_right - 1;
	for(; left < right; left >>= 1, right >>= 1){
		if(left&1) leftRet = operationFunction(leftRet, seg[left++]);
		if(!(right&1)) rightRet = operationFunction(seg[right--], rightRet); 
	}
	if(left == right) rightRet = operationFunction(seg[right], rightRet);
	return operationFunction(leftRet, rightRet);

}

template<typename T>
void segtree<T>::build(const unsigned int _size, const vector<T>& _initialValue, T (*_operationFunction)(const T&, const T&), const T _identityElement) {

	// constructor

	size_t 				= _size;
	C 					= mybit_ceil(_size);
	seg 				= vector<T>(2 * C,_identityElement);
	operationFunction 	= _operationFunction;

	for (unsigned int elementsIdx = 0; elementsIdx < size_t; ++elementsIdx) // [C, 2C - 1] basic data
		seg[C + elementsIdx] = _initialValue[elementsIdx];		
	
	unsigned int idx = C;
	while (--idx) 
		seg[idx] = operationFunction(seg[(idx << 1)], seg[(idx << 1) + 1]); // [1, C - 1] operated data

	identity = seg[0];
	
}

template<typename T>
T segtree<T>::query(unsigned int q_left, unsigned int q_right) { 
	
	try{
		if(q_left > q_right || q_left < 1 || q_right > size_t) throw 0;
		return pQuery(q_left, q_right);
	}
	catch(int expn){
		cout << "	segtree :: Invalid query : invalid range\n";
		return identity;
	}

}

template<typename T>
void segtree<T>::update(const unsigned int target, const T value) {

	try{

		if(target > C) throw 0;

		unsigned int idx = C + target - 1;
		seg[idx] = value;
		while (idx >>= 1) 
		seg[idx] = operationFunction(seg[(idx << 1)], seg[(idx << 1) + 1]);
	}
	catch(int expn){
		cout << "	segtree :: Invalid update query : segmentation fault\n";
	}
	
}

template<typename T>
T segtree<T>::get(const unsigned int target){
	try{
		if(target < 0 || target > size_t){
			throw target;
		}
		return seg[C + target - 1];
	}
	catch(const unsigned int expn){
		cout << "	segtree :: Invalid get query : segmentation fault\n";
	}
}