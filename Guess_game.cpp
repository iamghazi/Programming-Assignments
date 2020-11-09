
/*Name: Shaista Rehan
Program 11 Page 890

Sample Input/Output:


GUESSING GAME                                                                                                                                   
*****************************                                                                                                                   
Press 1 for Human Player vs Human Player                                                                                                        
Press 2 for Human Player vs Computer                                                                                                            
Press 3 for Computer vs Computer                                                                                                                
*****************************                                                                                                                   
3                                                                                                                                               
Player 1's turn to guess.                                                                                                                       
You guess 29. Your guess is too low.                                                                                                            
Player 2's turn to guess.                                                                                                                       
You guess 78. Your guess is too high.                                                                                                           
Player 1's turn to guess.                                                                                                                       
You guess 55. Your guess is too high.                                                                                                           
Player 2's turn to guess.                                                                                                                       
You guess 34. Your guess is too low.                                                                                                            
Player 1's turn to guess.                                                                                                                       
You guess 54. Your guess is too high.                                                                                                           
Player 2's turn to guess.                                                                                                                       
You guess 49. You're right! You win!                                                                                                            
Do you want to play again? (y/n)
y
*****************************                                                                                                                   
Press 1 for Human Player vs Human Player                                                                                                        
Press 2 for Human Player vs Computer                                                                                                            
Press 3 for Computer vs Computer                                                                                                                
*****************************                                                                                                                   
2                                                                                                                                               
Player 1's turn to guess.                                                                                                                       
Enter a number                                                                                                                                  
56                                                                                                                                              
You guess 56. Your guess is too high.                                                                                                           
Player 2's turn to guess.                                                                                                                       
You guess 10. Your guess is too low.                                                                                                            
Player 1's turn to guess.                                                                                                                       
Enter a number                                                                                                                                  
40                                                                                                                                              
You guess 40. Your guess is too low.                                                                                                            
Player 2's turn to guess.                                                                                                                       
You guess 47. Your guess is too high.                                                                                                           
Player 1's turn to guess.                                                                                                                       
Enter a number                                                                                                                                  
45                                                                                                                                              
You guess 45. Your guess is too high.                                                                                                           
Player 2's turn to guess.                                                                                                                       
You guess 43. You're right! You win!                                                                                                            
Do you want to play again? (y/n)
*/


#include <iostream>
#include <stdlib.h>
using namespace std;
int high=100,low=-1;

class Player
{
  public:
    virtual int getGuess()
    {
      return 0;
    }
};
class HumanPlayer: public Player    //Child class of parent class player
{
  public:
    virtual int getGuess()
    {
      cout<<"Enter a number"<<endl;
      int t;
      cin>>t;
      return t;
    }
};
class ComputerPlayer: public Player  //Child class
{ 
  int guess_number=0;  //number to store whether the guess is first or not and if its 0  then it makes a random guess
  public:
    virtual int getGuess()
    {
     
     int t=(rand()%(high-low+1))+low;
     return t;
    
    }
};
bool checkForWin(int guess, int answer)
{ 
  cout<< "You guess " << guess << ". ";
  if (answer == guess)
  {
    cout<< "You're right! You win!" <<endl;
    return true;
  }
  else if (answer < guess)
  {
    cout<< "Your guess is too high."<<endl;
    if(guess<high)
    high=guess-1;               //if the last guess was too high means the answer must be lower than that guess so fixing
                                //the upper value to the lowest guessed number
   }
  else
  {
    cout<< "Your guess is too low." <<endl;
    if(guess>low)              //if the last guess was too low means the answer must be highee than that guess so fixing
    low=guess+1;              //the lower value to the highest guessed number  
  }
  return false;
}
void play(Player &player1, Player &player2)
{
  int answer = 0, guess = 0;
  answer = rand() % 100;
  bool win = false;
  while (!win)
  {
    cout<< "Player 1's turn to guess." <<endl;
    guess = player1.getGuess();
    win = checkForWin(guess, answer);
    if (win) return;
    cout<< "Player 2's turn to guess." <<endl;
    guess = player2.getGuess();
    win = checkForWin(guess, answer);
  }
}

int main()
{ 
  char ans;
  cout<<"GUESSING GAME"<<endl;
  do{
  cout <<"*****************************\n";      
  cout<<"Press 1 for Human Player vs Human Player"<<endl;
  cout<<"Press 2 for Human Player vs Computer"<<endl;
  cout<<"Press 3 for Computer vs Computer"<<endl;
  cout <<"*****************************\n";
  int choice;
  cin>>choice;
  srand (time(NULL));
  if(choice==1)
  {
    HumanPlayer player1,player2;
    play(player1,player2);
  }
  if(choice==2)
  {
    HumanPlayer player1;
    ComputerPlayer player2;
    play(player1,player2);
  }
  if(choice==3)
  {
    ComputerPlayer player1,player2;
    play(player1,player2);
  }
  cout <<"Do you want to play again? (y/n)" <<endl;
  cin >> ans;
  }while(ans == 'y' || ans == 'Y');
  
  
}


