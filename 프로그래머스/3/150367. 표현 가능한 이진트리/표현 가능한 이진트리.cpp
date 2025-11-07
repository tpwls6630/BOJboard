#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string parseTree(long long number) {
    string ret = "";
    while(number) {
        ret += number & 1 ? '1' : '0';
        number >>= 1;
    }
    
    int cnt = 2;
    while(cnt - 1 < ret.length()) {
        cnt <<= 1;
    }
    cnt--;
    cnt -= ret.length();
    while(cnt--) ret += '0';
    reverse(ret.begin(), ret.end());
    return ret;
}



bool isPerfectBinaryTree(const string &tree, int l, int r, bool isDummyRoot) {
    if (l > r) return true; 
    int mid = (r + l) / 2;
    if (isDummyRoot) {
        if (tree[mid] == '1') return false;
        return isPerfectBinaryTree(tree, l, mid - 1, true)
            && isPerfectBinaryTree(tree, mid + 1, r, true);
    }
    else {
        if (tree[mid] == '0') isDummyRoot = true;
        return isPerfectBinaryTree(tree, l, mid - 1, isDummyRoot)
            && isPerfectBinaryTree(tree, mid + 1, r, isDummyRoot);
    }
}

bool isPerfectBinaryTree(const string &tree) {
    int mid = tree.length() / 2;
    if (tree[mid] == '0') return false;
    return isPerfectBinaryTree(tree, 0, tree.length() - 1, false);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for (const auto &n : numbers) {
        string tree = parseTree(n);
        answer.push_back(isPerfectBinaryTree(tree) ? 1 : 0);
    }
    return answer;
}