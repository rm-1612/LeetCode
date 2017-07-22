/*

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i,j,n=haystack.size(),m=needle.size();
        if(m==0)
            return 0;
        for(i=0;i<n;++i)
        {
            int k;
            if(haystack[i]==needle[0])
            {
                for(k=i,j=0;k<n && j<m;++k,++j)
                {
                    if(haystack[k]!=needle[j])
                    {
                        break;
                    }
                }
                if(j==m)
                    return k-m;
            }
        }
        return -1;
        
    }
};
