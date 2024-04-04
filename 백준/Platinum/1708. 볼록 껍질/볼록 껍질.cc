#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

#define INF 5'000'000'000'000
#define FOR(i, x) for(int i = 0; i < x; i++)
#define pii pair<int, int>
#define ll long long
#define all(x) x.begin(),x.end()

pii orig;

ll ccw(const pii &origin, const pii &A, const pii &B){
    return 1LL*(A.first-origin.first)*(B.second-origin.second) - 1LL*(A.second-origin.second)*(B.first-origin.first);
}

bool compare(const pii &a, const pii &b){
    ll c = ccw(orig, a, b);
    if(c == 0){
        return pow(a.first-orig.first,2)+pow(a.second-orig.second,2) 
        < pow(b.first-orig.first,2)+pow(b.second-orig.second,2);
    }
    return c > 0;
}

int convexHull(vector<pii> &points){

    int p_size = points.size();
    sort(all(points));
    orig = points[0];
    sort(points.begin() + 1, points.end(), compare);

    stack<int> cvh;
    cvh.push(0);
    cvh.push(1);

    int top2, top1;

    int next = 2;

    while(next < p_size){
        while(cvh.size() >= 2){
            top2 = cvh.top();
            cvh.pop();
            top1 = cvh.top();

            if(ccw(points[top1], points[top2], points[next]) > 0){
                cvh.push(top2);
                break;
            }
        }

        cvh.push(next++);
    }
    
    return cvh.size();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    vector<pii> points(n); 

    FOR(i, n){
        cin >> points[i].first >> points[i].second;
    }

    cout << convexHull(points);
    return 0;
}