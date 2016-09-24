class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size() - 1;
        int end = 0;
        int left = gas[start] - cost[start];
        while(start > end){
            if(left >= 0){
                left += gas[end] - cost[end];
                end++;
            }
            else{
                start--;
                left += gas[start] - cost[start];
            }
        }
        
        return left >= 0 ? start : -1;
    }
};