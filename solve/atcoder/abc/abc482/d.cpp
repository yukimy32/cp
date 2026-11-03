#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N; cin >> N;
	vector<ll> X(N);
	for (int i = 0; i < N; i++) cin >> X[i];
	for (int i = 0; i < N; i++) {
		if (i == 0 || i == N - 1) {
			cout << (X[N - 1] - X[0]) / 2 << '\n';
			continue;
		}
		ll ans = 1e18;
		ans = min(ans, max((X[i] - X[0]) / 2, (X[N - 1] - X[i - 1]) / 2));
		ans = min(ans, max((X[N - 1] - X[i]) / 2, (X[i + 1] - X[0]) / 2));
		cout << ans << '\n';
	}
}