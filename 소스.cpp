#include <iostream>
#include <queue>
using namespace std;
int M, N;
bool map[1000][1000];

int BFS(const int row, const int col) {
	int ans = 0;
	queue<pair<int, int>> q1, q2;
	pair<int, int> pos;
	q1.push({ row,col });
	while (!q1.empty() || !q2.empty()) {
		cout << "\nq1, ans = " << ans << "\n";
		while (!q1.empty()) {
			pos = q1.front();
			q1.pop();
			cout << "pos = (" << pos.first<<", "<<pos.second << "), ";
			//up
			if (pos.first && !map[pos.first - 1][pos.second]) {
				map[pos.first - 1][pos.second] = true;
				q2.push({ pos.first - 1,pos.second });
			}
			//down
			if (pos.first != N - 1 && !map[pos.first + 1][pos.second]) {
				map[pos.first + 1][pos.second] = true;
				q2.push({ pos.first + 1,pos.second });
			}
			//left
			if (pos.second && !map[pos.first][pos.second - 1]) {
				map[pos.first][pos.second - 1] = true;
				q2.push({ pos.first,pos.second - 1 });
			}
			//right
			if (pos.second != M - 1 && !map[pos.first][pos.second + 1]) {
				map[pos.first][pos.second + 1] = true;
				q2.push({ pos.first,pos.second + 1 });
			}
		}
		if (q2.empty()) return ans;
		ans++;
		cout << "\nq2, ans = " << ans << "\n";
		while (!q2.empty()) {
			pos = q2.front();
			q2.pop();
			cout << "pos = (" << pos.first << ", " << pos.second << "), ";
			if (pos.first && !map[pos.first - 1][pos.second]) {
				map[pos.first - 1][pos.second] = true;
				q1.push({ pos.first - 1,pos.second });
			}
			if (pos.first != N - 1 && !map[pos.first + 1][pos.second]) {
				map[pos.first + 1][pos.second] = true;
				q1.push({ pos.first + 1,pos.second });
			}
			if (pos.second && !map[pos.first][pos.second - 1]) {
				map[pos.first][pos.second - 1] = true;
				q1.push({ pos.first,pos.second - 1 });
			}
			if (pos.second != M - 1 && !map[pos.first][pos.second + 1]) {
				map[pos.first][pos.second + 1] = true;
				q1.push({ pos.first,pos.second + 1 });
			}
		}
		if (q1.empty()) return ans;
		ans++;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j]) ans += BFS(i, j);
		}
	}
	if (!ans) cout << "-1\n";
	else  cout << ans << "\n";
}