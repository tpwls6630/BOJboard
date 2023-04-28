#include <iostream>
#include <vector>

#define pii pair<int,int>
#define ll long long
#define IM 2147483647
#define all(x) x.begin(),x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; VAR++)
using namespace std;
//########################################################################//

int N, L;
class myFloor;
vector<int> period, commonPeriod;
vector<myFloor> initialFloors;

class myFloor {
public:
	int l, r;
	bool direction = RIGHT;
	const static bool RIGHT = false, LEFT = true;
	myFloor() : l(0), r(0), direction(RIGHT) {}
	myFloor(int length, bool direc){
		if (direc == RIGHT) {
			l = 0; r = length;
			direction = RIGHT;
		}
		else {
			l = L - length; r = L;
			direction = LEFT;
		}
	}
	myFloor(myFloor &f) {
		this->l = f.l;
		this->r = f.r;
		this->direction = f.direction;
	}
	void next() {
		if (r == L && l == 0) return;
		if (direction == RIGHT) {
			++l; ++r;
			if (r == L) direction = LEFT;
		}
		else if (direction == LEFT) {
			--l; --r;
			if (l == 0) direction = RIGHT;
		}
	}
	bool overlapped(myFloor& f) {
		if (r < f.l || l > f.r) return false;
		return true;
	}
};

int gcd(int a, int b) {
	if (b > a) swap(a, b);
	if (a == 0) return 1;
	if (b == 0) return a;
	return gcd(b, a % b);
}

int timeOfUpward(int currentFloor, int currentTime) {
	int offsetTime = currentTime % commonPeriod[currentFloor];
	myFloor curF(initialFloors[currentFloor]), nextF(initialFloors[currentFloor + 1]);
	while (offsetTime--) {
		curF.next(); nextF.next();
	}
	int ret = 0;
	while (!curF.overlapped(nextF)) {
		curF.next(); nextF.next();
		ret++;
	}
	return ret;
}


void calculateCommonPeriod() {
	for (int i = 0; i < N - 1; i++) {
		commonPeriod[i] = (period[i] * period[i + 1]) / gcd(period[i], period[i + 1]);
		if (commonPeriod[i] == 0) commonPeriod[i] = 1;
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	cin >> N >> L;
	initialFloors = vector<myFloor>(N);
	period.resize(N);
	commonPeriod.resize(N - 1);
	FOR(i,N) {
		int length, direc;
		cin >> length >> direc;
		initialFloors[i] = myFloor(length, direc);
		period[i] = 2 * (L - length);
	}
	
	calculateCommonPeriod();

	int totalTime = 0;
	for (int i = 0; i < N - 1; i++) {
		totalTime += timeOfUpward(i, totalTime);
	}

	cout << totalTime;
	return 0;
}
