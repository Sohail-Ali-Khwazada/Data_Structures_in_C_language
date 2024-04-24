#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* childs[26];
    bool eow = false;

};

class Trie {
    private:
        Node* root;
    public:
        Trie() {
            root = new Node();
        }

        void insert(string word) {
            Node* curr = root;
            int indx;

            for(int i = 0; i < word.size(); i++) {
                indx = word[i] - 'a';
                if(!curr->childs[indx]) {
                    curr->childs[indx] = new Node();
                }
                curr = curr->childs[indx];
            }
            curr->eow = true;
        }

        bool search(string word) {
            Node* curr = root;
            int indx;

            for(int i = 0; i < word.size(); i++) {
                indx = word[i] - 'a';
                if(!curr->childs[indx]) return false;
                curr = curr->childs[indx];
            }
            return curr->eow == true;
        }
};

int main(){
    Trie trie1;
    vector<string>words = {"the","a","there","their","any"};

    for(int i = 0; i < words.size(); i++) {
        trie1.insert(words[i]);
    }

    cout<<trie1.search("their")<<endl;
    cout<<trie1.search("thor")<<endl;
    cout<<trie1.search("an")<<endl;
    cout<<trie1.search("any")<<endl;
    return 0;
}