/*

Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        map<string,vector<string> > mp;
        int i,n=strs.size();
        for(i=0;i<n;++i)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
            mp[str].push_back(strs[i]);
        }
        map<string,vector<string> > :: iterator it;
        for(it=mp.begin();it!=mp.end();++it)
        {
            vector<string> v=it->second;
            res.push_back(v);            
        }
        return res;
    }
};
