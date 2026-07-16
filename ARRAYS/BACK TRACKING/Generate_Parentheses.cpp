#include <iostream>
#include <vector>
#include <string>
using namespace std;

void generateParentheses(int open, int close, int n, string current, vector<string> &result)
{
    // Base case
    if (current.length() == 2 * n)
    {
        result.push_back(current);
        return;
    }

    // Add '(' if possible
    if (open < n)
    {
        generateParentheses(open + 1, close, n, current + "(", result);
    }

    // Add ')' if it won't make the string invalid
    if (close < open)
    {
        generateParentheses(open, close + 1, n, current + ")", result);
    }
}

int main()
{
    int n;

    cout << "Enter number of pairs: ";
    cin >> n;

    vector<string> result;

    generateParentheses(0, 0, n, "", result);

    cout << "\nValid Parentheses are:\n";

    for (string s : result)
    {
        cout << s << endl;
    }

    return 0;
}