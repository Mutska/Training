/* How do you add? */
// top-down
#include <iostream>
#include <cstring>
using namespace std;
int N, K, memo[110][110];
int ways(int N, int K) {
  if (K == 1) // only can use 1 number to add up to N
    return 1; // the answer is definitely 1, that number itself
  else if (memo[N][K] != -1)
    return memo[N][K];
  // if K > 1, we can choose one number from [0..N] to be one of the number and recursively compute the rest
  int total_ways = 0;
  for (int split = 0; split <= N; split++)
    total_ways = (total_ways + ways(N - split, K - 1)) % 1000000; // we just need the modulo 1M
  return memo[N][K] = total_ways; // memoize them
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(memo, -1, sizeof memo);
  while (cin >> N >> K, (N || K)) cout << ways(N, K) << "\n"; // some recursion formula + top down DP
  return 0;
}
