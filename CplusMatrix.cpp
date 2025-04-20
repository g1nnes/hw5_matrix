#include <iostream>
#include<vector>

using namespace std;
class Matrix {
public:
    vector<vector<int>> v;
    Matrix(vector<vector<int>> w) {
        v = w;
    }
    void printMatrix() {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                cout<<v[i][j]<<" ";
            }
            cout << endl;
        }
    }

    void matrixAdd(vector<vector<int>> multiplier) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                v[i][j] = v[i][j] + multiplier[i][j];
            }
        }
    }

    void matrixMultiply(int constant) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[0].size(); j++) {
                v[i][j] = v[i][j] * constant;
            }
        }
    }
    void matrixMultiply(vector<vector<int>> multiplier) {
        int shrunkenRows = 0;
        int shrunkenColumn = 0;
        if (multiplier.size() < v.size()) {
            shrunkenRows = multiplier.size();
        }
        else {
            shrunkenRows = v.size();
        }

        if (multiplier[0].size() < v[0].size()) {
            shrunkenColumn = multiplier[0].size();
        }
        else {
            shrunkenColumn = v[0].size();
        }

        vector<vector<int>> newMatrix(shrunkenRows, vector<int>(shrunkenColumn, 0));
        for (int i = 0; i < shrunkenRows; i++) {
            for (int j = 0; j < shrunkenColumn; j++) {
                newMatrix[i][j] = v[i][j] * multiplier[i][j];
            }
        }
        v = newMatrix;
    }
    void transposeMatrix() {
        vector<vector<int>> newMatrix(v[0].size(), vector<int>(v.size(), 0));
        for (int i = 0; i < newMatrix.size(); i++) {
            for (int j = 0; j < newMatrix[0].size(); j++) {
                newMatrix[i][j] = v[j][i];
            }
        }
        v = newMatrix;
    }
};

int main()
{
    vector<vector<int>> test_matrix = {
        {6, 4},
        {8, 3}
    };
    Matrix a(test_matrix);
    cout << "A: " << endl;
    a.printMatrix();
    cout << endl;

    test_matrix = {
    {1,2,3},
    {4,5,6}
    };
    Matrix b(test_matrix);
    cout << "B: " << endl;
    b.printMatrix();
    cout << endl;

    test_matrix = {
    {2,4,6},
    {1,3,5}
    };
    Matrix c(test_matrix);
    cout << "C:" << endl;
    c.printMatrix();
    cout << endl;

    b.matrixMultiply(3);
    c.transposeMatrix();
    b.matrixMultiply(c.v);
    a.matrixAdd(b.v);
    a.printMatrix();
}
