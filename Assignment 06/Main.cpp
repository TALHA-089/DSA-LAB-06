#include "Functions.h"
#include <sstream>

int main() {
    cout << endl << endl;
    LinkedList<int> intList;

    bool exitProgram = false;

    while (!exitProgram) {
        int mainChoice;
        MainMenu(); 
        
        while (!getValidMenuChoice(mainChoice, 1, 4)){
            MainMenu(); 
        }

        switch (mainChoice) {
            case 1: { 
                bool exitStack = false;
                while (!exitStack) {
                    StackMenu();
                    int stackChoice;
        
                    while (!getValidMenuChoice(stackChoice, 1, 4)){
                        StackMenu();
                    }

                    switch (stackChoice) {
                        case 1: {  
                            int inputSize = getValidSize();

                            for (int i = 0; i < inputSize; i++) {
                                bool isValidInput = false;
                                int key;
                                do {
                                    cout << "\nEnter Number " << i + 1 << ": ";
                                    string KEY;
                                    getline(cin, KEY); 

                                    stringstream ss(KEY); 
                                    isValidInput = !(ss >> key).fail(); 

                                    if (isValidInput && ss.eof()) { 
                                        intList.Push(key); 
                                        cout << "\nInput Successful!\n";
                                    } else {
                                        cout << "\nInvalid Input\n";
                                    }
                                } while (!isValidInput);
                            }
                            break;
                        }
                        case 2: { 
                            if (!intList.isEmpty()) {
                                cout << "\n" << intList.Pop() << " Removed Successfully!\n";
                            } else {
                                cout << "\nStack is empty!\n";
                            }
                            break;
                        }
                        case 3: { 
                            cout << "\n---------- Stack (Linked List) ------------\n\n";
                            intList.DisplayStack();  
                            break;
                        }
                        case 4: { 
                            intList.Clear();  
                            exitStack = true;
                            break;
                        }
                    }
                }
                break;
            }

            case 2: {  // Queue Menu
                bool exitQueue = false;
                while (!exitQueue) {
                    QueueMenu();
                    int queueChoice;
                  
                    while (!getValidMenuChoice(queueChoice, 1, 4)){
                        QueueMenu();
                    }

                    switch (queueChoice) {
                        case 1: {  
                            int inputSize = getValidSize();
                            for (int i = 0; i < inputSize; i++) {
                                int key;
                                cout << "\nEnter Number " << i + 1 << ": ";
                                string KEY;
                                getline(cin, KEY); 

                                stringstream ss(KEY); 
                                if (ss >> key && ss.eof()) { 
                                    intList.Insert(key);  
                                    cout << "\nInput Successful!\n";
                                } else {
                                    cout << "\nInvalid Input\n";
                                }
                            }
                            break;
                        }
                        case 2: {  
                            if (!intList.isEmpty()) {
                                cout << "\n" << intList.Remove() << " Removed Successfully!\n";
                            } else {
                                cout << "\nQueue is empty!\n";
                            }
                            break;
                        }
                        case 3: { 
                            cout << "\n---------- Queue (Linked List) ------------\n\n";
                            intList.DisplayQueue();  
                            break;
                        }
                        case 4: { 
                            intList.Clear(); 
                            exitQueue = true;
                            break;
                        }
                    }
                }
                break;
            }

            case 3: {  // Priority Queue Menu
                bool exitPriorityQueue = false;
                while (!exitPriorityQueue) {
                    PriorityQueueMenu();
                    int priorityChoice;

                    while (!getValidMenuChoice(priorityChoice, 1, 4)){
                        PriorityQueueMenu();
                    }

                    switch (priorityChoice) {
                        case 1: { 
                            int inputSize = getValidSize();
                            for (int i = 0; i < inputSize; i++) {
                                int key;
                                cout << "\nEnter Number " << i + 1 << ": ";
                                string KEY;
                                getline(cin, KEY);

                                stringstream ss(KEY);
                                if (ss >> key && ss.eof()) { 
                                    intList.InsertPQ(key);  
                                    cout << "\nInput Successful!\n";
                                } else {
                                    cout << "\nInvalid Input\n";
                                }
                            }
                            break;
                        }
                        case 2: { 
                            if (!intList.isEmpty()) {
                                cout << "\n" << intList.RemovePQ() << " Removed Successfully!\n";
                            } else {
                                cout << "\nPriority Queue is empty!\n";
                            }
                            break;
                        }
                        case 3: { 
                            cout << "\n---------- Priority Queue (Linked List) ------------\n\n";
                            intList.DisplayPQ(); 
                            break;
                        }
                        case 4: { 
                            intList.Clear();  
                            exitPriorityQueue = true;
                            break;
                        }
                    }
                }
                break;
            }

            case 4: {  // Exit program
                cout << "\nGoodbye!\n";
                exitProgram = true;
                break;
            }
        }
    }

    return 0;
}
