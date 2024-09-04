#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include "stdlib.h"
using namespace std;

#define INF 5'000'000'000'000
#define FOR(i, x) for(int i = 0; i < x; i++)
#define pii pair<int, int>
#define ll long long
#define all(x) x.begin(),x.end()

/*
        ____________
       /  0  /  1  /|
      /_____/_____/ |
     /  2  /  3  /| |
    /_____/_____/ |/|
 4->|     |     | /5|
    |_____|_____|/|/
    |  6  |  7  | / 
    |_____|_____|/


*/

int r, c;
vector<int> parent;
int curBlockNum = 0;
int f(int x){
    if(parent[x] == -1) return x;
    return parent[x] = f(parent[x]);
}

bool u(int a, int b){
    int A = f(a), B = f(b);
    if(A == B) return false;

    parent[A] = B;
    return true;
}
void join(vector<array<int,2>> &edge){
    for(int i = 0; i < edge.size(); ++i){
        int a = edge[i][0], b = edge[i][1];
        u(a,b);
    }
}
int getLeftBlockOffset(int currentBlockOffset){
    static int rowDiv = c * 8;
    int curCol = currentBlockOffset % rowDiv;
    if(curCol == 0) return -1; // leftmost block
    return currentBlockOffset - 8;
}

int getUpBlockOffset(int currentBlockOffset)
{
    static int rowDiv = c * 8;
    if(currentBlockOffset < rowDiv) return -1; // first row
    return currentBlockOffset - rowDiv;
}
void put_O(){
    vector<array<int,2>> edge;
    int blockOffset = curBlockNum;
    FOR(i, 4){
        edge.push_back({curBlockNum + i, curBlockNum + i + 4});
    }
    int LBOffset, UBOffset;
    if((LBOffset = getLeftBlockOffset(blockOffset)) != -1){
        edge.push_back({blockOffset, LBOffset+1});
        edge.push_back({blockOffset+2, LBOffset+3});
        edge.push_back({blockOffset+4, LBOffset+5});
        edge.push_back({blockOffset+6, LBOffset+7});
    }
    if((UBOffset = getUpBlockOffset(blockOffset)) != -1){
        edge.push_back({blockOffset, UBOffset+2});
        edge.push_back({blockOffset+1, UBOffset+3});
        edge.push_back({blockOffset+4, UBOffset+6});
        edge.push_back({blockOffset+5, UBOffset+7});
    }
    join(edge);
    curBlockNum += 8;
}

void put_I(){
    vector<array<int,2>> edge;
    int blockOffset = curBlockNum;
    edge.push_back({blockOffset, blockOffset+2});
    edge.push_back({blockOffset+1, blockOffset+3});
    edge.push_back({blockOffset+4, blockOffset+6});
    edge.push_back({blockOffset+5, blockOffset+7});
    int LBOffset, UBOffset;
    if((LBOffset = getLeftBlockOffset(blockOffset)) != -1){
        edge.push_back({blockOffset, LBOffset+1});
        edge.push_back({blockOffset+2, LBOffset+3});
        edge.push_back({blockOffset+4, LBOffset+5});
        edge.push_back({blockOffset+6, LBOffset+7});
    }
    if((UBOffset = getUpBlockOffset(blockOffset)) != -1){
        edge.push_back({blockOffset, UBOffset+2});
        edge.push_back({blockOffset+1, UBOffset+3});
        edge.push_back({blockOffset+4, UBOffset+6});
        edge.push_back({blockOffset+5, UBOffset+7});
    }
    join(edge);
    curBlockNum += 8;
}

void put_H(){
    vector<array<int,2>> edge;
    int blockOffset = curBlockNum;
    for(int i = 0; i < 8; i+=2){
        edge.push_back({blockOffset+i, blockOffset+i+1});
    }
    int LBOffset, UBOffset;
    if((LBOffset = getLeftBlockOffset(blockOffset)) != -1){
        edge.push_back({blockOffset, LBOffset+1});
        edge.push_back({blockOffset+2, LBOffset+3});
        edge.push_back({blockOffset+4, LBOffset+5});
        edge.push_back({blockOffset+6, LBOffset+7});
    }
    if((UBOffset = getUpBlockOffset(blockOffset)) != -1){
        edge.push_back({blockOffset, UBOffset+2});
        edge.push_back({blockOffset+1, UBOffset+3});
        edge.push_back({blockOffset+4, UBOffset+6});
        edge.push_back({blockOffset+5, UBOffset+7});
    }
    join(edge);
    curBlockNum += 8;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    
    cin >> r>> c;

    parent = vector<int>(c*r*8, -1);
    FOR(i, r){
        string q;
        cin >> q;
        for(char ch : q){
            switch(ch){
                case 'O': put_O();
                break;
                case 'I': put_I();
                break;
                case 'H': put_H();
                break;
            }
        }
    }

    int ret = 0;
    for(auto p : parent){
        if(p == -1) ++ret;
    }

    cout << ret;

    return 0;
}