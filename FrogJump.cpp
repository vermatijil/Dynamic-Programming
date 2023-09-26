#include <iostream>
#include <vector>

using namespace std;

int dp(int n, vector<int> &jump)
{
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int index = 1; index < n; index++)
    {
        int fs = dp[index - 1] + abs(jump[index] - jump[index - 1]);
        int sc = INT_MAX;
        if (index > 1)
            sc = dp[index - 2] + abs(jump[index] - jump[index - 2]);
        dp[index] = min(fs, sc);
    }
    return dp[n - 1];
}

int helper_memo(vector<int> &ans, vector<int> &jump, int k, int index)
{
    if (index == 0)
        return 0;
    if (ans[index] != -1)
        return ans[index];
    int one = helper(k, jump, index - 1) + abs(jump[index] - jump[index - 1]);
    int two = INT_MAX;
    if (index > 1)
        two = helper(k, jump, index - 2) + abs(jump[index] - jump[index - 2]);
    ans[index] = min(one, two);
    return ans[index];
}

int memo(int k, vector<int> &jump)
{
    int index = 0;
    vector<int> ans(k + 1, -1);
    return helper_memo(ans, jump, k, index);
}

int helper(int k, vector<int> &jump, int index)
{
    if (index == 0)
        return 0;
    int one = helper(k, jump, index - 1) + abs(jump[index] - jump[index - 1]);
    int two = INT_MAX;
    if (index > 1)
        two = helper(k, jump, index - 2) + abs(jump[index] - jump[index - 2]);
    int ans = min(one, two);
    return ans;
}

int forgJump(int k, vector<int> &jump)
{
    return helper(k, jump, k - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> jump(n);
        for (int i = 0; i < n; i++)
        {
            cin >> jump[i];
        }
        int k;
        cin >> k;
        cout << forgJump(k, jump);
        cout << endl;
    }
    return 0;
}