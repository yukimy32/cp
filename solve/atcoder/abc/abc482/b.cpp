#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	vector<string> S(5);
	for (int i = 0; i < 5; i++) cin >> S[i];
	int ans = 5;
	for (int i = 0; i < 5; i++) {
		ans = min(ans, (int)count(S[i].begin(), S[i].end(), '.'));
		int c = 0;
		for (int j = 0; j < 5; j++) c += (S[j][i] == '.');
		ans = min(ans, c);
	}
	int c1 = 0, c2 = 0;
	for (int i = 0; i < 5; i++) {
		if (S[i][i] == '.') c1++;
		if (S[i][4 - i] == '.') c2++;
	}
	ans = min({ans, c1, c2});
	cout << ans << '\n';
}