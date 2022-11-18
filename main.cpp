#include <iostream>
#include "md5.h"
#include "sha256.h"

using namespace std;

int main(int argc, char *argv[]){
    
    cout << "Ingrese el texto a cifrar" << endl;
    string Inp;
    cin >> Inp;
    string S_out = sha256(Inp);
    string M_out = md5(Inp);

    cout << "Cifrado en SHA256 " << S_out << endl; //Da una clave de 256 bits
    cout << "Cifrado en MD5 " << M_out << endl; //Da una clave de 128 bits
}