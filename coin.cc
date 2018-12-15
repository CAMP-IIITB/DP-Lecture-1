// Given an infinite number of coins of denominations
// coins[0], coins[1], ..., coins[n-1], can you combine
// these coins to form an amount of "amount" coins?

#include <cstdio>

using namespace std;

int main(){
  int n;        // number of coins
  scanf("%d", &n);
  
  int coins[n]; // value of each coin
  for(int i = 0; i < n; i++)
    scanf("%d", &coins[i]);
    
  int amount;   // amount to make
  scanf("%d", &amount);
    
  bool dp[amount+1];
  dp[0] = true;
  
  for(int i = 1; i <= amount; i++){
    dp[i] = false; // initially the value is initialize to false
    for(int j = 0; j < n; j++){
      if(coins[j] <= i and dp[i-coins[j]] == true){
        dp[i] = true;
        break;
      }
    }
  }
  
  if(dp[amount] == true){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }
  
  return 0;
}
