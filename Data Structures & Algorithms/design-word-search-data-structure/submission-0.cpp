class WordDictionary {

    class TrieNode {
    public:

        TrieNode* children[26];
        bool isEnd;

        TrieNode()
        {
            for(int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }

            isEnd = false;
        }
    };

    TrieNode* root;

public:

    WordDictionary() {

        root = new TrieNode();
    }
    
    void addWord(string word) {

        TrieNode* curr = root;

        for(char ch : word)
        {
            int idx = ch - 'a';

            if(curr->children[idx] == nullptr)
            {
                curr->children[idx] =
                    new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }

    bool dfs(string &word,
             int index,
             TrieNode* node)
    {
        // reached end of word
        if(index == word.size())
        {
            return node->isEnd;
        }

        char ch = word[index];

        // wildcard case
        if(ch == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(node->children[i] &&
                   dfs(word,
                       index + 1,
                       node->children[i]))
                {
                    return true;
                }
            }

            return false;
        }

        // normal character case
        int idx = ch - 'a';

        if(node->children[idx] == nullptr)
        {
            return false;
        }

        return dfs(word,
                   index + 1,
                   node->children[idx]);
    }
    
    bool search(string word) {

        return dfs(word, 0, root);
    }
};