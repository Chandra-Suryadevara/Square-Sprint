#include "../Headers/HighScoreManager.hpp"
#include <iostream>
#include <fstream>
#include <filesystem> 

using namespace std;
namespace fs = std::filesystem;

HighScoreManager::HighScoreManager() {
    // Create directories if they don't exist
    fs::path directory = "square_sprint/score_keeper";
    fs::create_directories(directory);
    fileName = directory / "high_scores.txt";
}

void HighScoreManager::saveHighScore(int score) {
    ifstream inFile(fileName); // Open file for reading
    ofstream outFile("square_sprint/score_keeper/temp.txt"); // Open temporary file for writing
    bool updated = false; // Flag to track if score has been updated

    if (outFile.is_open()) {
        if (inFile.is_open()) {
            int currentHighScore;
            while (inFile >> currentHighScore) {
                if (score > currentHighScore) {
                    outFile << score << endl; // Write the new high score
                    updated = true; // Set flag to true
                } else {
                    outFile << currentHighScore << endl; // Write the existing high score
                }
            }
            inFile.close(); // Close input file
        } else {
            // If the input file doesn't exist, continue writing
            outFile << score << endl;
            updated = true;
        }
        
        outFile.close(); // Close temporary file
        remove(fileName.c_str()); // Delete original file
        rename("square_sprint/score_keeper/temp.txt", fileName.c_str()); // Rename temporary file to original
        if (updated) {
            cout << "High score updated successfully!" << endl;
        } else {
            cout << "High score not higher than current high score." << endl;
        }
    } else {
        cout << "Error opening files!" << endl;
    }
}


int HighScoreManager::getHighScore() {
    ifstream inFile(fileName); // Open file for reading
    int highScore = 0;
    int currentScore;

    if (inFile.is_open()) {
        while (inFile >> currentScore) {
            if (currentScore > highScore) {
                highScore = currentScore;
            }
        }
        inFile.close(); // Close input file
        return highScore;
    } else {
        cout << "Error opening file for reading high score!" << endl;
        return -1; // Return -1 to indicate error
    }
}
