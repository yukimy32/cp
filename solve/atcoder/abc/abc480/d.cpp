#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	vector<ll> P(N + 1), T(N + 1);
	for (int i = 0; i < N; i++) P[i + 1] = P[i] + A[i];
	for (int i = 0; i < N; i++) T[i + 1] = T[i] + P[i + 1];
	auto S = [&] (ll x) -> ll {
		ll le = 0, ri = N;
		while (le + 1 < ri) {
			ll mi = (le + ri) >> 1;
			if (mi * (mi + 1) <= 2 * x) le = mi;
			else ri = mi;
		}
		return T[le] + P[x - le * (le + 1) / 2];
	};
	while (Q--) {
		ll L, R; cin >> L >> R;
		cout << S(R) - S(L - 1) << '\n';
	}
}