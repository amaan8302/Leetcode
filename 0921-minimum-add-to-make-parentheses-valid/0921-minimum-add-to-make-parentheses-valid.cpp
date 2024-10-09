class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        int balance = 0, moves = 0;
        for (char c : s) 
        {
            if (c == '(') 
                balance++;
            else
            {
                if (balance > 0) 
                    balance--;
                else 
                    moves++;
            }
        }
        return moves + balance; 
    }
};