// You are given an n x n grid. Each grid contains some number of coins.
// You are initially located at co-ordinate (0,0), i.e., the top left corner
// of the grid and want to reach the co-ordinate (n-1, n-1), i.e. the bottom
// right corner of the grid. Each time you visit a cell in this grid, you must
// collect all the coins present in that cell. You would like to reach your
// destination and maximize the number of coins collected under the constraint
// that from cell (i,j) you can only move to cells (i+1,j) or (i,j+1). 
// Calculate the maximum number of coins that you can collect.

#include <cstdio>

using namespace std;

int main(){
  int n;        // number of coins
  scanf("%d", &n);
  
  int grid[n][n];
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &grid[i][j]);
    }
  }
  
  int dp[n][n];
  
  // handle the base cases
  dp[0][0] = grid[0][0];
  for(int i = 1; i < n; i++){
    dp[i][0] = dp[i-1][0] + grid[i][0];
    dp[0][i] = dp[0][i-1] + grid[0][i];
  }
  
  for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
      dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j];
    }
  }
  
  printf("%d\n", dp[n-1][n-1]);
  
  return 0;
}
