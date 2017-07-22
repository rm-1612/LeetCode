/*

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard.
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]

*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        vector<string> res;
        map<char,int> mp;
        mp['q']=1;
        mp['w']=1;
        mp['e']=1;
        mp['r']=1;
        mp['t']=1;
        mp['y']=1;
        mp['u']=1;
        mp['i']=1;
        mp['o']=1;
        mp['p']=1;
        mp['a']=2;
           mp['s']=2;
           mp['d']=2;
           mp['f']=2;
           mp['g']=2;
           mp['h']=2;
           mp['j']=2;
           mp['k']=2;
           mp['l']=2;
           mp['z']=3;
           mp['x']=3;
           mp['c']=3;
           mp['v']=3;
           mp['b']=3;
           mp['n']=3;
           mp['m']=3;
        int j;
           for(int i=0;i<words.size();++i)
           {
               int p=mp[tolower(words[i][0])];
               for( j=1;j<words[i].length();++j)
               {
                   if(mp[tolower(words[i][j])]!=p)
                       break;
               }
               if(j==words[i].length())
                   res.push_back(words[i]);
           }
        return res;
    }
};
