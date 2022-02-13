#include <iostream>
#include <vector>

using namespace std;

vector<int>
spiralOrder(const vector<vector<int>>& A)
{
  vector<int> res{};

  int i{}, j{}, li = A.size() - 1, lj = A[0].size() - 1;

  while (i <= li && j <= lj) {
    printf("%d, %d, %d, %d\n", i, j, li, lj);
    for (int k = j; k <= lj; k++) {  // row from top side
      res.push_back(A[i][k]);
    }
    i++;
    for (int k = i; k <= li; k++) {
      res.push_back(A[k][lj]);
    }
    lj--;
    if (i <= li) {
      for (int k = lj; k >= j; k--) {
        res.push_back(A[li][k]);
      }
    li--;
    }
    if (j <= lj) {
      for (int k = li; k >= i; k--) {
        res.push_back(A[k][j]);
      }
      j++;
    }
  }

  return res;
}

void
print_matrix(const vector<vector<int>>& arr)
{
  for (size_t i = 0; i < arr.size(); i++) {
    for (size_t j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j];
      if (j < arr[0].size() - 1)
        cout << ", ";
    }
    cout << "\n";
  }
}

int
main(void)
{
  int m{}, n{};
  cin >> m >> n;
  vector<vector<int>> arr;
  arr.resize(m, vector<int>(n));
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  print_matrix(arr);
  vector<int> res = spiralOrder(arr);
  for (size_t i = 0; i < res.size(); i++) {
    cout << res[i];
    if (i < res.size() - 1)
      cout << ", ";
  }
}
