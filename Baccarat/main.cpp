// This program is the text base version of the pouplar casino game called Baccarat
// this will help people play the game and have phone

// This program will input American money and convert it to foreign currency

// Anangafac Alabaweh
// CSC-5-43410
// Last Modified: 4/24/2021

#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;




int player_g (int&, int&, int&); // this function will generate the random number for the player and also calculate the final value of the player
int p_num1, p_num2, b_num1, b_num2, bet_amount, banker, player; // this are the variables needed for the functions 
char bet_option, quit_option;
string result;
int banker_g (int&, int&, int&); // this function will generate the random number for the banker and also calculate the final value of the banker
void bet_function(); // this is the function that control the betting system of the game
void play_function(); // this is that function that comprises of the player, banker and bet function
int welcome_option;
 int count;
 char quit_option1, quit_option2;

int main()

{
     string line;
  ifstream myfile ("rules.txt"); // this iis the name of the file that will be read when the user select the rule option
  
    
  // first menu selection of the game

    cout << "Welcome the Baccarat game\n"
            << "1 = PLAY\n"
            << "2 = Rule of the game\n"
            << "3 = quit\n";
    cin >> welcome_option;
    
    
    // data validation
    while (!(welcome_option == 1 || welcome_option==2 || welcome_option==3))
    {
        cout << "please enter a valid option";
        cin >> welcome_option;
    }
    
    do 
    {
    
        if (welcome_option == 1)
        play_function ();
        
        else if (welcome_option==2)
        {
              
          while ( getline (myfile,line) )
               {
      cout << line << '\n';
    }
    myfile.close();  
    cout << endl;
    
    cout << "Do you can to continue playing Y/N\n";
    cin >> quit_option2;
        
    while (!(quit_option2 =='n' || quit_option2 =='N' || quit_option2=='y' || quit_option2 == 'Y'))
    {
        
        cout << "\nPlease input a valid option\n";
        cout << "Do you can to continue playing Y/N\n";
        cin >> quit_option2;
    }
    
    
   if ((quit_option2=='y' ||quit_option2 == 'Y')) {
    play_function ();
   }
   else cout <<"Thank you\n";
    }
        else if (welcome_option == 3)
   cout <<"Thank you\n";
    
    } while (!(welcome_option == 3) && !(quit_option=='n' ||quit_option == 'N') && !(quit_option2=='n' ||quit_option2 == 'N'));
    

 
          return 0;
}


// function for general random number generation
int player_g (int &p_num1, int &p_num2, int &player)
{ 
    srand (time(00));
   p_num1= (rand()%9); // first player random number generator
  
    p_num2= (rand()%9); // second  player random number generator
    (((p_num1 + p_num2)>10)? player=(p_num1 + p_num2)-10 : player = p_num1 + p_num2); // formula to determine the final value of the player
    
    if (player==10)
    player-=10;
    
   }

// funstion for banker number generation
int banker_g(int &b_num1, int &b_num2, int &banker)
{
    
     
   b_num1= (rand()%9); // first banker random number generator
  
    b_num2= (rand()%9); // second banker random number generator
    cout <<endl;
    
       (((b_num1 + b_num2)>10) ? banker=(b_num1 + b_num2)-10 : banker = b_num1 + b_num2); // formular to determine the final value for the banker
    
       if (banker==10)
    banker-=10;
       
    }

// this function will make the person palying to select their side 
void bet_function ()
{		 
            
      do
      {
    cout <<"Select your side \n"
         << "P = Player\n"
         << "B = Banker\n"
         << "T = Tie\n";
    cin >> bet_option;
    
    if (bet_option != 'B' && bet_option != 'b' && bet_option != 'P' && bet_option != 'p'&& bet_option != 'T' && bet_option != 't' ) // data validation
    {
        cout<< "Please input a valid selection\n";
    }
      } while (bet_option != 'B' && bet_option != 'b' && bet_option != 'P' && bet_option != 'p' && bet_option != 'T' && bet_option != 't' ); // end of do loop
      
         
            // this is the function for the bet input and results
    switch (bet_option)
    {
        case 'p':
        case 'P': {
        if (player>banker)
            result = "win";
        else result = "lose";
        
        };
                break;
        case 'b':
        case 'B': {
        if (banker>player)
            result = "win";
        else result = "lose";
        
        }  
        break;
            
        case 't':
        case 'T': {
        if (banker == player)
            result = "win";
       else result = "lose";
        
        }  
        break;
        
                     
    }
    
    cout <<"\nThe first and second draw  for player is " << p_num1 << " and " <<  p_num2 << "\n Player = " << player;
    
    cout << endl;
    
    cout <<"\nThe first and second draw  for banker is " << b_num1 << " and " <<  b_num2 << "\n  Banker = " << banker;
    cout << endl;
    
    cout << setprecision(2)<< fixed;
    
    // this statement will help determine if the user wins, lose or tie
       
    if (result == "win")
    {
      cout<<"\n Congratulation you won $" << bet_amount*2;
      cout <<endl;
        
    }
    else if (result == "lose")
    {
         cout<<"\n Sorry you lost, your current balance is $0.0\n";
    }
    else if (result == "tie")
    {
        cout << "\nIts a tie";
        
        cout<<"\n Congratulation you won $" << bet_amount*8;
        cout << endl;
	
    }}

void play_function ()
{
    do
    {
    cout<< "Welcome to the Baccarat Game\n"
         << "The minimum bet is $10\n"   
         << "The Maximum bet is $100.\n";  
    cout <<"How much will you love to bet \n$";
          while (!(cin >> bet_amount)) // data validation for the bet amount input
          {
              cout<<"Please input a valid amount $";
              cin.clear();
          cin.ignore(123,'\n');
          }
            
            while(bet_amount < 10 || bet_amount >100)
                    
            {
                 
                 if(bet_amount < 10)
                    cout<<"\nYou did place a bet less than the minimum amount\n";
                else if(bet_amount > 100)
                    cout<< "\nYou Exceeded the maximum amount\n";
                cout << "Please enter a valid amount\n";
                cin>> bet_amount;
            }
     
    player_g(p_num1, p_num2, player);
   
     banker_g(b_num1, b_num2, banker);
     
     bet_function();
     
     cout <<"Do you want to continue betting Y/N\n";
     cin >> quit_option;
             
     while (!(quit_option == 'y' || quit_option == 'Y' || quit_option == 'n' || quit_option == 'N')) // data validation
     {
         
         cout << "\nPlease enter Y/N if you will like continue betting\n";
         cin >> quit_option;
     }
     
     if(quit_option == 'n' || quit_option == 'N')
         cout << "Thank you for playing";
     
    } while (!(quit_option=='n' ||quit_option == 'N')); // end of do loop
    
}