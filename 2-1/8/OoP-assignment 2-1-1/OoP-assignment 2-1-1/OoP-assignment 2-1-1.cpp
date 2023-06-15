#include <iostream>

using namespace std;

int main(void) {
	int stack[128]; // stack의 크기 128로 정의
	string command; 
	int num, top=0; 
    while (1) { // start an infinite loop
        cin >> command; // read user input command

        if (command == "push") { // if the command is "push"
            cin >> num; // read an integer value
            stack[top + 1] = num; // add the value to the top of the stack
            top++; // increment the top index
        }
        else if (command == "pop") { // if the command is "pop"
            cout << stack[top] << endl; // print the top value from the stack
            stack[top] = NULL; // set the top value to null
            top--; // decrement the top index
        }
        else if (command == "top") { // if the command is "top"
            cout << stack[top]; // print the top value without removing it
        }
        else if (command == "print") { // if the command is "print"
            for (int i = 1; i <= top; i++) { // loop through the stack from the bottom to the top
                cout << stack[i] << " "; // print each value separated by a space
            }
            cout << endl; // print a newline character at the end
        }
        else if (command == "empty") { // if the command is "empty"
            if (top == 0) { // if the stack is empty
                cout << "1" << endl; // print 1 to indicate that the stack is empty
            }
            else { // otherwise
                cout << "0" << endl; // print 0 to indicate that the stack is not empty
            }
        }
        else if (command == "exit") { // if the command is "exit"
            break; // exit the loop and terminate the program
        }
        else { // if the command is not recognized
            cout << "unknown command" << endl; // print an error message
        }
    }
	return 0;
}