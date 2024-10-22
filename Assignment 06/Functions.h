#pragma once
#include "LinkedList.h"

void MainMenu();
void StackMenu();
void QueueMenu();
void PriorityQueueMenu();
int getValidSize();
int getValidChoice();

bool getValidMenuChoice(int &choice, int min, int max) {
    string input;
    getline(cin, input);
    stringstream ss(input);
    
    if (ss >> choice && ss.eof() && choice >= min && choice <= max) {
        return true; 
    } else {
        cout << "\nInvalid choice! Please enter a number between " << min << " and " << max << ".\n";
        return false;
    }
}

void StackMenu() {
    cout << "\n---------- Linked List (Stack) ------------\n";
    cout << "\n1.Push";
    cout << "\n2.Pop";
    cout << "\n3.Display Stack";
    cout << "\n4.MainMenu";
    cout << "\n\nEnter your Choice: ";
}

void MainMenu() {
    cout << "\n---------- Linked List ------------\n";
    cout << "\n1.Stack Menu";
    cout << "\n2.Queue Menu";
    cout << "\n3.Priority Queue";
    cout << "\n4.Exit";
    cout << "\n\nEnter your Choice: ";
}

void QueueMenu() {
    cout << "\n---------- Linked List (Queue) ------------\n";
    cout << "\n1.Insert";
    cout << "\n2.Remove";
    cout << "\n3.Display Queue";
    cout << "\n4.MainMenu";
    cout << "\n\nEnter your Choice: ";
}

void PriorityQueueMenu() {
    cout << "\n---------- Linked List (Priority Queue) ------------\n";
    cout << "\n1.Insert";
    cout << "\n2.Remove";
    cout << "\n3.Display Queue";
    cout << "\n4.MainMenu";
    cout << "\n\nEnter your Choice: ";
}

int getValidSize() {
    int x;
    string X;
    bool isValidSize = false;
    do {
        string Filter;
        int digitcounter = 0;
        cout << "\nHow many Numbers do you want to enter: ";
        getline(cin, X);


        for (int i = 0; i < X.length(); i++) {
            char c = X[i];
            if (isdigit(c)) {
                Filter += c;
                digitcounter++;
            }
        }

        if (digitcounter > 0) {
            isValidSize = true;
            stringstream(Filter) >> x;
        } else {
            isValidSize = false;
            cout << "\nInvalid Input!\n";
            cout << "\nTry Again!\n";
        }
    } while (!isValidSize);

    return x;
}

int getValidChoice() {
    int x;
    string X;
    bool isValidChoice = false;

    do {
        MainMenu();
        getline(cin, X);

        string Filter;

        for (int i = 0; i < X.length(); i++) {
            char c = X[i];
            if (isdigit(c)) {
                Filter += c;
            }
        }

        stringstream(Filter) >> x;

        if (x >= 1 && x <= 4) {
            isValidChoice = true;
        } else {
            isValidChoice = false;
            cout << "\nInvalid Input!\n";
            cout << "\nTry Again!\n";
        }
    } while (!isValidChoice);

    return x;
}


