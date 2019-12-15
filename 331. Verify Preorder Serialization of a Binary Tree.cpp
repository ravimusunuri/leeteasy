class Solution {
public:
    bool isValidSerialization(string preorder) {
     if(preorder.length()==0)
		return 1;
	
    int valCnt = 0, sentinelCnt = 0;
	if(preorder[0]=='#')
		sentinelCnt++;
	else
		valCnt++;
	
	for(int i=1;i<preorder.length();i++){
		if(preorder[i-1]==','){
			if(preorder[i] == '#')
				sentinelCnt++;
			else
				valCnt++;
		    
		}
		if(sentinelCnt>valCnt&&i<preorder.length()-1)
		        return 0;
	}

	return valCnt==sentinelCnt-1;   
    }
};
