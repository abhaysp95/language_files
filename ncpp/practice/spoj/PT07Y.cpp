#include <iostream>
#include <vector>

using namespace std;

vector<int> adj_list[10001];
int vis[10001];

void dfs(int n) {
	vis[n] = 1;
	for(size_t i = 0; i < adj_list[n].size(); i++) {
		int child = adj_list[n][i];
		if(vis[child] == 0) dfs(child);
	}
}

int main(int argc, char** argv) {
	int N = 0, E = 0;
	scanf("%d %d", &N, &E);
	for(int i = 0; i < E; i++) {
		int n1 = 0, n2 = 0;
		scanf("%d %d", &n1, &n2);
		adj_list[n1].push_back(n2);
		adj_list[n2].push_back(n1);
	}

	size_t cc = 0;
	for(int i = 1; i <= N; i++) {
		if(vis[i] == 0) dfs(i), cc++;
	}

	printf("%s\n", (cc == 1) ? "YES" : "NO");

	return 0;
}
