// main file

#include <iostream>
#include <vector>

using namespace std;

vector<int> adj_list[10001];
int vis[100001];
int dis[100001];

void dfs(int n, int d) {
	vis[n] = 1;
	dis[n] = d;
	printf("n[%d, %d] -> ", n, d);
	size_t sz = adj_list[n].size();
	for(size_t i = 0; i < sz; i++) {
		int child = adj_list[n][i];
		if(!vis[child]) {
			dfs(child, d + 1);
		}
	}
}

int main(int argc, char **argv) {
	int V{}, E{};
	scanf("%d %d", &V, &E);
	for(size_t i = 0; i < E; i++) {
		int v1{}, v2{};
		scanf("%d %d", &v1, &v2);
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}
	dfs(2, 0);
	return 0;
}