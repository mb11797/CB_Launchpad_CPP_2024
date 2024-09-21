#include<iostream>
#include<vector>
using namespace std;
	
class TrieNode{
public:
	char ch;
	TrieNode*child[26];
	bool isTerminal;

	TrieNode(char ch){
		this->ch = ch;
		this->isTerminal = false;
	}
};

class Trie{
	TrieNode*root;
public:
	Trie(){
		root = new TrieNode('\0');
	}

	// add("apple")
	// add("manika") -> word[0] = 'm' -> ch = 'm' -> ch - 'a' = 'm' - 'a' = 109 - 97 = 12
	void addWord(string word){
		TrieNode*temp = root;
		for(int i=0; i<word.length(); i++){
			char ch = word[i];
			if(temp->child[ch - 'a'] != NULL){
				// node exists
				temp = temp->child[ch - 'a'];
			}
			else{
				// node does not exist
				TrieNode*newNode = new TrieNode(ch);
				temp->child[ch - 'a'] = newNode;
				temp = temp->child[ch - 'a'];
			}
		}
		temp->isTerminal = true;
		return;
	}

	bool searchWord(string word){
		TrieNode*temp = root;
		for(int i=0; i<word.length(); i++){
			char ch = word[i];
			if(temp->child[ch - 'a'] == NULL){
				return false;
			}
			temp = temp->child[ch - 'a'];
		}

		return temp->isTerminal;
	}

	vector<string> searchAllWordsWithPrefix(string prefix){
		TrieNode*temp = root;
		vector<string> ans;
		for(int i=0; i<prefix.length(); i++){
			char ch = prefix[i];
			if(temp->child[ch - 'a'] == NULL){
				return ans;
			}
			temp = temp->child[ch - 'a'];
		}

		// recursively traverse the TRIE from this node and aggregate all the words
		dfs(temp, prefix, ans);
		return ans;
	}

	void dfs(TrieNode*node, string word, vector<string> &ans){
		if(node->isTerminal){
			ans.push_back(word);
		}

		for(int i=0; i<26; i++){
			char ch = 'a' + i;		// 0 -> 'a' (ascii value me addition and then type casting)
									// 1 -> 'b' = 'a' + 1
									// 2 -> 'c' = 'a' + 2
									// ...
									// 25 -> 'z' = 'a' + 25
			if(node->child[i] != NULL){
				dfs(node->child[i], word + ch, ans);
			}
		}
	}
};


int main(){

	Trie*trie = new Trie();
	trie->addWord("apple");
	trie->addWord("ape");
	trie->addWord("app");
	trie->addWord("bone");
	trie->addWord("arav");

	if(trie->searchWord("app")){
		cout<<"app is present"<<endl;
	}
	else{
		cout<<"app is not present"<<endl;
	}

	vector<string> ans = trie->searchAllWordsWithPrefix("ap");
	cout<<"All words starting with prefix = ap are: "<<endl;
	for(string word: ans){
		cout<<word<<", ";
	}	
	cout<<endl;

	return 0;
}