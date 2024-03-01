#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <vector>
#include <random>

using namespace std;


string reverse(const string& word) {
    string reversedWord = word;
    reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}


string removeVowels(const string& word) {
    string result;
    const string vowels = "aeiouAEIOU";
    for (char ch : word) {
        if (vowels.find(ch) == string::npos) {
            result += ch;
        }
    }
    return result;
}

string removeConsonants(const string& word) {
    string result;
    const string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    for (char ch : word) {
        if (consonants.find(ch) == string::npos) {
            result += ch;
        }
    }
    return result;
}


string shuffleWord(const string& word) {
    string shuffledWord = word;
    random_device rd;
    mt19937 g(rd());
    
    shuffle(shuffledWord.begin(), shuffledWord.end(), g);
    
    return shuffledWord;
}

int main() {
    cout << "Введите слово: ";
    string word;
    cin >> word;

    cout << "Выберите действие:\n"
         << "1. Слово выводится задом наперед\n"
         << "2. Вывести слово без гласных\n"
         << "3. Вывести слово без согласных\n"
         << "4. Рандомно раскидывать буквы заданного слова\n"
         << "Ваш выбор: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Перевернутое слово: " << reverse(word) << endl;
            break;
        case 2:
            cout << "Слово без гласных: " << removeVowels(word) << endl;
            break;
        case 3:
            cout << "Слово без согласных: " << removeConsonants(word) << endl;
            break;
        case 4:
            cout << "Перемешанное слово: " << shuffleWord(word) << endl;
            break;
        default:
            cout << "Неверный выбор." << endl;
    }

    return 0;
}
