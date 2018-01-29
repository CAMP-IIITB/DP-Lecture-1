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
