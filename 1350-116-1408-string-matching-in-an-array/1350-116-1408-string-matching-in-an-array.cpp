class Solution {
public:
    // bool solve()
    vector<string> stringMatching(vector<string>& words) 
    {
         set<string> result;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j && words[j].find(words[i]) != string::npos)
                {
                    result.insert(words[i]);
                    break;
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};