INF = 10 ** 9


res = INF
mat = list()
vis = list()

def all_path_visited() -> bool:
    if False in vis:
        return False
    return True

def depth_first_search(k: int, curr: int, temp: int) -> None:
    global res
    if(all_path_visited()):
        temp += mat[curr][k - 1] + mat[k - 1][0]
        res = min(res, temp)
    for i in range(len(vis)):
        if not vis[i]:
            vis[i] = True
            depth_first_search(k, i, temp + mat[curr][i])
            vis[i] = False



def get_shortest_path(n, k) -> int:
    vis[0] = True
    depth_first_search(k, 0, 0)
    return res

def solve_testcase() -> None:
    k = int(input())
    n = int(input())

    global mat
    global vis

    if mat != None:
        mat.clear()
    if vis != None:
        vis.clear()

    for _ in range(n):
        mat.append(list(map(int, input().split())))
        vis.append(False)

    print(get_shortest_path(n, k))


def main() -> None:
    t = int(input())

    for _ in range(t):
        solve_testcase()

if __name__ == "__main__":
    main()
