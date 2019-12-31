class Solution {
public:
    int minSteps(int n) {
	int a = 0;
	int curr = 1;
	int res = 0;
	while(curr != n) {
		if(n % (curr) == 0) {
			a = curr;
			curr += a;
			res += 2;
		} else {
			curr += a;
			res++;
		}
	}
	return res;
}
};
