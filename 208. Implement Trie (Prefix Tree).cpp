class Trie
{

public:

    struct Trie_Node
    {
        struct Trie_Node *children[26];
        bool is_end; 
    };

    struct Trie_Node *root = new Trie_Node;

    Trie() 
    {

        root->is_end = false;
        
        for(int i=0;i<26;i++)
        {
            root->children[i] = NULL;
        }  
    }

    struct Trie_Node *get_node()
    {
        struct Trie_Node *temp = new Trie_Node;
        
        temp->is_end = false;
        
        for(int i=0;i<26;i++)
        {
            temp->children[i] = NULL;
        }
        
        return temp;
    }

    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        struct Trie_Node *temp = root;
        
        for(auto x:word)
        {
            int idx = x-'a';
            
            if(!temp->children[idx])
            {
                temp->children[idx] = get_node();
            }
            
            temp = temp->children[idx];
            
        }
        temp->is_end = true;   
    }

    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        
        struct Trie_Node *temp = root;
        
        for(auto x:word)
        {
            int idx = x-'a';
            
            if(!temp->children[idx])
            {
                return false;
            }
            
            temp = temp->children[idx];
            
        }
        return temp->is_end;  
        
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        
        struct Trie_Node *temp = root;
        
        for(auto x:prefix)
        {
            int idx = x-'a';
            
            if(!temp->children[idx])
            {
                return false;
            }
            
            temp = temp->children[idx];
            
        }
        return true;  
        
    }

};

