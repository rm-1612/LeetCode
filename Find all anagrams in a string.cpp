/*

Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".


*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p1[26]={0};
        for(int i=0;i<p.length();++i)
        {
            ++p1[p[i]-'a'];
        }
        vector<int > v;
        for(int i=0;i<s.length();++i)
        {
            string str=s.substr(i,p.length());
            int q[26]={0};
            for(int j=0;j<str.length();++j)
            {
                ++q[str[j]-'a'];
            }
            int k;
            for(k=0;k<26;++k)
            {
                if(p1[k]!=q[k])
                    break;
            }
            if(k==26)
                v.push_back(i);
        }
        return v;
        
    }
};
