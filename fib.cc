#include <cstdio>

using namespace std;

long long fib(int n){
  if(n == 0)
    return 0;
  else if(n == 1)
    return 1;
  else
    return fib(n-1) + fib(n-2);
}

int main(){
  int n;
  scanf("%d", &n);
  
  long long answer = fib(n);
  
  printf("%lld\n", answer);
  
  return 0;
}
