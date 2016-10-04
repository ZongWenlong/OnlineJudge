class Solution {
public:
    string sortStr(string str){
        int charCount[26] = {0};
        for(char c : str){
            charCount[c - 'a']++;
        }
        for(int i = 0,j = 0; i < 26;i++){
            while(charCount[i] != 0){
                str[j++] = i + 'a';
                charCount[i]--;
            }
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,list<int>> groups;
        for(int i = 0;i < strs.size();i++){
            string newStr = sortStr(strs[i]);
            groups[newStr].push_back(i);
        }
        vector<vector<string>> results;
        for(auto group : groups){
            vector<string> result;
            for(int index : group.second){
                result.push_back(strs[index]);
            }
            results.push_back(result);
        }
        return results;
    }
};