#include <cstdio>

using namespace std;

const int N = 30;

long long memo[N];

int fib(int n){
  if(memo[n] >= 0)
    return memo[n];
  
  memo[n] = fib(n-1) + fib(n-2);
  
  return memo[n];
}

int main(){
  int n;
  scanf("%d", &n);
  
  for(int i = 0; i < n; i++){
    memo[i] = -1;
  }
  
  memo[0] = 0;
  memo[1] = 1;
  
  long long answer = fib(n);
  
  printf("%lld\n", answer);
  
  return 0;
}
