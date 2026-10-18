#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int N, K, T; cin >> N >> K >> T;
	vector<pair<int, int>> P;
	for (int i = 0; i < N; i++) {
		int A; cin >> A;
		P.push_back({min(T, A), min(T, A + K)});
	}
	vector<pair<int, int>> Q;
	sort(P.begin(), P.end());
	for (auto [l, r]: P) {
		if (Q.size() == 0 || Q.back().second < l) {
			Q.push_back({l, r});
		} else {
			Q.back().second = max(Q.back().second, r);
		}
	}
	int ans = (Q[0].first + K - 1) / K + (T - Q.back().second + K - 1) / K;
	for (int i = 0; i < Q.size() - 1; i++) {
		ans += (Q[i + 1].first - Q[i].second + K - 1) / K;
	}
	cout << ans << '\n';
}