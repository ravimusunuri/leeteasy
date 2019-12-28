class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> ret;
    bool isInserted=false;  // merged interval/ new interval
    
    for(int i=0;i<intervals.size();i++)
    {
       // before   
       if(intervals[i][0] <= newInterval[0])
       {
            if(newInterval[0] <= intervals[i][1])
            {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
            else // dont merge
            {
                ret.push_back(intervals[i]);
            }
       }
       else // after
       {
           if(intervals[i][0] <= newInterval[1])
           {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);   
           }
           else
           {
               if(!isInserted)
               {
                    ret.push_back(newInterval);
                    isInserted=true;
               }
               ret.push_back(intervals[i]); 
           }
       }
    }
    if(!isInserted)
       ret.push_back(newInterval); 
    
    return ret;
    }
};
