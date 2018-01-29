#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int dist(int x1, int y1, int x2, int y2){
  return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
  int n; // number of orders to serve
  scanf("%d", &n);
  
  int x[n+2], y[n+2];
  for(int i = 0; i < n+2; i++){
    scanf("%d %d", &x[i], &y[i]);
  }
  
  // x[0], y[0] is location of truck 1
  // x[1], y[1] is location of truck 2  
  
  const int INF = 1e9; // a very large number  
    
  int dp[n+2][n+2];
  dp[0][1] = 0;
  
  // serving the i'th order
  for(int i = 2; i < n+2; i++){
    int a, b;
    
    // case 1: truck 1 is at i
    a = i;
    for(b = 1; b < i; b++){
      if(b == a-1){ // we must determine where truck 1 moved from
        int mn = INF;
        
        for(int preva = 0; preva < b; preva++){
          if(preva == 1) continue;
          mn = min(mn, dp[preva][b] + dist(x[a], y[a], x[preva], y[preva]));
        }
        
        dp[a][b] = mn;
      }
      else{ // in this case we know that truck 1 moved from a-1 to a
        dp[a][b] = dp[a-1][b] + dist(x[a], y[a], x[a-1], y[a-1]);
      }
    }
    // end of case 1
    
    // case 2: truck 2 is at i
    // what follows is symmetric with case 1
    b = i;
    for(a = 0; a < i; a++){
      if(a == 1) continue; // truck 1 cannot be at location of truck 2
      
      if(a == b-1){
        int mn = INF;
        
        for(int prevb = 0; prevb < a; prevb++){
          if(prevb == 1) continue;
          mn = min(mn, dp[a][prevb] + dist(x[b], y[b], x[prevb], y[prevb]));
        }
        
        dp[a][b] = mn;
      }
      else{
        dp[a][b] = dp[a][b-1] + dist(x[b], y[b], x[b-1], y[b-1]);
      }
    }
    // end of case 2
    
  }
  
  int final_ans = INF;
  
  // if truck 1 served the final order
  for(int i = 1; i < n+2; i++){
    final_ans = min(final_ans, dp[n+1][i]);
  }
  
  // if truck 2 served the final order
  for(int i = 0; i < n+2; i++){
    if(i == 1) continue;
    final_ans = min(final_ans, dp[i][n+1]);
  }
  
  printf("%d\n", final_ans);

  return 0;    
}
