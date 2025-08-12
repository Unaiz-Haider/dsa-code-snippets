class Solution {
  public:
  
  void findPaths(vector<vector<int>> &maze, vector<string> &ans, string &temp, int end, int i, int j){
      
      if(i == end &&  j == end){
          ans.push_back(temp);
          return;
      }
      
      maze[i][j] = 0;
      
      if(i < end && maze[i + 1][j] == 1){
            temp.push_back('D');
            findPaths(maze, ans, temp, end, i + 1, j);
            temp.pop_back();
      }
      
      if(j > 0 && maze[i][j -1] == 1){
            temp.push_back('L');
            findPaths(maze, ans, temp, end, i, j - 1);
            temp.pop_back();
      }
      
      if(j < end && maze[i][j + 1] == 1){
            temp.push_back('R');
            findPaths(maze, ans, temp, end, i, j + 1);
            temp.pop_back();
      }
      
      if(i > 0 && maze[i - 1][j] == 1){
            temp.push_back('U');
            findPaths(maze, ans, temp, end, i - 1, j);
            temp.pop_back();
      }
      
       maze[i][j] = 1;
      
  }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        
        vector<string> ans;
        
        string temp;
        
        int n = maze.size() - 1;
        
        findPaths(maze, ans, temp, n, 0, 0);
        
        return ans;
    }
};