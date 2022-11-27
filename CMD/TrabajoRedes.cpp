#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

#include "md5.h"
#include "sha256.h"
#include "project.cpp"

using namespace std;

string LeerArchivo(){
    string myString;
    string completo;
    ifstream MyReadFile("dataset.txt");
    int cont = 0;
    
    while(getline (MyReadFile, myString)){
        if(!cont==0){
            completo = completo + " " + myString;
        }else{ //CASO INICIAL 
            completo = completo + myString;
            cont++;
        }
    }
    return completo;
}

void CrearTXT(double* pM, string nameFile){
    ofstream MyFileM(nameFile);
    for(int i = 0; i < 100 ; i++){
        MyFileM << *(pM+i) << "\n";
    }
    MyFileM.close();

}

void getPercentage(int check, int total){
    int quotient = check / total;
    int percent = quotient * 100;

    if(percent == 100){
        cout << "Complete " << percent << "%" << endl;
    }
}

void MD5_times(string data){
    double times[100] = {};
    int checkpoint = 10000;
    int data_lenght = 1000000;

    int i = 0;
    while (checkpoint != (data_lenght + 10000)){
        auto start = chrono::steady_clock::now();
        
        string aux = data.substr(0, checkpoint);
        md5(aux);
        
        auto end = chrono::steady_clock::now();

        chrono::duration<float, std::milli> duration = end - start;

        cout << "Execution Time milliseconds: " << duration.count() << endl;
        
        getPercentage(checkpoint, data_lenght);
        
        times[i] = duration.count();
        checkpoint += 10000;
        i++;
    }

    CrearTXT(times, "MD5_times.txt");
}

void SHA_times(string data){
    double times[100] = {0};
    int checkpoint = 10000;
    int data_lenght = 1000000;

    int i = 0;

    while (checkpoint != (data_lenght + 10000)){
        auto start = chrono::steady_clock::now();
        
        string aux = data.substr(0, checkpoint);
        md5(aux);
        
        auto end = chrono::steady_clock::now();

        chrono::duration<float, std::milli> duration = end - start;

        cout << "Execution Time milliseconds: " << duration.count() << endl;
        
        getPercentage(checkpoint, data_lenght);
        
        times[i] = duration.count();
        checkpoint += 10000;
        i++;
    }

    CrearTXT(times, "SHA_times.txt");
}

int main(){
    string data = LeerArchivo();

    cout << data << endl;

    MD5_times(data);
    SHA_times(data);

    cout << "" << endl;
    cout << "Done!" << endl;
    
    return 0;
}