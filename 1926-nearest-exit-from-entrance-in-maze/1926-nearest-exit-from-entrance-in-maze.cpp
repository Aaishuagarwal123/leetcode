class Solution {
public:
    int nearestExit(vector<vector<char>>& m, vector<int>& e) {
        queue<pair<int,int>>q;
      int n=m.size();
      int n1=m[0].size();
      q.push({e[0],e[1]});
      int move=0;
      vector<vector<int>>dir={{0,1},{0,-1},{-1,0},{1,0}};
      m[e[0]][e[1]]='+';
      while(!q.empty())
      {
        int size=q.size();
        
        while(size--)
        {
          int x=q.front().first;
          int y=q.front().second;
          q.pop();
          if(x==0||x==n-1||y==0||y==n1-1)
          {
            if(x!=e[0]||y!=e[1])
              return move;
          }
          for(int k=0;k<4;k++)
          {
            int nx=x+dir[k][0];
            int ny=y+dir[k][1];
            if(nx>=n||nx<0||ny>=n1||ny<0||m[nx][ny]=='+')
              continue;
            q.push({nx,ny});
            m[nx][ny]='+';
          }
        }
        move++;
      }
      return -1;
    }
};