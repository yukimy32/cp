#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

unsigned int isqrt(unsigned long long N) {
	if (N == 0) return 0;
	unsigned long long x = 2ULL << ((63 ^ countl_zero(N)) >> 1);
	do {
		x = (x + N / x) >> 1;
	} while (N < x * x);
	return x;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	ll N; cin >> N;
	ll ans = 0;
	for (ll A = 1; A * (A + 1) * (A + 2) <= N; A++) {
		ans += max(0LL, (isqrt((unsigned long long)(A * A + 8 * N / A)) - 3 * A) / 4);
	}
	for (int M = 4; ; M++) {
		ll s = 0;
		for (ll A = 1; A * (A + 1) * (A + 2) <= N; A++) {
			ll le = 0, ri = pow((ld)N / A, (ld)1 / (M - 1)) - A + 1;
			while (le + 1 < ri) {
				ll mi = (le + ri) >> 1, x = N;
				for (int j = 0; j < M; j++) x /= A + mi * j;
				if (x > 0) le = mi;
				else ri = mi;
			}
			s += le;
			if (le == 0) break;
		}
		ans += s;
		if (s == 0) break;
	}
	cout << ans << '\n';
}