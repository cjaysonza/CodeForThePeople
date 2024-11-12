#include <iostream>
using namespace std;

void showTable(char array1[3][3]);
void showDiagonal1(char array1[3][3]);
void showDiagonal2(char array1[3][3]);

int main() {
    char array1[3][3] = {
        {'A', 'B', 'C'},
        {'D', 'E', 'F'},
        {'G', 'H', 'I'},
    };
    cout << "Show Table" << endl;
    showTable(array1);

    cout << endl << endl;

    cout << "Show Diagonal Values" << endl;
    showDiagonal1(array1);
    cout << endl;
    showDiagonal2(array1);
    cout << endl;
    cout << endl;

    return 0;
}

void showTable(char array1[3][3]) {
    for (int row = 0; row < 3; row++) {
        for (int column = 0; column < 3; column++) {
            cout << array1[row][column] << " ";
        }
        cout << endl;
    }
}

void showDiagonal1(char array1[3][3]) {
    // NW to SE --- AEI
    for (int diagonal = 0; diagonal < 3; diagonal++) {
        cout << array1[diagonal][diagonal] << " ";
    }
    cout << endl;

    // NE to SW --- GEC
    for (int row1 = 2, column1 = 0; row1 >= 0 && column1 < 3;
         row1--, column1++) {
        cout << array1[row1][column1] << " ";
    }
    cout << endl;
}

void showDiagonal2(char array1[3][3]) {
    // SE to NW --- IEA
    for (int diagonal3 = 2; diagonal3 >= 0; diagonal3--) {
        cout << array1[diagonal3][diagonal3];
        cout << " ";
    }
    cout << endl;
    // SW to NE --- CEG
    for (int diagonal4 = 0; diagonal4 < 3; diagonal4++) {
        cout << array1[diagonal4][2 - diagonal4] << " ";
    }
}
