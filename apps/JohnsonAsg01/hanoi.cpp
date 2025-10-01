#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void moveDisks(int, int, int, int);
void printIt(int, int, int);

int main() {
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;

    cout << "Recursive Towers of Hanoi Timing\n";

    for (auto numdisks : { 5, 10, 15, 20, 25, 30, 35 }) {
        auto start = high_resolution_clock::now();

        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Disks: " << numdisks
            << " | Time: " << duration.count() << " ms\n";
    }
    return 0;
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
    if (num > 0) {
        moveDisks(num - 1, fromPeg, tempPeg, toPeg);
        // printIt(num, fromPeg, toPeg);
        moveDisks(num - 1, tempPeg, toPeg, fromPeg);
    }
}

void printIt(int disk, int fromPeg, int toPeg) {
    
    // cout << "Move disk " << disk
    //      << " from peg " << fromPeg
    //      << " to peg " << toPeg << endl;
}
