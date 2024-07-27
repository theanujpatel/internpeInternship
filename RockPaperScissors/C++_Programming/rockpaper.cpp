#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string getComputerChoice() {
    int randomChoice = rand() % 3;
    if (randomChoice == 0) return "Rock";
    else if (randomChoice == 1) return "Paper";
    else return "Scissors";
}

string getUserChoice() {
    string choice;
    cout << "Enter Rock, Paper, or Scissors (or Q to quit): ";
    cin >> choice;
    // Convert user input to first letter uppercase and the rest lowercase
    for (auto &c : choice) c = tolower(c);
    choice[0] = toupper(choice[0]);
    return choice;
}

void determineWinner(string userChoice, string computerChoice) {
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == "Rock" && computerChoice == "Scissors") ||
               (userChoice == "Paper" && computerChoice == "Rock") ||
               (userChoice == "Scissors" && computerChoice == "Paper")) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
}

int main() {
    srand(time(0));  // Seed the random number generator
    string userChoice;
    
    while (true) {
        userChoice = getUserChoice();
        if (userChoice == "Q") {
            break;
        }
        string computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;
        determineWinner(userChoice, computerChoice);
    }

    cout << "Thank you for playing!" << endl;
    return 0;
}

