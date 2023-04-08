#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
//#include <deque>
#include <string>
//#include <tuple>
//#include <stack>
#include <sstream>
#include <map>
#include <unordered_map>
//#include <array>
//#include <format>

#define INT_MAX 2147483647
#define LLONG_MAX 9'223'372'036'854'775'807
#define all(x) x.begin(), x.end()
#define FOR(VAR,TIMES) for(int VAR = 0; VAR < TIMES; ++VAR)
using namespace std;
//#######################################################

int M[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
long long n, due, f;

vector<string> split(string str, char delimiter) {
	vector<string> ans;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		ans.push_back(temp);
	}

	return ans;
}

struct date {

	int yyyy = 0;
	int mm = 0;
	int dd = 0;
	int hh = 0;
	int m = 0;

	date() :yyyy(0), mm(0), dd(0), hh(0), m(0) {}
	date(int yyyy, int mm, int dd, int hh, int m) :yyyy(yyyy), mm(mm), dd(dd), hh(hh), m(m) {}
	date(string str) {
		yyyy = stoi(str.substr(0, 4));
		mm = stoi(str.substr(5, 2));
		dd = stoi(str.substr(8, 2));
		hh = stoi(str.substr(11, 2));
		m = stoi(str.substr(14, 2));
	}
	long long rt() {
		return (long long)((M[mm - 1] + dd - 1) * 24 * 60 + hh * 60 + m);
	}

	long long operator-(date& ref) {
		return rt() - ref.rt();
	}
};


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	string buf;
	cin >> n >> buf >> f; cin.ignore();
	due = stoi(buf.substr(0, 3)) * 24 * 60 + stoi(buf.substr(4, 2)) * 60 + stoi(buf.substr(7));
	//cout << format("due time {}", due) << endl;
	unordered_map<string, date> ledger;
	map<string, long long> person;
	while (n--) {
		string temp;
		getline(cin, temp);
		vector<string> str = split(temp, ' ');
		bool fd = false;
		auto iter = ledger.find( str[2] + " " + str[3]);
		if (iter != ledger.end()) {
			long long fanalty = date(str[0] + " " + str[1]) - (*iter).second - due;
			if (fanalty > 0) {
				if(person.find(str[3]) == person.end())
					person[str[3]] = f*fanalty;
				else
					person[str[3]] += f*fanalty;
			}
			ledger.erase(iter);
		}
		else {
			ledger[str[2] + " " + str[3]] = date(str[0] + " " + str[1]);
		}
	}
	
	if (person.empty()) {
		cout << -1; return 0;
	}
	for (auto p : person) {
		cout << p.first << ' ' << p.second << "\n";
	}

	return 0;
}