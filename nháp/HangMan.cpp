#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

string FIGURE[] = {
    "   ---------------     \n"
    "   |                   \n"
    "   |                   \n"
    "   |                   \n"
    "   |                   \n"
    " -----                 \n",


    "   ---------------     \n"
    "   |            |       \n"
    "   |                   \n"
    "   |                   \n"
    "   |                   \n"
    " -----                 \n",


    "   ---------------     \n"
    "   |            |       \n"
    "   |            O      \n"
    "   |                   \n"
    "   |                   \n"
    " -----                 \n",


    "   ---------------     \n"
    "   |            |       \n"
    "   |            O      \n"
    "   |            |      \n"
    "   |                   \n"
    " -----                 \n",



    "   ---------------     \n"
    "   |            |       \n"
    "   |            O      \n"
    "   |           /|      \n"
    "   |                   \n"
    " -----                 \n",


    "   ---------------     \n"
    "   |            |       \n"
    "   |            O      \n"
    "   |           /|\\     \n"
    "   |                   \n"
    " -----                 \n",



    "   ---------------     \n"
    "   |            |       \n"
    "   |            O      \n"
    "   |           /|\\     \n"
    "   |           /       \n"
    " -----                 \n",



    "   ---------------     \n"
    "   |            |       \n"
    "   |            O      \n"
    "   |           /|\\     \n"
    "   |           / \\      \n"
    " -----                 \n",     

};


void renderGame(string guessedWord, int badGuessCount);
bool contain(string secretWord, char guess );
string update(string guessedWord,string secretWord,char guess);
char readGuess();
int main () 
{   
    string secretWord = "Congratulations";
    string guessedWord = string(secretWord.length(), '-');
    int badGuessCount = 0;

    
    do
    {
        renderGame(guessedWord, badGuessCount);
        char guess = readGuess();
        if (contain(secretWord, guess ))
            guessedWord = update( guessedWord, secretWord, guess);       
        else     
            badGuessCount ++;       

    } while (badGuessCount < 7 && secretWord != guessedWord);

    renderGame(guessedWord, badGuessCount);
    if (badGuessCount < 7) cout << "Congratulations! You win!";
    else cout << "You lost. The correct word is " << secretWord;

    
    return 0;
    
}


bool contain(string secretWord, char guess )
{
    int len = secretWord.length();
    for (int i=0; i<len; i++)
        if (guess == secretWord[i])
            return true;

    return false;
}

string update(string guessedWord,string secretWord,char guess)
{
    int len = secretWord.length();
    for (int i=0; i<len ; i++)
        if (guess == secretWord[i])
            guessedWord[i] = guess;

    return guessedWord;
}
void renderGame(string guessedWord, int badGuessCount)
{
    cout << FIGURE[badGuessCount] << endl;

    cout << "This is word you guessed : " << guessedWord << endl;
    cout << "The number of yourr guess : " << badGuessCount << endl;

}

char readGuess()
{
    char c;
    cout << "Can you guess 1 letter in the secret word ?    " ;
    cin >> c;
    return c; 
}