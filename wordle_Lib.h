#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Dataset
{
public:
    vector<string> words;
    int N;

    Dataset(const char* dataSetFile)
    {
        string input;
        N = 0;
        ifstream fin (dataSetFile);
        while(!fin.eof())
        {
            getline(fin, input); words.push_back(input);
            N++;
        }
        N--;
        fin.close();
    }

    int size()            {return N; }
    string word_i(int i)  {return words[i]; }

    void print ()
    {
        for(int i = 0; i < N; i++)
            cout << words[i] << endl;
    }
};

class biLetters {
public:
    char letter;
    int type; // type = 1 -> green, type = 0 -> yellow, type = -1 -> Gray

    biLetters(char letter_, int type_) { letter = letter_; type = type_; }
    void changeToGreen()    { type = 1;  }
    void changeToYellow()   { type = 0;  }
    void changeToGray()     { type = -1; }
};

class Finder {
public:
    vector<string> wordsList; // List of the possible words
    vector<biLetters> words;

    Finder(const char* dataSetFile) {
        Dataset DS(dataSetFile);
        wordsList = DS.words;
        for (int i = 0; i < 5; i++)
            words.push_back(biLetters('a', -1));
    }

    void printList() {
        for (int i = 0; i < wordsList.size(); i++)
            cout << wordsList[i] << endl;
    }
    void equalWords(string enteredWord, vector<int> types) {
        for (int i = 0; i < enteredWord.size(); i++) {
            words[i].letter = enteredWord[i];
            words[i].type = types[i];
        }
    }

    bool isContainGray(biLetters letter, string word) {
        if (letter.type == -1) {
            for (int i = 0; i < word.size(); i++) {
                if (letter.letter == word[i])
                    return true;
            }
            return false;
        }

        return false;
    }
    bool isContainYellow(biLetters letter, string word) {
        if (letter.type == 0) {
            for (int i = 0; i < word.size(); i++) {
                if (letter.letter == word[i])
                    return true;
            }
            return false;
        }

        return true;
    }
    bool isContainGreen(biLetters letter, int pos, string word) {
        if (letter.type == 1) {
            for (int i = 0; i < word.size(); i++) {
                if (letter.letter == word[i] && i == pos)
                    return true;
            }
            return false;
        }

        return true;
    }

    void evo() {
        vector<string> wordsListNew;
        bool controllo = true;

        for (int i = 0; i < wordsList.size(); i++) {
            for (int k = 0; k < words.size(); k++) {
                if (isContainGray(words[k], wordsList[i]) ||
                    !isContainYellow(words[k], wordsList[i]) ||
                    !isContainGreen(words[k], k, wordsList[i])) {
                        controllo = false;
                        break;
                }
            }
            if (controllo)
                wordsListNew.push_back(wordsList[i]);
            controllo = true;
        }
        wordsList = wordsListNew;

        printList();
        
    }


};