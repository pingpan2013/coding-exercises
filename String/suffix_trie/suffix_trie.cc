/*
 * =====================================================================================
 *
 *       Filename:  suffix_trie.cc
 *
 *    Description:  basic operations of suffix trie
 *                  Reference: http://www.geeksforgeeks.org/pattern-searching-using-trie-suffixes/
 *
 *        Created:  02/17/2015 00:57:21
 *       Compiler:  g++ 4.7.0
 *
 * =====================================================================================
 */

#include <list>
#include <iostream>

using namespace std;

#define MAX_CHAR 256

class SuffixTrieNode{
private:
    SuffixTrieNode* children[MAX_CHAR];
    list<int> *indexes;
    
public:
    SuffixTrieNode(){
        indexes = new list<int>;

        for(int i = 0; i < MAX_CHAR; i++){
            children[i] = nullptr;
        }
    }
    
    // recursively insert a suffix in substree rooted 
    // with this node
    void insertSuffix(string suffix, int index){
        indexes->push_front(index);

        if(s.empty())   return;

        char c = s[0];
        if(children[c] == nullptr){
            children[c] = new SuffixTrieNode();
        }
        
        // recursively construct the suffix trie
        children[c]->insertSuffix(s.substr(1), index+1);
    }

    // search a pattern in substree rooted with this node
    list<int>* search(string pattern){
        if(s.empty()){
            return indexes;
        }

        if(children[s[0]]){
            return children[s[0]]->search(s.substr(1));
        }
        else return nullptr; // no branch
    }
};

class SuffixTrie{
private:
    SuffixTrieNode root;

private:
    SuffixTree(string text){
        // insert all suffixes
        for(int i = 0; i < text.size(); i++){
            root.insertSuffix(text.substr(i), i);
        }
    }
    
    // get all occurences of pattern in the suffix trie built for text
    void search(string pattern){
        list<int> *result = root.search(pattern);
    }

    if(!result)  cout << "pattern not found!" << endl;
    else{
        int len = pattern.size();
        for(auto i = result->begin(); i != result->end(); i++){
            cout << "Pattern found at position " << *i - len << endl;
        }
    }
};


