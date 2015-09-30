// https://www.hackerrank.com/contests/code-cpp-september-2015/challenges/operator-overloading
#include <iostream>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {}
    Matrix operator +(const Matrix &m) const {
        int row = a.size();
        Matrix x;
        x.a.resize(row);
        for (int r = 0; r < row; r++) {
            int col = a[r].size();
            x.a[r].resize(col);
            for (int c = 0; c < col; c++) {
                x.a[r][c] = a[r][c] + m.a[r][c];
            }
        }
        return x;
    }
    vector<vector<int> > a;
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
