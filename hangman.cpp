#include<stdio.h>
#include<stdlib.h>
#include<string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printTitle(){
    system("CLS");
    string titulo[7];
    titulo[0]="      #                                          #######                             \n";
    titulo[1]="      #  ####   ####   ####     #####    ##      #        ####  #####   ####    ##   \n";
    titulo[2]="      # #    # #    # #    #    #    #  #  #     #       #    # #    # #    #  #  #  \n";
    titulo[3]="      # #    # #      #    #    #    # #    #    #####   #    # #    # #      #    # \n";
    titulo[4]="#     # #    # #  ### #    #    #    # ######    #       #    # #####  #      ###### \n";
    titulo[5]="#     # #    # #    # #    #    #    # #    #    #       #    # #   #  #    # #    # \n";
    titulo[6]=" #####   ####   ####   ####     #####  #    #    #        ####  #    #  ####  #    # \n";
    
    for(int i = 0; i<7; i++ ){
        printf("%s", titulo[i].c_str());
    }
     system("PAUSE");
}

string gameState(string state){
    if (state == "LOST")return "LOST";
    if (state== "WIN") return "WIN";
}

void printHangman(int guesses){
    printf("You have %d guesses left.\n", guesses);

}

bool isThere(char letter, string word){
    for(int i = 0; i < (word.length()); i++){
        if (word[i] == letter) return true;
    }
    return false;
}

int printLetters(vector<char> lettersFound, string testWord){
    int x = 1;
    printf("\n");
    for (int i = 0; i < (testWord.size()); i++)
    {
        if(find(lettersFound.begin(), lettersFound.end(), testWord[i]) != lettersFound.end()){
            printf(" %c ", testWord[i]);
        }
        else 
        {
            printf(" _ ");
            x = 0;                
        }
            
    }
    printf("\n");
    return x;
}

// string chooseWord(){
//     return "perfeito";
// }

void gameStart(){
    //preparation
    printTitle();
    int end = 0;
    string word = "gorilla";
    int wordSize = word.length();
    int guessesLeft = 10;
    vector<char> found; //has to have constant value. using 32 as a placeholder size
    char letter;
    string msg = "\n\n Game Start! \n\n";
    string state="";
    int win = 0;

    //gameloop
    while(end!=1){
        system("CLS");
        if(guessesLeft == 0){
            end = 1;
            state = "\n \n YOU LOST\n";
        }
        letter='0';
        printHangman(guessesLeft);
        win = printLetters(found, word);
        if(win == 1) {state = "\n \n YOU WON\n"; break;}
        printf("%s\n", msg.c_str());
        printf("Choose a letter: ");
        scanf(" %c", &letter);
        printf("\n");
        if(isThere(letter, word))
        {
            found.push_back(letter);
            msg = "\n \n You got it right!\n";
        } 
        else if(!isThere(letter, word))
        {
            msg = "\n \n Letter not found. \n";
            guessesLeft -= 1;            
        }
           

    }
    printf("%s \n", state.c_str());
    system("PAUSE");
}


int main(int argc, char const *argv[]){
    gameStart();
    return 0;
}