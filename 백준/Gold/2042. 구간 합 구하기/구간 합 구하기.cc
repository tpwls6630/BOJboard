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

int n,m,q;




class segtree {
	// 아직은 덧셈 연산자가 정의된 자료형에 대해서만 사용 가능.
private:

	unsigned int size_t;	// size of elements
				// binary ceil value
	vector<long long> seg;

	unsigned int mybit_ceil(unsigned int x) { // bit_floor (eg. 0110 -> 1000)
		unsigned int ret = 1 << 31;
		while (ret) {
			if (ret & x) break;
			ret >>= 1;
		}
		return ret << 1;
	}

public:
	unsigned int C;
	segtree() : size_t(0) {}
	segtree(const unsigned int _size, vector<long long>& _initialValue) {
		build(_size, _initialValue);
	}
	void build(const unsigned int _size, vector<long long>& _initialValue) {
		size_t = _size;
		C = mybit_ceil(_size);
		seg = vector<long long>(2 * C + 1);
		for (int elementsIdx = 0; elementsIdx < size_t; ++elementsIdx) {
			seg[C + elementsIdx] = _initialValue[elementsIdx];
		}
		for (int i = (C << 1) - 1; i > 0; i--) {
			seg[i / 2] += seg[i];
		}
	}
	long long query(unsigned int q_left, unsigned int q_right, unsigned int left, unsigned int right, unsigned int node = 1) { // [q_left, q_right]
		if (right < q_left || q_right < left) return 0;
		if (q_left <= left && right <= q_right) return seg[node];
		unsigned int mid = (left + right) / 2;
		return query(q_left, q_right, left, mid, 2 * node) + query(q_left, q_right, mid + 1, right, 2 * node + 1);
		
	}
	void update(const unsigned int target, long long value) {
		unsigned int idx = C + target - 1;
		seg[idx] = value;
		idx >>= 1;
		while (idx) {
			seg[idx] = seg[idx << 1] + seg[(idx << 1) + 1];
			idx >>= 1;
		}
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m >> q;
	vector<long long> arr(n);
	FOR(i, n) cin >> arr[i];
	segtree seg(n, arr);

	int t = m + q;
	FOR(i, t) {
		long long Q, a , b; cin >> Q >> a >> b;
		if (Q == 1) {

			seg.update(a, b);
		}
		else {

			cout << seg.query(a, b, 1, seg.C) << "\n";
		}
	}
	return 0;
}