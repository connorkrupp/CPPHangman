// Connor Krupp
// Hangman

#include <iostream>

std::string word;
std::string currentGuess;

void buildCurrentGuess();
bool wordSolved();
bool addLetter(char letter);

int main(int argc, char const *argv[]) {


  std::cout << "User 1 enter a word: ";
  std::cin >> word;

  buildCurrentGuess();

  int guessesRemaining = 5;
  while (!wordSolved()) {
    char letter;
    std::cout << "Guess a Letter: ";
    std::cin >> letter;

    if (!addLetter(letter)) {
      guessesRemaining--;
      std::cout << "Wrong! " << guessesRemaining << " guesses remaining..." << std::endl;
    }

    if (guessesRemaining == 0) {
      std::cout << "You Suck Ass!" << std::endl;
      return 0;
    }
  }

  std::cout << "Word Solved!" << std::endl;

  return 0;
}

// Modifies: currentGuess
// Effects: creates underscore+space version of word
void buildCurrentGuess() {
  for (size_t i = 0; i < word.size(); i++) {
    currentGuess.push_back('_');
    if (i != word.size() - 1) { currentGuess.push_back(' '); }
  }
}

// Effects: returns whether currentGuess is equivalent to the word
bool wordSolved() {
  std::string guessedWord;
  for (size_t i = 0; i < currentGuess.size(); i++) {
    char currentChar = currentGuess.at(i);
    if (currentChar != ' ' && currentChar != '_') {
      guessedWord.push_back(currentChar);
    }
  }

  if (word == guessedWord) {
    return true;
  }
  return false;
}

// Modifies: currentGuess
// Effects: returns false if letter is not found, otherwise writes letter to
// currentGuess
bool addLetter(char letter) {
  std::size_t index = word.find(letter);
  if (index != std::string::npos) {
    currentGuess.at((index+1) * 2 - 2) = letter;
    return true;
  }
  return false;
}
