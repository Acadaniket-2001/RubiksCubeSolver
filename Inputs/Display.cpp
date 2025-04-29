//
// Created by "ANIKET GUPTA" on 29-04-2025.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <bits/stdc++.h>
using namespace std;

class Display {
public:
    void displayMoves() {
        cout << "Available moves:\n";
        cout << "+------------------+-----------+\n";
        cout << "|MOVES             |  KEY_PRESS|\n";
        cout << "|------------------|-----------|\n";
        cout << "|LEFT              |     1     |\n";
        cout << "|LPRIME            |     2     |\n";
        cout << "|L-TWICE           |     3     |\n";
        cout << "|------------------|-----------|\n";
        cout << "|RIGHT             |     4     |\n";
        cout << "|RPRIME            |     5     |\n";
        cout << "|R-TWICE           |     6     |\n";
        cout << "|------------------|-----------|\n";
        cout << "|UP                |     7     |\n";
        cout << "|UPRIME            |     8     |\n";
        cout << "|U-TWICE           |     9     |\n";
        cout << "|------------------|-----------|\n";
        cout << "|DOWN              |     10    |\n";
        cout << "|DPRIME            |     11    |\n";
        cout << "|D-TWICE           |     12    |\n";
        cout << "|------------------|-----------|\n";
        cout << "|FRONT             |     13    |\n";
        cout << "|FPRIME            |     14    |\n";
        cout << "|F-TWICE           |     15    |\n";
        cout << "|------------------|-----------|\n";
        cout << "|BACK              |     16    |\n";
        cout << "|BPRIME            |     17    |\n";
        cout << "|B-TWICE           |     18    |\n";
        cout << "+------------------+-----------+\n";
    }

    vector<int> inputMoves(int n) {
        cout << "Enter " << n << " move numbers:\n";

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            while (true) {
                int x; cin >> x;
                if (x >= 1 and x <= 18) {
                    arr[i] = x - 1;
                    break;
                }
                cout << x << " is not a valid input.\nEnter a valid one again: \n";
            }
        }
        return arr;
    }
};

#endif