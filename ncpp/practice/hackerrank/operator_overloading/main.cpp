#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix {
	public:
		std::vector<std::vector<int>> a;

		// working
		/*Matrix operator+(Matrix& other) {
			Matrix tempMatrix;
			for (int i = 0; i < this->a.size(); ++i) {
				std::vector<int> temp;
				for (int j = 0; j < this->a.at(i).size(); ++j) {
					temp.push_back(this->a.at(i).at(j) + other.a.at(i).at(j));
				}
				tempMatrix.a.push_back(temp);
			}
			return tempMatrix;
		}*/

		Matrix& operator+(Matrix& other) {
			for (int i = 0; i < other.a.size(); ++i) {
				for (int j = 0; j < other.a.at(i).size(); ++j) {
					this->a[i][j] += other.a.at(i).at(j);
				}
			}
			return *this;
		}
};

int main () {
	int cases,k;
	cin >> cases;
	for(k=0;k<cases;k++) {
		Matrix x;
		Matrix y;
		Matrix result;
		int n,m,i,j;
		cin >> n >> m;
		for(i=0;i<n;i++) {
			vector<int> b;
			int num;
			for(j=0;j<m;j++) {
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for(i=0;i<n;i++) {
			vector<int> b;
			int num;
			for(j=0;j<m;j++) {
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}

		//for (i = 0; i < n; i++) {
			//for (j = 0; j < m; j++) {
				//cout << x.a[i][j] << " ";
			//}
		//}

		result = x+y;
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) {
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
