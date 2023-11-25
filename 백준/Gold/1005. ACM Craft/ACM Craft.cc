#include <iostream>
#include <vector>
#include <array>
#include <queue>
using namespace std;

#define INF 5'000'000'000'000
#define FOR(i, x) for(int i = 0; i < x; i++)

long long solution(){
    int n,k,endNode;
    cin >> n>>k;

    vector<long long> weight(n + 1), dist(n+1, 0);
    vector<vector<int>> edge(n+1, vector<int>());
    vector<int> indegree(n+1, 0);

    FOR(i, n){
        cin >> weight[i+1];
    }
    FOR(i,k){
        int X, Y;
        cin >> X>>Y;
        indegree[Y]++;
        edge[X].push_back(Y);
    }
    cin >> endNode;

    queue<int> topo;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0) {
            topo.push(i);
            dist[i] = weight[i];
        }
    }

    while(!topo.empty()){
        int cur = topo.front(); topo.pop();

        if(cur == endNode) break;
        for(int i : edge[cur]){

            indegree[i]--;
            dist[i] = max(dist[i], dist[cur] + weight[i]);
            if(indegree[i] == 0) topo.push(i);
            
        }
    }

    return dist[endNode];
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int T;
    cin>>T;

    while(T--){
        cout << solution() << "\n";
    }
    return 0;
}