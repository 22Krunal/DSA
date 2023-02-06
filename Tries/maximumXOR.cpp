#include <bits/stdc++.h>

using namespace std;

class Trie
{

public:
    class node
    {
    public:
        node *next[2];

        node()
        {

            for (int i = 0; i < 2; i++)
                next[i] = NULL;
        }
    };
    node *trie;
    Trie()
    {
        trie = new node();
    }
    void insert(int n)
    {
        node *it = trie;
        for (int i = 31; i >= 0; i--)
        {

            int bit = ((n >> i) & 1);

            if (it->next[bit] == NULL)
                it->next[bit] = new node();

            it = it->next[bit];
        }
    }
    int helper(vector<int> &a)
    {
        int res = 0;
        for (auto ite : a)
        {
            int num = ite;
            int curr_max = 0;
            cout<<num<<"->";
            node *it = trie;
            for (int i = 31; i >= 0; i--)
            {

                int bit = ((num >> i) & 1) ? 0 : 1; // curr bit

                if (it->next[bit]!=NULL)
                {
                    curr_max <<= 1;
                    curr_max |= 1;
                    it = it->next[bit];
                }
                else
                {
                    curr_max <= 1;
                    curr_max |= 0;
                    it = it->next[bit];
                }
                cout<<bit;
            }
            cout<<endl;
            res = max(res, curr_max);
        }
        cout<<res<<endl;
        return res;
    }
};
int main()
{
    Trie *mytrie = new Trie();
    vector<int> a = {10, 15, 2, 3, 5};
    mytrie->insert(0);
    for (auto it : a)
        mytrie->insert(it);
    cout << mytrie->helper(a) << endl;

    cout << "";
    return 0;
}