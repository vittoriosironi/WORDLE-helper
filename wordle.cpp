#include "wordle_Lib.h"

void home() {
    cout << " -------------------------" << endl;
    cout << "|         WORDLE          |" << endl;
    cout << " -------------------------" << endl;
}

void menu() {
    cout << " - [S]tart" << endl;
    // cout << " - [H]elp" << endl;
    cout << " - [Q]uit" << endl;
}

int main() {
    system("clear");

    Finder FD("Wordle_List.txt");
    int count = 0;
    string enteredWord;
    char scelta = 'S';

    home();
    menu();

    while(scelta != 'q' && scelta != 'Q') {
        cout << endl;
        cout << " > "; cin >> scelta;

        if (scelta == 'H' || scelta == 'h') {}
        else if (scelta == 'S' || scelta == 's') {

            cout << "First word > ";
            cin.ignore(); getline(cin, enteredWord);
            while (enteredWord.size() != 5) {
                cout << "The word must have five letters" << endl;
                cout << "First word > "; getline(cin, enteredWord);
            }

            cout << "Enter this word in Wordle and insert the colors of the letter in the terminal" << endl;
            cout << endl;
            cout << "COLORS:" << endl;
            cout << "Green  -> 1" << endl;
            cout << "Yellow -> 0" << endl;
            cout << "Gray   -> -1" << endl;
            cout << "RESET word colors -> 256" << endl;
            cout << endl;

            do
            {
                vector<int> typeWord;
                int input;

                if (count != 0) {
                    cout << "\nWord > ";
                    cin.ignore(); getline(cin, enteredWord);
                    while (enteredWord.size() != 5) {
                        cout << "The word must have five letters" << endl;
                        cout << "Word > "; getline(cin, enteredWord);
                    }
                }

                for (int i = 0; i < 5; i++) {
                    cout << i + 1 << "° letter color > "; cin >> input;
                    if (input == 256) {
                        typeWord.clear();
                        i = -1;

                        cout << endl;
                    } else
                        typeWord.push_back(input);
                }
                FD.equalWords(enteredWord, typeWord);
                
                cout << endl;
                cout << "POSSIBLE WORDS" << endl;
                FD.evo();
                FD.printList();

                count++;
            } while (count < 6);
        }
    }

    return 0;
}
