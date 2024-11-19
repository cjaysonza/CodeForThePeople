#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "math.h"
#include "stdlib.h"
using namespace std;

struct Grid {
    vector<char> grid;
    int w, h;

    Grid(int w, int h, char bg) : w(w), h(h) {
        grid = vector<char>();

        for (int i = 0; i < w * h; i++) {
            grid.push_back(bg);
        }
    }

    int index(int x, int y) {
        return y * w + x;
    }

    void display(ostream &out, char separator) {
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                out << grid[index(x, y)] << separator;
            }
            out << endl;
        }
    }

    bool inBounds(int x, int y) {
        return 0 <= x && x < w && 0 <= y && y < h;
    }

    // if len is -1, will stop on out of bounds
    void drawLine(int x, int y, int dx, int dy, int len, char c) {
        for (int i = 0; i != len && inBounds(x, y); i++) {
            grid[index(x, y)] = c;
            x += dx;
            y += dy;
        }
    }
};


bool executeCmd(ifstream& input, Grid &grid) {
    string cmd;
    input >> cmd;
    if (cmd == "init") {
        int w, h;
        char bg;
        input >> w >> h >> bg;
        grid = Grid(w, h, bg);
    }
    else if (cmd == "line") {
        int x, y, dx, dy;
        char c;
        input >> x >> y >> dx >> dy >> c;
        grid.drawLine(x, y, dx, dy, -1, c);
    }
    else if (cmd == "end") {
        return false;
    }
    return true;
}

int main() {
    const string FILE_IN = "in.txt";
    const string FILE_OUT = "out.txt";

    ifstream in(FILE_IN);
    ofstream out(FILE_OUT);

    Grid grid(1, 1, '-');
    while (executeCmd(in, grid)) {}
    grid.display(cout, ' ');

    return 0;

}
