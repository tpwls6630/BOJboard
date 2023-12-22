#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int alphabet = 10;

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
            int next = *key - '0';
            if (!child[next])
                child[next] = new Trie();
            child[next]->insert(key + 1);
        }
    }
    bool find(const char *key)
    {
        if (*key == 0)
            return true;
        int next = *key - '0';
        if (!child[next])
            return false;
        return child[next]->find(key + 1);
    }
    bool isPrefix(const char *key) const
    {

        if (*key == 0)
        {
            for (int i = 0; i < alphabet; i++)
            {
                if (child[i])
                    return true;
            }
            return false;
        }
        int next = *key - '0';
        if (!child[next])
            return false;
        return child[next]->isPrefix(key + 1);
    }

private:
    bool terminal;
    Trie *child[alphabet];
};

bool isValid(const Trie *root, const vector<string> &numbers)
{
    for (string number : numbers)
    {
        if (root->isPrefix(number.c_str()))

            return false;
        }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie();
    cin.tie();

    int t;
    cin >> t;
    while (t--)
    {

        Trie *root = new Trie();

        int n;
        cin >> n;

        vector<string> numbers(n);
        FOR(i, n)
        {
            cin >> numbers[i];
            root->insert(numbers[i].c_str());
        }

        if (isValid(root, numbers))
            cout << "YES\n";
        else
            cout << "NO\n";

        delete root;
    }

    return 0;
}