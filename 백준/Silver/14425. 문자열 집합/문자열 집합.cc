#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int alphabet = 26;

#define FOR(INTER_INDEX, RANGE) for (int INTER_INDEX = 0; INTER_INDEX < RANGE; INTER_INDEX++)

class Trie
{
public:
    Trie() : terminal(false)
    {
        memset(child, 0, sizeof(child));
    }
    ~Trie()
    {
        for (Trie *t : child)
            delete t;
    }

    void insert(const char *key)
    {
        if (*key == 0)
            terminal = true;
        else
        {
            int next = *key - 'a';
            if (!child[next])
                child[next] = new Trie;
            child[next]->insert(key + 1);
        }
    }
    bool find(const char *key)
    {
        if (*key == 0)
            return this->terminal;
        int next = *key - 'a';
        if (!child[next])
            return false;
        return child[next]->find(key + 1);
    }

private:
    bool terminal;
    Trie *child[alphabet];
};

Trie root;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    int n, m;
    cin >> n >> m;

    FOR(i, n)
    {
        string str;
        cin >> str;
        root.insert(str.c_str());
    }

    int ans = 0;

    FOR(i, m)
    {
        string str;
        cin >> str;
        if (root.find(str.c_str()))
            ans++;
    }

    cout << ans;
    return 0;
}