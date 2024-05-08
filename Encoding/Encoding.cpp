#include <iostream>
#include <vector>

using namespace std;

vector<int> decimalToBinary(int n) {
    vector<int> binaryNum;

    while (n > 0) {
        binaryNum.insert(binaryNum.begin(), n % 2);
        n = n / 2;
    }

    return binaryNum;
}

bool minThreeBin(const vector<int>& binaryNum) {
    int countOnes = 0;
    for (int i = 0; i < binaryNum.size(); ++i) {
        if (binaryNum[i] == 1) {
            countOnes++;
            if (countOnes >= 3) {
                return true;
            }
        }
    }
    return false;
}

bool exactlyThreeBin(const vector<int>& binaryNum) {
    int countOnes = 0;
    for (int i = 0; i < binaryNum.size(); ++i) {
        if (binaryNum[i] == 1) {
            countOnes++;

        }
    }
    return countOnes == 3;
}

bool minThreeBinChain(const vector<int>& binaryNum) {
    int countOnes = 0;
    for (int i = 0; i < binaryNum.size(); ++i) {
        if (binaryNum[i] == 1) {
            countOnes++;
            if (countOnes >= 3) return true;
        }
        else {
            countOnes = 0;
        }
    }
    return false;
}
bool exactlyThreeBinChain(const vector<int>& binaryNum) {
    int countOnes = 0;
    for (int i = 0; i < binaryNum.size(); ++i) {
        if (binaryNum[i] == 1) {
            countOnes++;
            if (countOnes == 3) {
                
                if (i + 1 < binaryNum.size() && binaryNum[i + 1] == 1) {
                    return false; 
                }
                return true;
            }
        }
        else {
            countOnes = 0;
        }
    }
    return false;
}


int main()
{
    int a, b;
    cout << "Enter the value of a: \n";
    cin >> a;
    cout << "Enter the value of b: \n";
    cin >> b;

    while (true) {
        int choice;
        cout << "Select test function:\n";
        cout << "1. Check if the binary representation contains at least three ones (A)\n";
        cout << "2. Check if the binary representation contains exactly three ones (B)\n";
        cout << "3. Check whether the binary representation contains a chain of at least three units (C)\n";
        cout << "4. Check whether the binary representation contains a chain of exactly three ones (D)\n";
        cin >> choice;

        vector<vector<int>> binaryArray;

        for (int i = a; i <= b; i++)
        {
            vector<int> binMaker = decimalToBinary(i);
            binaryArray.push_back(binMaker);
        }
        cout << "Binary representations of numbers ranging from " << a << " to " << b << ":\n";
        switch (choice) {
        case 1:
            for (int i = 0; i < binaryArray.size(); ++i) {
                if (minThreeBin(binaryArray[i])) {
                    for (int j = 0; j < binaryArray[i].size(); ++j) {
                        cout << binaryArray[i][j];
                    }
                    cout << endl;
                }
            }
            break;
        case 2:
            for (int i = 0; i < binaryArray.size(); ++i) {
                if (exactlyThreeBin(binaryArray[i])) {
                    for (int j = 0; j < binaryArray[i].size(); ++j) {
                        cout << binaryArray[i][j];
                    }
                    cout << endl;
                }
            }
            break;
        case 3:
            for (int i = 0; i < binaryArray.size(); ++i) {
                if (minThreeBinChain(binaryArray[i])) {
                    for (int j = 0; j < binaryArray[i].size(); ++j) {
                        cout << binaryArray[i][j];
                    }
                    cout << endl;
                }
            }
            break;
        case 4:
            for (int i = 0; i < binaryArray.size(); ++i) {
                if (exactlyThreeBinChain(binaryArray[i])) {
                    for (int j = 0; j < binaryArray[i].size(); ++j) {
                        cout << binaryArray[i][j];
                    }
                    cout << endl;
                }
            }
            break;
        default:
            if (choice == 5)
            {
                int result = a;
                /*vector<int> binMaker = decimalToBinary(a);
                for (int i = 0; i < binMaker.size(); ++i) {
                    result = result * 2 + binMaker[i];
                }*/
                cout << "Until " << result << endl;
                int c = ((result & 0b111) << 5) | (result & 0b11000) | (result >> 5);
                cout << "REWORK " << c << endl;

                int d = (a & 0b1111) | (b << 4);
                cout << "A: " << d << endl;

                           
                unsigned int g = ((b & 0b1100) << 4) | ((a & 0b1100) << 2) | ((b & 0b11) << 2) | (a & 0b11);



                std::cout << "B: " << g << std::endl; 

                unsigned int h = ((b & 0b1000) << 4) | ((a & 0b1000) << 3) |
                    ((b & 0b100) << 3) | ((a & 0b100) << 2) |
                    ((b & 0b10) << 2) | ((a & 0b10)<<1) |
                    ((b & 0b1) << 1) | (a & 0b1);

                std::cout << "D: " << h << std::endl; 
                break;
            }
            else
            {
                cout << "Incorrect choice.\n";
                return false;
            }

        }
    }





    return 0;
}