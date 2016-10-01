class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        int i = 0;
        for(;i < strs[0].size();i++){
            char cur = strs[0][i];
            for(int vi = 1; vi < strs.size();vi++){
                if(i >= strs[vi].size() || strs[vi][i] != cur){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};