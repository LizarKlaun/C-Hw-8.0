#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL));
    int randNumber = rand() % 13;
    cout << "4.0, 4.5;" << endl;
    int** myArr = new int* [10];
    for (int i = 0; i < 10; i++) {
        myArr[i] = new int[13];
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 13; j++) {
            myArr[i][j] = randNumber;
            randNumber = rand() % 13;
            if (myArr[i][j] < 9) {
                for (int a = 0; a < 4; a++) {
                    myArr[i][j] = randNumber;
                    if (myArr[i][j] > 8) {
                        break;
                    }
                    randNumber = rand() % 13;
                }
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " Student" << "   ";
        for (int j = 0; j < 13; j++) {
            if (myArr[i][j] % 10 == 0 and myArr[i][j] != 0 or myArr[i][j] % 11 == 0 and myArr[i][j] != 0 or myArr[i][j] % 12 == 0 and myArr[i][j] != 0) {
                cout << myArr[i][j] << " ";
            }
            else {
                cout << myArr[i][j] << "  ";
            }
        }
        cout << endl;
    }

    cout << endl << "4.1; 4.2; 4.4;" << endl;
    int classHonors = 0;
    int honorsScore = 0;
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        honorsScore = 0;
        cout << i + 1 << " Student" << "   ";
        for (int j = 0; j < 13; j++) {
            sum += (myArr[i][j] + myArr[i][j]) / 13;
            if (myArr[i][j] > 9) {
                honorsScore += 1;
            }
        }
        cout << sum << "   ";
        if (honorsScore > 6) {
            cout << "Honors!!!: ";
        }
        for (int j = 0; j < 13; j++) {
            if (honorsScore > 6 and myArr[i][j] > 9) {
                cout << myArr[i][j] << " ";
            }
        }
        if (sum < 6) {
            cout << "NeAtestoan";
        }
        else if (sum > 8) {
            classHonors += 1;
        }
        cout << endl;
    }

    cout << endl << "4.3;" << endl;

    if (classHonors > 6) {
        cout << "Honors class" << endl;
    }

    else {
        cout << "Class of double thinkers" << endl;
    }

    cout << endl << "4.6;" << endl;

    for (int j = 0; j < 13; j++) {
        int scoreGreaterThan = 0;
        for (int i = 0; i < 10; i++) {
            if (myArr[i][j] < 9) {
                scoreGreaterThan++;
            }
        }
        if (scoreGreaterThan == 10) {
            cout << j << endl;
        }
    }
    for (int i = 0; i < 10; i++) {
        delete[] myArr[i];
        myArr[i] = nullptr;
    }

    delete[]myArr;

    myArr = nullptr;
}