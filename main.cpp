// Connor Krupp
// Hangman

#include <iostream>

std::string word;
std::string wordInProgress;

void buildWordInProgress();
bool wordSolved();
bool addLetter(char letter);
bool startGame();

int main(int argc, char const *argv[]) {

  std::cout << "User 1 enter a word: ";
  std::cin >> word;

  buildWordInProgress();

  if (startGame()) {
    std::cout << word << " Solved!" << std::endl;
  } else {
    std::cout << "You Suck Ass!" << std::endl;
  }

  return 0;
}

// Modifies: wordInProgress
// Effects: creates underscore+space version of word
void buildWordInProgress() {
  for (size_t i = 0; i < word.size(); i++) {
    wordInProgress.push_back('_');
    if (i != word.size() - 1) { wordInProgress.push_back(' '); }
  }
}

// Effects: returns whether wordInProgress is equivalent to the word
bool wordSolved() {
  std::string guessedWord;
  for (size_t i = 0; i < wordInProgress.size(); i++) {
    char currentChar = wordInProgress.at(i);
    if (currentChar != ' ' && currentChar != '_') {
      guessedWord.push_back(currentChar);
    }
  }

  if (word == guessedWord) {
    return true;
  }
  return false;
}

// Modifies: wordInProgress
// Effects: returns false if letter is not found, otherwise writes letter to
//          wordInProgress
bool addLetter(char letter) {
  std::size_t index = word.find(letter);
  if (index != std::string::npos) {
    wordInProgress.at((index+1) * 2 - 2) = letter;
    return true;
  }
  return false;
}

// Effects: returns whether the game was won or lost
bool startGame() {

  int guessesRemaining = 5;
  while (!wordSolved()) {
    char letter;
    std::cout << wordInProgress << std::endl;
    std::cout << "Guess a Letter: ";
    std::cin >> letter;

    if (!addLetter(letter)) {
      guessesRemaining--;
      std::cout << "Wrong! " << guessesRemaining << " guesses remaining..." << std::endl;
    }

    if (guessesRemaining == 0) {
      return false;
    }
  }
  return true;

}
