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

    void prefix(string word){
        int i=0;
        node*it=trie;
        int j=0;
        while (i<word.size())
        {
       
            if(it->next[word[i]-'a']==NULL)return ;
            it=it->next[word[i]-'a'];
            i++;
        }
        //word is present in the trie as prefix 
        vector<string> res;
        printall(it,res,word);

        for(auto s:res)
        cout<<s<<endl;
    }
    // DFS fuction for finding words with prefix as given word
    void printall(node*it,vector<string>&res,string curr){
        if(!it)return ;

        if(it->end)
        res.push_back(curr);

        for(int i=0;i<26;i++){  // check for all charcter 
           
           if(it->next[i])
            printall(it->next[i],res,curr+(char('a'+i)));
        }
        
    }
};

int main()
{
    Trie *mytrie = new Trie();
     
     int n;cin>>n;

    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        mytrie->insert(s);
    }
    int q;cin>>q;
     
     for(int i=0;i<q;i++){
         string s;
         cin>>s;
         mytrie->prefix(s);
     }
   
    return 0;
}