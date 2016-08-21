#include"Header.h"

int minDistance(string word1, string word2)
{
	int m = word1.size(), n = word2.size();
	vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));//dp[i][j] stands for the edit distance of word1[0...i-1] to wrod2[0..j-1]
	for (int i = 0; i <=m; ++i)dp[i][0] = i;
	for (int j = 0; j <= n; ++j)dp[0][j] = j;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + (word1[i-1] == word2[j-1] ? 0 : 1));
		}
	}
	return dp[m][n];
}