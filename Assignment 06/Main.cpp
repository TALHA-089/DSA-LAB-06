#include "Functions.h"
#include <sstream>


int main() {

    cout << endl << endl;
    LinkedList<int> intList;

    while(true){
        int choice;
        choice = getValidChoice();

        if(choice == 4){
            cout << "\nGoodBye!\n";
            cout << endl << endl;
            break;
        }else if(choice == 1){
            int inputSize;
            inputSize = getValidSize();

            for(int i = 0; i < inputSize; i++){

                bool isValidInput = false;
                int key;
                do{
                    cout << "\nEnter Number " << i + 1 << ": ";
                    int digitCounter = 0;
                    string KEY;
                    string Filter;
                    isValidInput = false;
                    getline(cin, KEY);
                
                    for(int i = 0; i < KEY.length(); i++){
                        if(isdigit(KEY[i])){
                            Filter += KEY[i];
                            digitCounter++;
                        }else{
                            continue;
                        }
                    }

                    if(digitCounter > 0){
                        isValidInput = true;
                        stringstream(KEY) >> key;
                    }else{
                        isValidInput = false;
                        cout << "\nInvalid Input\n";
                    }
                }while(!isValidInput);

                intList.add(key);
                cout << "\nInput Successful!\n";
            }

        }else if(choice == 2){
            int key;
            string KEY;

            cout << "\nEnter the Number you want to remove: ";
            getline(cin, KEY);
            stringstream (KEY) >> key;

            intList.deleteNode(key);
            cout << "\n" << key << " Removed Successfully!\n";

        }else if(choice == 3){
            cout << "\n---------- Linked List ------------\n\n";
            intList.printList();
        }else{
            cout << "\nInvalid Input\n";
            cout << "\nTry Again\n";
        }

    }

    return 0;
}
