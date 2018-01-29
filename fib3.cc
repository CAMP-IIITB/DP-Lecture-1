#include <cstdio>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  
  long long f[n+1];
  
  f[0] = 0;
  f[1] = 1;
  for(int i = 2; i <= n; i++)
    f[i] = f[i-1] + f[i-2];
    
  printf("%lld\n", f[n]);
  
  return 0;
}
