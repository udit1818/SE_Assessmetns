#include <iostream>
#include <cstdlib>  
#include <ctime>    

using namespace std;

// Function to display the menu and get the player's choice
int getPlayerChoice() {
    int choice;
    cout << "1) ROCK" << endl;
    cout << "2) PAPER" << endl;
    cout << "3) SCISSOR" << endl;
    cout << "-> Select Your Choice: ";
    cin >> choice;
    return choice;
}

// Function to determine the winner of a round
string determineWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) {
        return "Draw";
    } else if ((playerChoice == 1 && computerChoice == 3) ||
               (playerChoice == 2 && computerChoice == 1) ||
               (playerChoice == 3 && computerChoice == 2)) {
        return "Player Wins";
    } else {
        return "Computer Wins";
    }
}

int main() {
    string playerName;
    int rounds, playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;

    // Seed the random number generator
    srand(time(0));

    // Step 1: Accept the player's name
    cout << "NAME" << endl;
    cout << "Enter Your Name: ";
    cin >> playerName;

    // Step 2: Enter the number of rounds to play
    cout << "ROUNDS" << endl;
    cout << playerName << ", How Many Rounds You Want To Play? : ";
    cin >> rounds;

    // Game loop for each round
    for (int round = 1; round <= rounds; round++) {
        cout << "\n---\nGAME\n";
        cout << "Round No: " << round << "/" << rounds << endl;
        cout << "* " << playerName << "'s Score = " << playerScore << endl;
        cout << "* Computer Score = " << computerScore << endl;

        // Step 3: Get the player's choice
        playerChoice = getPlayerChoice();

        // Generate a random choice for the computer
        computerChoice = (rand() % 3) + 1;

        cout << "-> Computer Choice Is: " << computerChoice << endl;

        // Determine the winner of the round
        string result = determineWinner(playerChoice, computerChoice);
        cout << result << endl;

        // Update scores based on the result
        if (result == "Player Wins") {
            playerScore++;
        } else if (result == "Computer Wins") {
            computerScore++;
        }


    }

    // Final result of the game
    cout << "\n---\nFinal Result\n";
    cout << "* " << playerName << "'s Score = " << playerScore << endl;
    cout << "* Computer Score = " << computerScore << endl;

    if (playerScore > computerScore) {
        cout << playerName << " Wins the Game!" << endl;
    } else if (computerScore > playerScore) {
        cout << "Computer Wins the Game!" << endl;
    } else {
        cout << "Game Is Drawn" << endl;
    }

    return 0;
}
