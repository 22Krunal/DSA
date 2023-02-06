#include <bits/stdc++.h>

using namespace std;
class Trie
{

public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
                next[i] = NULL;
        }
    };

    node *trie;
    Trie()
    {
        trie = new node();
    }

    void insert(string word)
    {
        int i = 0;
        node *it = trie;

        while (i < word.size())
        {

            // if that char doesnot present in node make new node
            if (it->next[word[i] - 'a'] == NULL)
                it->next[word[i] - 'a'] = new node();

            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word)
    {
        int i = 0;
        node *it = trie;

        while (i < word.size())
        {
            if (!it->next[word[i] - 'a'])
                return false;
            it = it->next[word[i] - 'a'];
            i++;
        }
        // return true if and only if the end of last char is true
        //  that means we inserted  that word
        return (it->end);
    }
};

int main()
{
    Trie *mytrie = new Trie();
    vector<string> words = {"ant", "egg", "eggs", "and"};

    for (auto it : words)
        mytrie->insert(it);

    if (mytrie->search("eg"))
        cout << "Present in the trie" << endl;
    return 0;
}