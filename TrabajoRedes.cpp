#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cmath>

#include "md5.h"
#include "sha256.h"

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

void Prueba1(int checkpoint){

    string Inp =  LeerArchivo();
    string M_out = md5(Inp);

    /*for(int i = 0; i<checkpoint; i++){
        float y = log(pow(i,5));
    }*/
}

void getPercentage(int check, int total){
    int quotient = check / total;
    int percent = quotient * 100;

    switch (percent){
        case 10:
            cout << percent << "%" << endl;
        case 20:
            cout << percent << "%" << endl;
        case 30:
            cout << percent << "%" << endl;
        case 40:
            cout << percent << "%" << endl;
        case 50:
            cout << percent << "%" << endl;
        case 60:
            cout << percent << "%" << endl;
        case 70:
            cout << percent << "%" << endl;
        case 80:
            cout << percent << "%" << endl;
        case 90:
            cout << percent << "%" << endl;
        case 100:
            cout << percent << "%" << endl;
        default:
            cout << "No se completo el proceso." << endl;
    } 
}

void MD5_times(string data){
    double times[100] = {};
    int checkpoint = 10000;
    int data_lenght = 1000000;

    int i = 0;
    while (checkpoint != (data_lenght + 10000)){
        clock_t time_req = clock();
        
        // MD5(data[0:checkpoint]);
        Prueba1(checkpoint);
        
        time_req = clock() - time_req;

        double time = ((double)(time_req)/CLOCKS_PER_SEC);
        
        //cout << "Execution Time Miliseconds: " << time_req << endl;
        cout << "Execution Time Seconds: " << time << endl;
        
        times[i] = time;
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
        clock_t time_req = clock();
        
        // SHA(data[0:checkpoint]);
        Prueba1(checkpoint);
        
        time_req = clock() - time_req;

        double time = ((double)(time_req)/CLOCKS_PER_SEC);
        
        //cout << "Execution Time Miliseconds: " << time_req << endl;
        //cout << "Execution Time Seconds: " << time << endl;
        
        times[i] = time;
        checkpoint += 10000;
        i++;

    }
    //CrearTXT(times, "SHA_timess.txt");
}


int main(){
    //string data = LeerArchivo();
    string data = "asd";
    cout << data;

    //double* pMD5_times = new double[100];
    //double* pSHA_times = new double[100];

    //pMD5_times = MD5_times(data);
    MD5_times(data);

    //CrearTXT(pMD5_times, pSHA_times);

    cout << "Done!";

    //cout << *pSHA_times << endl;
    
    return 0;
}