#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
//#include <cmath>
//#include <cstring>
//#include <string>
//#include <sstream>
//#include <stack>
//#include <typeinfo>
//#include <array>
//#include <bitset>
//#include <format>

#define pii pair<int,int>
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)


using namespace std;
//########################################################################//
int n, m;


template<typename T>
class segtree {

	//implementation of segment tree
	// 
	//operationFunction must has 1. associative property
	//							 2. a identity element

private:

	unsigned int size_t = 0;						// size of elements
	unsigned int C = 1;								// binary ceil of size_t
	std::vector<T> seg;									// contatiner / [C, 2C - 1] has basic elements. / [1, C - 1] has operated elements. / [0] has identity element.
	T(*operationFunction)(const T& a, const T& b);	// monoid operator defined on (T, T) -> T

	const unsigned int mybit_ceil(const unsigned int x) { // bit_ceil (eg. 0110 -> 1000) // x < 2^31 

		unsigned int ret = 1 << 31;
		while (ret >= x && ret)
			ret >>= 1;

		return ret << 1;
	}

	T pQuery(const unsigned int q_left, const  unsigned int q_right, const unsigned int left, const unsigned int right, const  unsigned int node) {

		if (right < q_left || q_right < left) { return seg[0]; } // identity element
		if (q_left <= left && right <= q_right) { return seg[node]; }
		unsigned int mid = (left + right) / 2;
		T lq = pQuery(q_left, q_right, left, mid, 2 * node);
		T rq = pQuery(q_left, q_right, mid + 1, right, 2 * node + 1);
		return operationFunction(lq, rq);

	}

	void build(const unsigned int _size, const std::vector<T>& _initialValue, T(*_operationFunction)(const T&, const T&), const T _identityElement) {

		size_t = _size;
		C = mybit_ceil(_size);
		seg = std::vector<T>(2 * C, _identityElement);
		operationFunction = _operationFunction;

		for (unsigned int elementsIdx = 0; elementsIdx < size_t; ++elementsIdx)
			seg[C + elementsIdx] = _initialValue[elementsIdx];

		unsigned int idx = C;
		while (--idx)
			seg[idx] = operationFunction(seg[(idx << 1)], seg[(idx << 1) + 1]);

	}

public:

	segtree() : size_t(0), C(0) {}
	segtree(const unsigned int _size, const std::vector<T>& _initialValue, T(*_operationFunction)(const T&, const T&), const T _identityElement = T()) {
		build(_size, _initialValue, _operationFunction, _identityElement);
	}
	T query(unsigned int q_left, unsigned int q_right) { // [q_left, q_right)

		if (q_left > q_right) return seg[0];			// invalid query
		return pQuery(q_left, q_right, 1, C, 1);

	}

	void update(const unsigned int target, const T value) {

		unsigned int idx = C + target - 1;
		seg[idx] = value;
		while (idx >>= 1)
			seg[idx] = operationFunction(seg[(idx << 1)], seg[(idx << 1) + 1]);

	}
};

pii minMax(const pii& p1, const pii& p2) {
	return pii(min(p1.first, p2.first), max(p1.second, p2.second));
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	vector<int> arr(n);
	vector<pii> initial(n, pii());
	FOR(i, n) {
		cin >> arr[i]; initial[i] = { arr[i],arr[i] };
	}
	segtree<pii> seg(n, initial, minMax, pii{IM, -IM-1});

	while (m--) {
		int l, r; cin >> l >> r;
		pii temp = seg.query(l, r);
		cout << temp.first << ' ' << temp.second << "\n";
	}

	return 0;
}