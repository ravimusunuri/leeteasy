class Solution {
public:
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if (numCourses == 0) {
            return true;
        }
        
        // get in-degrees
        int indegree[numCourses] = {0};
        for(int i=0; i< prerequisites.size(); i++) {
            indegree[prerequisites[i][1]]++;       
        }
        
        stack<int> st;
        for(int i=0; i< numCourses; i++) {
            if (indegree[i] == 0) {
                st.push(i);
            }
        }
        
        int count = 0;
        while (!st.empty()) {
            int i = st.top();
            st.pop();
            count++;
            for(int j=0; j< prerequisites.size(); j++) {
                if ((prerequisites[j][0] == i)  && (--indegree[prerequisites[j][1]] == 0)){
                    st.push(prerequisites[j][1]);  
                }
            }
        }
        
        if (count == numCourses){
            return true;
        }
        
        return false;
    }
};
