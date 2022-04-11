#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//binary search
pair<int, int> Search_range(const vector<int>& arr, const int n) {
	int i = 0, j = arr.size() - 1;
	int half;
	while (1) {
		half = (i + j + 1) / 2;
		if (arr[half] == n) {
			if (!half) {
				//n이 중복이면 이미 S에 n이 있었다는 것이므로 구간을 구할 수 없다.
				if (arr[half + 1] == n) return make_pair(0, 0);
				return make_pair(1, n);
			}
			if (half == arr.size() - 1) {
				if (arr[half - 1] == n) return make_pair(0, 0);
				return make_pair(arr[half - 1] + 1, n);
			}
			if (arr[half - 1] == n || arr[half + 1] == n) return make_pair(0, 0);
			return make_pair(arr[half - 1] + 1, arr[half + 1] - 1);
		}
		if (arr[half] < n) i = half + 1;
		else j = half - 1;
	}
}
int Count(const pair<int, int>& range, const int n) {
	if (!range.second || range.first == range.second) return 0;
	//n ~ max 까지는 시작범위는 항상 n이며 끝나는 범위는 max - n개 존재 = more
	//[10, 11], [10, 12]
	//min ~ n 까지는 i부터 n 이상의 수 ~ max의 범위 = (more + 1) * less
	//[9, 10], [9, 11], [9, 12]
	int less = n - range.first, more = range.second - n;
	int ans = (more + 1) * less + more;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<int> arr;
	int L, N;
	cin >> L;
	while (L--) {
		cin >> N;
		arr.push_back(N);
	}
	cin >> N;
	arr.push_back(N); 
	sort(arr.begin(), arr.end());
	//N을 S에 넣고 정렬하여 인접한 두 원소를 범위로 삼는다.
	pair<int, int> range = Search_range(arr, N);
	cout << Count(range, N) << "\n";
}
