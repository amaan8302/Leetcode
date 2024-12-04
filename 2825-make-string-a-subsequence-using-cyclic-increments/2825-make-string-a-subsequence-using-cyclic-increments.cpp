class Solution {
public:
    bool solve(int i , int j , string str1, string str2)
    {
        if(j==str2.length())
            return true;
        if(i == str1.length())
            return false;
        while(i<str1.length() && j<str2.length())
        {   
            
            if(str1[i]==str2[j] || str1[i]+1==str2[j] || str1[i]-25 == str2[j])
                j++;
            i++;
        }
        return j==str2.length();
    }
    bool canMakeSubsequence(string str1, string str2) 
    {
        return solve(0,0,str1,str2);
    }
};