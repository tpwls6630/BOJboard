#include <algorithm>
#include <iostream>
#include <vector>
//#include <queue>
#include <cmath>
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

int n, q;



template<typename T>
class segtree {

	//implementation of segment tree
	// 
	//operationFunction must has 1. associative property
	//							 2. a identity element

private:

	unsigned int size_t = 0;							// size of elements
	unsigned int C = 1;									// binary ceil of size_t
	vector<T> seg;									// contatiner / [C, 2C - 1] has basic elements. / [1, C - 1] has operated elements. / [0] has identity element.
	T(*operationFunction)(const T& a, const T& b);	// monoid operator defined on (T, T) -> T

	const unsigned int mybit_ceil(const unsigned int x) { // bit_ceil (eg. 0110 -> 1000) // x < 2^31 
		unsigned int ret = 1 << 31;
		while (ret >= x && ret) {
			ret >>= 1;
		}
		return ret << 1;
	}

	T pQuery(unsigned int q_left, unsigned int q_right, const unsigned int left, const unsigned int right, unsigned int node) {
		if (right < q_left || q_right < left) { return seg[0]; } // identity element
		if (q_left <= left && right <= q_right) { return seg[node]; }
		unsigned int mid = (left + right) / 2;
		T lq = pQuery(q_left, q_right, left, mid, 2 * node);
		T rq = pQuery(q_left, q_right, mid + 1, right, 2 * node + 1);
		return operationFunction(lq, rq);
	}
public:
	
	segtree() : size_t(0), C(0) {}
	segtree(const unsigned int _size, const vector<T>& _initialValue, T (*_operationFunction)(const T&, const T&), const T _identityElement = T()) {
		build(_size, _initialValue, _operationFunction, _identityElement);
	}
	void build(const unsigned int _size, const vector<T>& _initialValue, T (*_operationFunction)(const T&, const T&), const T _identityElement) {
		size_t = _size;
		C = mybit_ceil(_size);
		seg = vector<T>(2 * C,_identityElement);
		operationFunction = _operationFunction;
		for (unsigned int elementsIdx = 0; elementsIdx < size_t; ++elementsIdx) {
			seg[C + elementsIdx] = _initialValue[elementsIdx];
		}
		unsigned int idx = C - 1;
		while (idx) {
			seg[idx] = operationFunction(seg[(idx << 1)], seg[(idx << 1) + 1]);
			--idx;
		}
	}

	T query(unsigned int q_left, unsigned int q_right) { // [q_left, q_right)
		if (q_left > q_right) return seg[0];
		return pQuery(q_left, q_right, 1, C, 1);
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

vector<int> functionComposition(const vector<int>& v1, const vector<int>& v2) {
	vector<int> ret(6,0);
	for (int i = 1; i <= 5; i++) {
		ret[i] = v1[v2[i]];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(6, 0)), rarr(arr);
	FOR(i, n) {
		for (int x = 1; x <= 5; x++) {
			cin >> arr[i][x];
			rarr[n - 1 - i][arr[i][x]] = x;
		}
	}

	segtree<vector<int>> rSeg(n, rarr, functionComposition, vector<int>{0, 1, 2, 3, 4, 5});

	cin >> q;
	while (q--) {
		int u, a, b;
		vector<int> y(6, 0);
		cin >> u >> a >> b;
		for (int x = 1; x <= 5; x++) {
			cin >> y[x];
		}
		vector<int> AtoU = rSeg.query(n - u + 2, n - a + 1), UtoB = rSeg.query(n - b + 1, n - u);
		vector<int> U = functionComposition(AtoU, functionComposition(y, UtoB));
		vector<int> U_Inverse(6, 0);
		for (int x = 1; x <= 5; x++) {
			U_Inverse[U[x]] = x;
		}
		rSeg.update(n - u + 1, U_Inverse);
		for (int x = 1; x <= 5; x++) {
			cout << U[x] << ' ';
		}
		cout << "\n";
	}

	return 0;
}