#include <iostream>
#include <queue>
using namespace std;
int M, N, K;
bool map[500][500];

void BFS(const int i, const int j) {
	queue<pair<int, int>> q;
	pair<int, int> pos;
	q.push(make_pair(i, j));
	map[i][j] = false;
	while (!q.empty()) {
		pos = q.front();
		q.pop();
		//up
		if (!pos.second && map[pos.first][pos.second - 1]) {
			q.push(make_pair(pos.first, pos.second - 1));
			map[pos.first][pos.second - 1] = false;
		}
		//down
		if (pos.second != N - 1 && map[pos.first][pos.second + 1]) {
			q.push(make_pair(pos.first, pos.second + 1));
			map[pos.first][pos.second + 1] = false;
		}
		//left
		if (!pos.first && map[pos.first - 1][pos.second]) {
			q.push(make_pair(pos.first - 1, pos.second));
			map[pos.first - 1][pos.second] = false;
		}
		//right
		if (pos.first != M - 1 && map[pos.first + 1][pos.second]) {
			q.push(make_pair(pos.first + 1, pos.second));
			map[pos.first + 1][pos.second] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, m, n;
	cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		while (K--) {
			cin >> m >> n;
			map[m][n] = true;
		}
		int group = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j]) {
					BFS(i, j);
					group++;
				}
			}
		}
		cout << group << "\n";
	}
}
