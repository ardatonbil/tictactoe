#include <iostream>
#include <vector>
using namespace std;

int str_to_int(string g) {
    if (g == "1") {
        return 0;
    }
    if (g == "2") {
        return 1;
    }
    if (g == "3") {
        return 2;
    }
    return -1;
}

bool inputcheck(string x) {
    int count = 0;
    if (x.length() != 3) {
        return false;
    }
    for (int i = 0; i < x.length(); i++) {
        if (x.at(i) != '1' && x.at(i) != '2' && x.at(i) != '3' && x.at(i) != '-') {
            return false;
        }
        else if (x.at(i) == '-') {
            count++;
        }
    }
    int y;
    y = x.find('-');
    if ((count != 1) || (y != 1)) {
        return false;
    }
    return true;
}


int main()
{
    string p1, p2;
    int point1 = 0, point2 = 0;
    cout << "Welcome to Tic-Tac-Toe!" << endl << "Player 1, please enter your name: ";
    cin >> p1;
    cout << "Hello, " << p1 << ". You are going to play with X" << endl << "Player 2, please enter your name: ";
    cin >> p2;
    cout << "Hello, " << p2 << ". You are going to play with O" << endl ;
    cout << endl;
    int k = 1;
    while (k < 2) {
        vector <vector<string>> mtx(3, vector<string>(3));
        for (int d = 0; d <= 2; d++) {
            for (int p = 0; p <= 2; p++) {
                (mtx.at(d)).at(p) = " ";
            }
        }
        int f = 0;
        cout << "Starting a new game..." << endl;
        while (f <= 9) {
            cout << "Current board: " << endl;
            cout << " " << mtx[0][0] << " " << "|" << " " << mtx[0][1] << " " << "|" << " " << mtx[0][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[1][0] << " " << "|" << " " << mtx[1][1] << " " << "|" << " " << mtx[1][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[2][0] << " " << "|" << " " << mtx[2][1] << " " << "|" << " " << mtx[2][2] << endl;
            int v = 0, n = 0;
            while (v < 1) {
                string inp1;
                cout << p1 << ", please enter your move: ";
                cin >> inp1;
                if (inputcheck(inp1) == false) {
                    cout << "Please enter correct move format!" << endl;
                    continue;
                }
                else {
                    string row = "", column = "";
                    row = inp1.at(0);
                    column = inp1.at(2);
                    int x = str_to_int(row), y = str_to_int(column);
                    if ((mtx[x][y] == "O") || (mtx[x][y] == "X")) {
                        cout << "That location is already full!" << endl;
                        continue;
                    }
                    else {
                        mtx[x][y] = "X";
                        f++;
                        v++;
                    }
                }
            }
            if (f >= 5) {
                if ((mtx[0][0] == "X" && mtx[0][1] == "X" && mtx[0][2] == "X") || (mtx[1][0] == "X" && mtx[1][1] == "X" && mtx[1][2] == "X") ||
                    (mtx[2][0] == "X" && mtx[2][1] == "X" && mtx[2][2] == "X") || (mtx[0][0] == "X" && mtx[1][0] == "X" && mtx[2][0] == "X") ||
                    (mtx[0][1] == "X" && mtx[1][1] == "X" && mtx[2][1] == "X") || (mtx[0][2] == "X" && mtx[1][2] == "X" && mtx[2][2] == "X") ||
                    (mtx[0][0] == "X" && mtx[1][1] == "X" && mtx[2][2] == "X") || (mtx[0][2] == "X" && mtx[1][1] == "X" && mtx[2][0] == "X")) {
                    point1++;
                    cout << p1 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
                else if ((mtx[0][0] == "O" && mtx[0][1] == "O" && mtx[0][2] == "O") || (mtx[1][0] == "O" && mtx[1][1] == "O" && mtx[1][2] == "O") ||
                         (mtx[2][0] == "O" && mtx[2][1] == "O" && mtx[2][2] == "O") || (mtx[0][0] == "O" && mtx[1][0] == "O" && mtx[2][0] == "O") ||
                         (mtx[0][1] == "O" && mtx[1][1] == "O" && mtx[2][1] == "O") || (mtx[0][2] == "O" && mtx[1][2] == "O" && mtx[2][2] == "O") ||
                         (mtx[0][0] == "O" && mtx[1][1] == "O" && mtx[2][2] == "O") || (mtx[0][2] == "O" && mtx[1][1] == "O" && mtx[2][0] == "O")) {
                    point2++;
                    cout << p2 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
                else if (f == 9) {
                    cout << "The game ended in a draw!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
            }
            cout << "Current board: " << endl;
            cout << " " << mtx[0][0] << " " << "|" << " " << mtx[0][1] << " " << "|" << " " << mtx[0][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[1][0] << " " << "|" << " " << mtx[1][1] << " " << "|" << " " << mtx[1][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[2][0] << " " << "|" << " " << mtx[2][1] << " " << "|" << " " << mtx[2][2] << endl;
            while (n < 1) {
                string inp2;
                cout << p2 << ", please enter your move: ";
                cin >> inp2;
                if (inputcheck(inp2) == false) {
                    cout << "Please enter correct move format!" << endl;
                    continue;
                }
                else {
                    string row = "", column = "";
                    row = inp2.at(0);
                    column = inp2.at(2);
                    int x = str_to_int(row), y = str_to_int(column);
                    if ((mtx[x][y] == "O") || (mtx[x][y] == "X")) {
                        cout << "That location is already full!" << endl;
                        continue;
                    }
                    else {
                        mtx[x][y] = "O";
                        f++;
                        n++;
                    }
                }
            }

            if (f >= 5) {
                if ((mtx[0][0] == "X" && mtx[0][1] == "X" && mtx[0][2] == "X") || (mtx[1][0] == "X" && mtx[1][1] == "X" && mtx[1][2] == "X") ||
                    (mtx[2][0] == "X" && mtx[2][1] == "X" && mtx[2][2] == "X") || (mtx[0][0] == "X" && mtx[1][0] == "X" && mtx[2][0] == "X") ||
                    (mtx[0][1] == "X" && mtx[1][1] == "X" && mtx[2][1] == "X") || (mtx[0][2] == "X" && mtx[1][2] == "X" && mtx[2][2] == "X") ||
                    (mtx[0][0] == "X" && mtx[1][1] == "X" && mtx[2][2] == "X") || (mtx[0][2] == "X" && mtx[1][1] == "X" && mtx[2][0] == "X")) {
                    point1++;
                    cout << p1 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;

                    break;
                }
                else if ((mtx[0][0] == "O" && mtx[0][1] == "O" && mtx[0][2] == "O") || (mtx[1][0] == "O" && mtx[1][1] == "O" && mtx[1][2] == "O") ||
                         (mtx[2][0] == "O" && mtx[2][1] == "O" && mtx[2][2] == "O") || (mtx[0][0] == "O" && mtx[1][0] == "O" && mtx[2][0] == "O") ||
                         (mtx[0][1] == "O" && mtx[1][1] == "O" && mtx[2][1] == "O") || (mtx[0][2] == "O" && mtx[1][2] == "O" && mtx[2][2] == "O") ||
                         (mtx[0][0] == "O" && mtx[1][1] == "O" && mtx[2][2] == "O") || (mtx[0][2] == "O" && mtx[1][1] == "O" && mtx[2][0] == "O")) {
                    point2++;
                    cout << p2 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
                else if (f == 9) {
                    cout << "The game ended in a draw!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
            }
        }
        k++;
    }
    int h = 1;
    while (h < 2) {
        vector <vector<string>> mtx(3, vector<string>(3));
        for (int d = 0; d <= 2; d++) {
            for (int p = 0; p <= 2; p++) {
                (mtx.at(d)).at(p) = " ";
            }
        }
        int f = 0;
        cout << "Starting a new game..." << endl;
        while (f <= 9) {
            cout << "Current board: " << endl;
            cout << " " << mtx[0][0] << " " << "|" << " " << mtx[0][1] << " " << "|" << " " << mtx[0][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[1][0] << " " << "|" << " " << mtx[1][1] << " " << "|" << " " << mtx[1][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[2][0] << " " << "|" << " " << mtx[2][1] << " " << "|" << " " << mtx[2][2] << endl;
            int v = 0, n = 0;
            while (v < 1) {
                string inp2;
                cout << p2 << ", please enter your move: ";
                cin >> inp2;
                if (inputcheck(inp2) == false) {
                    cout << "Please enter correct move format!" << endl;
                    continue;
                }
                else {
                    string row = "", column = "";
                    row = inp2.at(0);
                    column = inp2.at(2);
                    int x = str_to_int(row), y = str_to_int(column);
                    if ((mtx[x][y] == "O") || (mtx[x][y] == "X")) {
                        cout << "That location is already full!" << endl;
                        continue;
                    }
                    else {
                        mtx[x][y] = "O";
                        f++;
                        v++;
                    }
                }
            }
            if (f >= 5) {
                if ((mtx[0][0] == "X" && mtx[0][1] == "X" && mtx[0][2] == "X") || (mtx[1][0] == "X" && mtx[1][1] == "X" && mtx[1][2] == "X") ||
                    (mtx[2][0] == "X" && mtx[2][1] == "X" && mtx[2][2] == "X") || (mtx[0][0] == "X" && mtx[1][0] == "X" && mtx[2][0] == "X") ||
                    (mtx[0][1] == "X" && mtx[1][1] == "X" && mtx[2][1] == "X") || (mtx[0][2] == "X" && mtx[1][2] == "X" && mtx[2][2] == "X") ||
                    (mtx[0][0] == "X" && mtx[1][1] == "X" && mtx[2][2] == "X") || (mtx[0][2] == "X" && mtx[1][1] == "X" && mtx[2][0] == "X")) {
                    point1++;
                    cout << p1 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
                else if ((mtx[0][0] == "O" && mtx[0][1] == "O" && mtx[0][2] == "O") || (mtx[1][0] == "O" && mtx[1][1] == "O" && mtx[1][2] == "O") ||
                         (mtx[2][0] == "O" && mtx[2][1] == "O" && mtx[2][2] == "O") || (mtx[0][0] == "O" && mtx[1][0] == "O" && mtx[2][0] == "O") ||
                         (mtx[0][1] == "O" && mtx[1][1] == "O" && mtx[2][1] == "O") || (mtx[0][2] == "O" && mtx[1][2] == "O" && mtx[2][2] == "O") ||
                         (mtx[0][0] == "O" && mtx[1][1] == "O" && mtx[2][2] == "O") || (mtx[0][2] == "O" && mtx[1][1] == "O" && mtx[2][0] == "O")) {
                    point2++;
                    cout << p2 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
                else if (f == 9) {
                    cout << "The game ended in a draw!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
            }
            cout << "Current board: " << endl;
            cout << " " << mtx[0][0] << " " << "|" << " " << mtx[0][1] << " " << "|" << " " << mtx[0][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[1][0] << " " << "|" << " " << mtx[1][1] << " " << "|" << " " << mtx[1][2] << endl;
            cout << "-----------" << endl;
            cout << " " << mtx[2][0] << " " << "|" << " " << mtx[2][1] << " " << "|" << " " << mtx[2][2] << endl;
            while (n < 1) {
                string inp1;
                cout << p1 << ", please enter your move: ";
                cin >> inp1;
                if (inputcheck(inp1) == false) {
                    cout << "Please enter correct move format!" << endl;
                    continue;
                }
                else {
                    string row = "", column = "";
                    row = inp1.at(0);
                    column = inp1.at(2);
                    int x = str_to_int(row), y = str_to_int(column);
                    if ((mtx[x][y] == "O") || (mtx[x][y] == "X")) {
                        cout << "That location is already full!" << endl;
                        continue;
                    }
                    else {
                        mtx[x][y] = "X";
                        f++;
                        n++;
                    }
                }
            }

            if (f >= 5) {
                if ((mtx[0][0] == "X" && mtx[0][1] == "X" && mtx[0][2] == "X") || (mtx[1][0] == "X" && mtx[1][1] == "X" && mtx[1][2] == "X") ||
                    (mtx[2][0] == "X" && mtx[2][1] == "X" && mtx[2][2] == "X") || (mtx[0][0] == "X" && mtx[1][0] == "X" && mtx[2][0] == "X") ||
                    (mtx[0][1] == "X" && mtx[1][1] == "X" && mtx[2][1] == "X") || (mtx[0][2] == "X" && mtx[1][2] == "X" && mtx[2][2] == "X") ||
                    (mtx[0][0] == "X" && mtx[1][1] == "X" && mtx[2][2] == "X") || (mtx[0][2] == "X" && mtx[1][1] == "X" && mtx[2][0] == "X")) {
                    point1++;
                    cout << p1 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;

                    break;
                }
                else if ((mtx[0][0] == "O" && mtx[0][1] == "O" && mtx[0][2] == "O") || (mtx[1][0] == "O" && mtx[1][1] == "O" && mtx[1][2] == "O") ||
                         (mtx[2][0] == "O" && mtx[2][1] == "O" && mtx[2][2] == "O") || (mtx[0][0] == "O" && mtx[1][0] == "O" && mtx[2][0] == "O") ||
                         (mtx[0][1] == "O" && mtx[1][1] == "O" && mtx[2][1] == "O") || (mtx[0][2] == "O" && mtx[1][2] == "O" && mtx[2][2] == "O") ||
                         (mtx[0][0] == "O" && mtx[1][1] == "O" && mtx[2][2] == "O") || (mtx[0][2] == "O" && mtx[1][1] == "O" && mtx[2][0] == "O")) {
                    point2++;
                    cout << p2 << " is the winner!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
                else if (f == 9) {
                    cout << "The game ended in a draw!" << endl << "Current Scores: " << endl << p1 << ": " << point1 << "   " <<
                         p2 << ": " << point2 << endl << endl;
                    break;
                }
            }
        }
        h++;
    }
    cout << "Final Scores: " << endl << p1 << ": " << point1 << "   " << p2 << ": " << point2 << endl;
    if (point1 < point2) {
        cout << p2 << " is the overall winner!" << endl;
    }
    else if (point1 > point2) {
        cout << p1 << " is the overall winner!" << endl;
    }
    else if (point1 == point2) {
        cout << "The overall game ended in a draw!" << endl;
    }
}
