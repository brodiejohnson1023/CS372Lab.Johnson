#include <iostream>
#include <chrono>
#include <stack>
#include <cmath>
using namespace std;
using namespace std::chrono;

void moveDisks(int, stack<int>&, stack<int>&, stack<int>&);
void printIt(int, char, char);
void MoveDisksHelper(stack<int>&, stack<int>&, char, char);

int main() {
    cout << "Iterative Towers of Hanoi Timing\n";

    for (auto numdisks : { 5, 10, 15, 20, 25, 30, 35 }) {
        stack<int> source;
        stack<int> dest;
        stack<int> aux;

        auto start = high_resolution_clock::now();

        moveDisks(numdisks, source, aux, dest);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Disks: " << numdisks
            << " | Time: " << duration.count() << " ms\n";
    }
    return 0;
}

void moveDisks(int num, stack<int>& fromPeg, stack<int>& tempPeg, stack<int>& toPeg) {
    char s = 'S', d = 'D', a = 'A';
    if (num % 2 == 0) {
        char temp = d; d = a; a = temp;
    }
    int numberOfMoves = pow(2, num) - 1;
    for (int i = num; i >= 1; i--) {
        fromPeg.push(i);
    }
    for (int i = 1; i <= numberOfMoves; i++) {
        if (i % 3 == 0) MoveDisksHelper(tempPeg, toPeg, a, d);
        else if (i % 3 == 2) MoveDisksHelper(fromPeg, tempPeg, s, a);
        else MoveDisksHelper(fromPeg, toPeg, s, d);
    }
}

void MoveDisksHelper(stack<int>& source, stack<int>& dest, char s, char d) {
    int top1, top2;
    if (source.empty()) {
        top2 = dest.top(); dest.pop();
        source.push(top2);
        printIt(top2, d, s);
    }
    else if (dest.empty()) {
        top1 = source.top(); source.pop();
        dest.push(top1);
        printIt(top1, s, d);
    }
    else if (source.top() > dest.top()) {
        top1 = source.top(); source.pop();
        top2 = dest.top(); dest.pop();
        source.push(top1); source.push(top2);
        printIt(top2, d, s);
    }
    else {
        top2 = dest.top(); dest.pop();
        top1 = source.top(); source.pop();
        dest.push(top2); dest.push(top1);
        printIt(top1, s, d);
    }
}

void printIt(int disk, char fromPeg, char toPeg) {
    
    // cout << "Move disk " << disk
    //      << " from peg " << fromPeg
    //      << " to peg " << toPeg << endl;
}
