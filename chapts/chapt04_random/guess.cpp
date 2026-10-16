#include <iostream>
#include <iomanip>
#include <stdlib.h>

//CLI GAME
//the user has to guess a number between 1 and N>1: if the guess is incorrect,
//the program gives a new interval
int main(){
    srand(time(NULL));
    int N = 100;
    int min = 1;
    int max = 100;
    int ans = rand()%max + min;
    //std::cout<<"ANSWER "<<ans<<std::endl; 
    int guess;
    int counter = 0;
    do{
        std::cout<<"n in ["<<min<<","<<max<<"]"<<std::endl<<"Guess? ";
        std::cin>>guess;
        counter+=1;
        if(guess>ans) max=guess;
        else if(guess<ans) min=guess;
        else if(guess > max || guess < min) std::cout<<"Can't you read?"
                <<std::endl;
    }while(guess != ans);
    std::cout<<"You won in "<<counter<<" guesses!!"<<std::endl;
}
