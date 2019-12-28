class Solution {
public:
    typedef unsigned int uint32;
    
    uint32 bagOfAlpha(const string &word)
    {
        uint32 alpha_bag = 0;
        for(char c : word)
            alpha_bag |= ( (uint32)1 << (c-'a') );
        
        return alpha_bag;
    }

    int maxProduct(vector<string>& words) 
    {
        vector<uint32> bags;
        
        for(const string &str : words)
            bags.push_back( bagOfAlpha(str) );
        
        int result = 0;
        for(int i=0; i < words.size(); i++)
        {
            for(int j=i+1; j < words.size(); j++)
            {
                if(bags[i] & bags[j]) continue;
                
                int tmp = words[i].size() * words[j].size();
                if(result < tmp) result = tmp;
            }
        }
        
        return result;
    }
};
