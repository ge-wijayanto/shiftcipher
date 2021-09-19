/*
Nama        : Gregorius Evangelist Wijayanto
NPM         : 140810190040
Kelas       : B
Deskripsi   : Program Shift Cipher
*/

#include <iostream>
#include <string.h>
using namespace std;

main() {
    string loopmenu;
    int key; 

    do {
        cout << "\n---------------------------------------------------------- \n";
        cout << "Input Text     : ";
        string text = "";
        getline(cin >> ws, text);

        cout << "---------------------------------------------------------- \n";
        cout << "Input Key      : ";
        cin >> key;
        cout << "========================================================== \n";
        
        // Algoritma Enkripsi
        char ch;
        for(int i = 0; text[i] != '\0'; ++i) {
            ch = text[i];
            // Enkripsi Lowercase Letter
            if (ch >= 'a' && ch <= 'z') {
                ch = ch + key;
                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }  
                text[i] = ch;
            }
            // Enkripsi Uppercase Letter
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                text[i] = ch;
            }
        }
        cout << "Ciphertext     : " << text << "\n";
        cout << "---------------------------------------------------------- \n";
        
        // Algoritma Dekripsi
        for(int i = 0; text[i] != '\0'; ++i) {
            ch = text[i];
            // Dekripsi Lowercase Letter
            if(ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if(ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
            text[i] = ch;
            }
            // Dekripsi Uppercase Letter
            else if(ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if(ch < 'A') {
                    ch = ch + 'Z' - 'A' + 1;
                }
                text[i] = ch;
            }
        }
        cout << "Plaintext      : " << text << "\n";
        cout << "---------------------------------------------------------- \n";

        cout << "\nBack to menu? (Y/N) : ";
        cin >> loopmenu;
    } while(loopmenu == "Y" || loopmenu == "y");

    return 0;
}