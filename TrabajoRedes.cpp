#include<iostream>
#include<fstream>
#include<string>
#include<ctime>

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
        clock_t time_req = clock();
        
        string aux = data.substr(0, checkpoint);
        md5(aux);
        
        time_req = clock() - time_req;

        double time = ((double)(time_req)/CLOCKS_PER_SEC);

        cout << "Execution Time Seconds: " << time << endl;
        
        getPercentage(checkpoint, data_lenght);
        
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
        
        string aux = data.substr(0, checkpoint);
        sha256(aux);
        
        time_req = clock() - time_req;

        double time = ((double)(time_req)/CLOCKS_PER_SEC);
        
        cout << "Execution SHA256 Time Seconds: " << time << endl;
        
        getPercentage(checkpoint, data_lenght);
        
        times[i] = time;
        checkpoint += 10000;
        i++;

    }

    CrearTXT(times, "SHA_timess.txt");
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