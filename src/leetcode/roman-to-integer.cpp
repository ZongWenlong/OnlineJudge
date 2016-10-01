class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        unordered_map<char,int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        
        int pre = INT_MAX;
        for(auto c : s){
            int cur = map[c];  
            if(cur > pre){
                value = value - pre + cur - pre;
            }
            else{
                value += cur;
            }
            pre = cur;
               
        }
        return value;
    }
};