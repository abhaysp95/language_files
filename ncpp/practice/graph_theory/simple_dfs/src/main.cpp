// main file

#include <iostream>
#include <vector>

using namespace std;

int vis[100001];
vector<int> adj_list[100001];

void dfs(int n) {
	vis[n] = 1;
	printf("%d -> ", n);
	for(int i = 0; i < adj_list[n].size(); i++) {
		// if child not visited
		if(vis[adj_list[n][i]] == 0) dfs(adj_list[n][i]);
	}
}

int main(int argc, char **argv) {
	int N{}, E{};
	scanf("%d %d", &N, &E);
	for(int i = 0; i < E; i++) {
		int n1 = 0, n2 = 0;
		scanf("%d %d", &n1, &n2);
		adj_list[n1].push_back(n2);
		adj_list[n2].push_back(n1);
	}
	dfs(1);
	return 0;
}