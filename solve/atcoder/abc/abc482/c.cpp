#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int H, W, N, Q; cin >> H >> W >> N >> Q;
	vector<int> R(N), C(N);
	for (int i = 0; i < N; i++) {
		cin >> R[i] >> C[i];
	}
	sort(R.begin(), R.end());
	sort(C.begin(), C.end());
	while (Q--) {
		int t, x, y; cin >> t >> x >> y;
		if (t == 1) {
			cout << lower_bound(R.begin(), R.end(), y + 1) - lower_bound(R.begin(), R.end(), x) << '\n';
		} else {
			cout << lower_bound(C.begin(), C.end(), y + 1) - lower_bound(C.begin(), C.end(), x) << '\n';
		}
	}
}