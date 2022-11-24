class Solution {
public:
  int n;
  int m;
  vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
  string word;
  bool helper(int i,int j,vector<vector<char>>&grid,int ind)
  {
    if(ind>=word.length())
      return true;
    if(i>=n||j>=m||i<0||j<0||grid[i][j]!=word[ind])
      return false;
    char ch=grid[i][j];
    grid[i][j]=' ';
    for(int k=0;k<4;k++)
    {
      int nx=i+dir[k][0];
      int ny=j+dir[k][1];
      if(helper(nx,ny,grid,ind+1))
        return true;
    }
    grid[i][j]=ch;
    return false;
  }
    bool exist(vector<vector<char>>&grid, string word1) {
        n=grid.size();
    m=grid[0].size();
      word=word1;
      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++)
        {
          if(grid[i][j]==word[0])
          {
            if(helper(i,j,grid,0))
              return true;
          }
        }
      }
      return false;
    }
};