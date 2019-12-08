class Solution {
public:
    
    bool neighbor (string s1, string s2) {
        int diff = 0;
        for (int i=0; i< s1.length(); i++) {
            if (s1[i] != s2[i]) { 
                diff++;
            }
        }
        if (diff == 1)
            return true;
        return false;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,vector<string>> graph;
        unordered_map<string, bool> visit;
        unordered_map<string, int> dist;
        queue<string> myq;
        
        wordList.push_back(beginWord);
        //wordList.push_back(endWord);
        for (int i=0; i< wordList.size(); i++) {
            for (int j=i+1; j< wordList.size(); j++) {
                if (neighbor(wordList[i], wordList[j])) {
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
            visit[wordList[i]] = false;
        }
        
        myq.push(beginWord);
        dist[beginWord] = 1;
        visit[beginWord] = true;
        
        while(!myq.empty()) {
            string top = myq.front();
            myq.pop();
            vector<string> adj = graph[top];
            
            if (top == endWord) {
                return dist[top];
            }
            
            for (int i = 0; i< adj.size(); i++) {
                if (visit[adj[i]] == false) {
                    myq.push(adj[i]);
                    visit[adj[i]] = true;
                    dist[adj[i]] = dist[top] + 1;
                }
            }
        }
        return 0;
    }
    
};
