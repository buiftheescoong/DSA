
#include <iostream>
#include <vector>

using namespace std;



int to_hop(int k, int n) {
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	return to_hop(k - 1, n - 1) + to_hop(k, n - 1);
}

int main() {
  int V, E;
  cin >> V >> E;

  int num_combinations = to_hop(E,V*(V-1)/2);

  cout << num_combinations << endl;

  return 0;
}

