class Solution {
public:
    string stringHash(string s, int k) {
        int number = s.length() / k;
        string ans = "";
        int i= 0;
        int j = k-1;
        while(j<s.length()){
            int curr_sum=0;
            while(i<=j){
             curr_sum += (int)(s[i] - 'a');
             i++;
            }
            int hash = curr_sum % 26;
            ans.push_back((char)(hash + 'a'));
            i=j+1;
            j = j+k;       
        }
        return ans;
    }
};