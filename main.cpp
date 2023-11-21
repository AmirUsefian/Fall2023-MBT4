#include <iostream>
using namespace std;

class StateMachine {
private:
    int currentState;

public:
    StateMachine() : currentState(1) {}

    void moveForward() {
        if (currentState < 8) {
            currentState++;
            cout << "Moved forward. Current state: " << currentState << endl;
        } else {
            cout << "Cannot move forward. Already at the final state." << endl;
        }
    }

    void moveBackward() {
        if (currentState > 1) {
            currentState--;
            cout << "Moved backward. Current state: " << currentState << endl;
        } else {
            cout << "Cannot move backward. Already at the initial state." << endl;
        }
    }

    void moveRight() {
        if (currentState % 2 == 0) {
            currentState += 2;
            if (currentState > 8) {
                currentState = 8;
            }
            cout << "Moved right. Current state: " << currentState << endl;
        } else {
            cout << "Cannot move right from the current state." << endl;
        }
    }

    void moveLeft() {
        if (currentState % 2 != 0) {
            currentState -= 2;
            if (currentState < 1) {
                currentState = 1;
            }
            cout << "Moved left. Current state: " << currentState << endl;
        } else {
            cout << "Cannot move left from the current state." << endl;
        }
    }

    int getCurrentState() {
        return currentState;
    }
};

int main() {
    StateMachine sm;
    int input;

    while (true) {
        cout << "Enter a key (2 for backward, 4 for left, 6 for right, 8 for forward, 0 to exit): ";
        cin >> input;

        if (input == 8) {
            sm.moveForward();
        } else if (input == 6) {
            sm.moveRight();
        } else if (input == 4) {
            sm.moveLeft();
        } else if (input == 2) {
            sm.moveBackward();
        } else if (input == 0) {
            break;
        } else {
            cout << "Invalid input. Please enter a valid key." << endl;
        }
    }

    return 0;
}