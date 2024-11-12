#include <iostream>
using namespace std;

void findHome(int x, int y);

int main() {
    findHome(3, 4);
    return 0;
}

void findHome(int x, int y) {
    if (x != 1) {
        cout << "Person Moved Left..." << endl;
        return findHome(x - 1, y);
    }
    if (y != 1) {
        cout << "Person Moved Down..." << endl;
        return findHome(x, y - 1);
    }
    cout << "Person is now Home!" << endl;
}
