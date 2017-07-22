/*

Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5

*/

class Solution {
public:
    int countSegments(string s) {
        int i=0;
        int count=0; 
        while(i<s.length())
        {
            if(s[i]==' ')
            {
                while(s[i]==' ' && i<s.length())
                    ++i;
            }
            else 
            {
                ++count;
                while(s[i]!=' '&& i<s.length())
                    ++i;
            }
            
        }
        return count;
    }
};
