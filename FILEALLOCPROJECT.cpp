#include <cmath>
#include <string>
#include <iostream>
#include <time.h>
using namespace std;
const int yourMemory = 50;
class contFileAlloc {

public:
    string name;
    int start = rand() % yourMemory + 1;
    int size;
    int end;

    void part() {
        end = start + size - 1;
    }
};

class indexedFileAlloc {
public:
    string name;
    int start = rand() % yourMemory + 1;
    int data[4];

    void typeData() {
        for (int i = 0; i < 4; i++) {
            data[i] = rand() % yourMemory + 1;

        }
    }
};

class linkedFileAlloc {
public:
    string name;
    int start = rand() % yourMemory;
    int data[4];
    
    void typeData() {
        for (int i = 0; i < 4; i++) {
            data[i] = rand() % yourMemory;

        }
    }
};

    void fillMemory(string memory[]) {
        for (int i = 0; i < 50; i++) {
            memory[i] = "Not Filled";
        }
    }

    int main()
    {
        srand(time(NULL));
        int input;
        string memory[yourMemory];
        fillMemory(memory);
        do
        {

            cout << "->File-Allocation algorithms menu<-\n";
            cout << "------------------------------------" << endl;
            cout << "1- for Contigiuos File Allocation\n";
            cout << "2- Indexed file allocation method\n";
            cout << "3- Linked file allocation method\n";
            cout << "Enter 4 for Exit\n";
            cin >> input;


            if (input == 1) {
                contFileAlloc cFile;
                cout << "Enter file Name : ";
                cin >> cFile.name;
                cout << endl;
                cFile.start;
                cout << "Enter file size : ";
                cin >> cFile.size;
                cout << endl;
                cFile.part();
                cout << endl;
                for (int i = cFile.start; i <= cFile.end; i++) {
                    if (memory[i] == "Not Filled") {
                        memory[i] = "Filled with file " + cFile.name;
                    }
                }
                for (int j = 0; j < yourMemory; j++) {
                    cout << j << ": ";
                    cout << memory[j] << endl;
                }

                cout << "Your File name is: " << "\t" << "Your File size is: " << "\t"
                    << "Your Starting Block is: " << "\t" << "Your Ending Block is: "
                    << "\n" << "\t" << cFile.name << "\t\t\t" << cFile.size <<
                    "\t\t\t" << cFile.start << "\t\t\t\t" << cFile.end << endl;
            }

            else if (input == 2) {
                indexedFileAlloc iFile;
                cout << "Enter file Name : ";
                cin >> iFile.name;
                cout << endl;
                iFile.typeData();
                

                for (int i = iFile.start; i < yourMemory; i++) {
                    if (iFile.data[0] == i ||
                        iFile.data[1] == i ||
                        iFile.data[2] == i ||
                        iFile.data[3] == i) {
                        memory[i] = "Filled with file " + iFile.name;
                    }
                    else
                        continue;
                }
                for (int j = 0; j < yourMemory; j++) {
                    cout << j << ": ";
                    cout << memory[j] << endl;
                }
                cout << "Your File name is: " << "\t"
                    << "Your Start is: " << "\t\t" <<endl<< iFile.name << "\t\t" <<
                    "\t\t" << iFile.start << endl;
            }

            else if (input == 3) {

                linkedFileAlloc lFile;
                cout << "Enter file Name : ";
                cin >> lFile.name;
                cout << endl;
                lFile.start;
                
                lFile.typeData();
               
                for (int i = lFile.start; i <= yourMemory; i++) {
                    if (lFile.data[0] == i
                        || lFile.data[1] == i
                        || lFile.data[2] == i
                        || lFile.data[3] == i) {
                        memory[i] = "Filled with file " + lFile.name;
                    }
                    else
                        continue;
                }
                for (int j = 0; j < yourMemory; j++) {
                    cout << j << ": ";
                    cout << memory[j] << endl;
                }
                cout << "Your File name is: " << "\t"
                    << "Your Start is: " << "\t\t" << endl << "\t"<<lFile.name << "\t\t" <<
                    "\t" << lFile.start << "\t\t" << endl;
            }

            else if (input == 4) {
                break;
            }
        } while (input != 4);
    }