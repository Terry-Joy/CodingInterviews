class Solution {
private:
    int n, m;
    bool vis[205][205];
public:
    bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j];
    }
	bool dfs(int i, int j, int len, vector<vector<char>> &board, string word) {
		if(!check(i, j) || word[len] != board[i][j])
			return false;
		if(len == word.size() - 1)
			return true;
		vis[i][j] = true;	
		bool f = 0;
		f = dfs(i + 1, j, len + 1, board, word) || dfs(i, j + 1, len + 1, board, word) ||
			dfs(i - 1, j, len + 1, board, word) || dfs(i, j - 1, len + 1, board, word);
		vis[i][j] = false;
		return f;
	}   
	bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size();
		bool ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == word[0]) {
					if(dfs(i, j, 0, board, word))
						return true;
				}
			}
		}
		return false;
	}
};