#pragma Once 
#include "LinkedList.h"


void MainMenu();
int getValidSize();
int getValidChoice();


void MainMenu(){
    cout << "\n---------- Linked List ------------\n";
    cout << "\n1.Add";
    cout << "\n2.Remove";
    cout << "\n3.Display List";
    cout << "\n4.Exit";
    cout << "\n\nEnter your Choice: ";
}

int getValidSize(){
    int x;
    string X;
    bool isValidSize = false;
    do{
        string Filter;
        int digitcounter = 0;
        cout << "\nHow many Numbers do you want to enter: ";
        getline(cin,X);
        for(int i = 0; i < X.length(); i++){
            if(isdigit(X[i])){
                Filter += X[i];
                digitcounter += 1;
            }else{
                continue;
            }
        }

        if(digitcounter > 0){
            isValidSize = true;
            stringstream(Filter) >> x;
        }else{
            isValidSize = false;
            cout << "\nInvalid Input!\n";
            cout << "\nTry Again!\n";
        }

    }while(!isValidSize);

    return x;
}

int getValidChoice(){
    
    int x;
    string X;
    bool isValidChoice = false;

    do{
        MainMenu();
        getline(cin, X);

        string Filter;
        for(int i = 0; i < X.length(); i++){
            if(isdigit(X[i])){
                Filter += X[i];
            }else{
                continue;
            }
        }

        stringstream (Filter) >> x;

        if(x == 1 || x == 2 || x == 3 || x == 4 ){
            isValidChoice = true;
        }else{
            isValidChoice = false;
            cout << "\nInvalid Input!\n";
            cout << "\nTry Again!\n";
        }

    }while(!isValidChoice);

    return x;
}

