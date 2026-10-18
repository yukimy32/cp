#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<ll> A(N);
	ll S = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		S += A[i];
	}
	ll D = S / M;
	vector<int> dp(1 << N);
	for (int i = 1; i < (1 << N); i++) {
		int m = 0; ll w = 0;
		for (int j = 0; j < N; j++) {
			if ((i >> j) & 1) {
				m = max(m, dp[i ^ (1 << j)]);
				w += A[j];
			}
		}
		dp[i] = m + (w % D == 0);
	}
	cout << M - dp[(1 << N) - 1] << '\n';
}