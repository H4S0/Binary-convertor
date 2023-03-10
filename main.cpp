#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class BinaryConverter {
private:
    string binary;

public:
    BinaryConverter(string bin) {
        binary = bin;
    }

    int toDecimal() {
        int decimal = 0;
        for (int i = 0; i < binary.length(); i++) {
            decimal += (binary[i] - '0') * pow(2, binary.length() - 1 - i);
        }
        return decimal;
    }

    string toHexadecimal() {
        string hexadecimal = "";
        int decimal = toDecimal();
        while (decimal > 0) {
            int pom1 = decimal % 16;
            if (pom1 < 10) {
                hexadecimal = char(pom1 + '0') + hexadecimal;
            } else {
                hexadecimal = char(pom1 - 10 + 'A') + hexadecimal;
            }
            decimal /= 16;
        }
        return hexadecimal;
    }

    string toOctal() {
        string octal = "";
        int decimal = toDecimal();
        while (decimal > 0) {
            int pom1 = decimal % 8;
            octal = char(pom1 + '0') + octal;
            decimal /= 8;
        }
        return octal;
    }
};

class DecimalConverter {
private:
    int decimal;

public:
    DecimalConverter(int dec) {
        decimal = dec;
    }

    string toBinary() {
        string binary = "";
        int pom = decimal;
        while (pom > 0) {
            int pom1 = pom % 2;
            binary = char(pom1 + '0') + binary;
            pom /= 2;
        }
        return binary;
    }

    string toHexadecimal() {
        string hexadecimal = "";
        int pom = decimal;
        while (pom > 0) {
            int pom1 = pom % 16;
            if (pom1 < 10) {
                hexadecimal = char(pom1 + '0') + hexadecimal;
            } else {
                hexadecimal = char(pom1 - 10 + 'A') + hexadecimal;
            }
            pom /= 16;
        }
        return hexadecimal;
    }

    string toOctal() {
        string octal = "";
        int pom = decimal;
        while (pom > 0) {
            int pom1 = pom % 8;
            octal = char(pom1 + '0') + octal;
            pom /= 8;
        }
        return octal;
    }
};

class HexadecimalConverter {
private:
    string hexadecimal;

public:
    HexadecimalConverter(string hex) {
        hexadecimal = hex;
    }

    int toDecimal() {
        int decimal = 0;
        for (int i = 0; i < hexadecimal.length(); i++) {
            if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
                decimal += (hexadecimal[i] - '0') * pow(16, hexadecimal.length() - 1 - i);
            } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
                decimal += (hexadecimal[i] - 'A' + 10) * pow(16, hexadecimal.length() - 1 - i);
            }
        }
        return decimal;
    }

    string toBinary() {
        DecimalConverter decConverter(toDecimal());
        return decConverter.toBinary();
    }

    string toOctal() {
        DecimalConverter decConverter(toDecimal());
    return decConverter.toOctal();
}

};

class OctalConverter {
    private:
    string octal;
 
    public:
       OctalConverter(string oct) {
       octal = oct;
       }
    int toDecimal() {
    int decimal = 0;
    for (int i = 0; i < octal.length(); i++) {
        decimal += (octal[i] - '0') * pow(8, octal.length() - 1 - i);
    }
    return decimal;
}

    string toBinary() {
        DecimalConverter decConverter(toDecimal());
        return decConverter.toBinary();
    } 

    string toHexadecimal() {
        DecimalConverter decConverter(toDecimal());
        return decConverter.toHexadecimal();
    }
};

int main() {
int choice;
cout << "Dobrodosli u nas konvertor by Ismir i Hasan!" << endl;
do {
    cout << endl << "Odaberite opciju iz menija ispod:" << endl;
    cout << "1. Konverzija binarni u dekadni" << endl;
    cout << "2. Konverzija dekadnog u binarni" << endl;
    cout << "3. Konverzija binarnog u hexadekadni" << endl;
    cout << "4. Konverzija hexadekadnog u binarni" << endl;
    cout << "5. Konverzija binarnog u oktalni" << endl;
    cout << "6. Konverzija oktalnog u binarni" << endl;
    cout << "0. Izlaz iz programa" << endl;
    cout <<"                                  \n";
    cout << "Vasa opcija: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string binary;
            cout << "Unesite binarnu vrijednost: ";
            cin >> binary;
            BinaryConverter binConverter(binary);
            cout << "Dekadna vrijednost: " << binConverter.toDecimal() << endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 2: {
            int decimal;
            cout << "Unesite dekadnu vrijednost: ";
            cin >> decimal;
            DecimalConverter decConverter(decimal);
            cout << "Binarna vrijednost: " << decConverter.toBinary() << endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 3: {
            string binary;
            cout << "Unesite binarnu vrijednost: ";
            cin >> binary;
            BinaryConverter binConverter(binary);
            cout << "Hexadekadna vrijednost: " << binConverter.toHexadecimal() << endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 4: {
            string hexadecimal;
            cout << "Unesite hexadekadnu vrijednost: ";
            cin >> hexadecimal;
            HexadecimalConverter hexConverter(hexadecimal);
            cout << "Binarna vrijednost: " << hexConverter.toBinary() << endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 5: {
            string binary;
            cout << "Unesite binarnu vrijednost: ";
            cin >> binary;
            BinaryConverter binConverter(binary);
            cout << "Oktalna vrijednost: " << binConverter.toOctal() << endl;
            system("PAUSE");
            system("CLS");
            break;
        }
        case 6: {
            string octal;
            cout << "Unesite oktalnu vrijednost: ";
            cin >> octal;
            OctalConverter octConverter(octal);
            cout << "Binarna vrijednost: " << octConverter.toBinary() << endl;
            break;
        }
        case 0: {
            cout << "Izlazim iz programa!Hvala vam sto ste koristili nas program!" << endl;
            break;
        }
        default: {
            cout << "Odabrali ste pogresnu opciju.Molimo odraditi ponovno unos:" << endl;
            break;
        }
    }
} while (choice != 0);

return 0;
}


