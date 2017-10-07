class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        if(strs.size()==0) return res;
    
        int i =0;
        for(auto s: strs){
            sort(s.begin(), s.end());                   //先排序每個string
            map[s].push_back(strs[i]);                  //排序完作為key 
            i++;
        } 
        //從map 遍歷
        for(auto m: map){
            sort(m.second.begin(), m.second.end());     //對 eat tea ate 做排序
            res.push_back(m.second);
        }
        return res;
    }
};
