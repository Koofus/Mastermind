#include <iostream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

class mastermind {
	
	private:
		string color1, color2, color3, color4;
		string master_code[4];
		string master_catalog[6] = {"Yellow","Blue","Red","Orange","Purple","Green"};
		string playing_board[10][4] = {{"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "}};
									  
	public:
		void setindex(int y, int x, string choice){
			playing_board[y][x] = choice;
		}
		void setcode(){
			srand(time(0));
			master_code[0] = master_catalog[rand() % 6];
			master_code[1] = master_catalog[rand() % 6];
			master_code[2] = master_catalog[rand() % 6];
			master_code[3] = master_catalog[rand() % 6];
		}
		void setrow(int row, string choice_one, string choice_two, string choice_three, string choice_four) {
			
				setindex(row,0,choice_one);
				setindex(row,1,choice_two);
				setindex(row,2,choice_three);
				setindex(row,3,choice_four);
		}
		void display_row(int row){
			cout << "|" << playing_board[row][0] << "|" << "|" << playing_board[row][1] << "|"<< "|" << playing_board[row][2] 
			<< "|"<< "|" << playing_board[row][3] << "|" << endl;
		}
		void display_master_code(){
			cout << "|" << master_code[0] << "|" << "|" << master_code[1] << "|"<< "|" << master_code[2] 
			<< "|"<< "|" << master_code[3] << "|" << endl;
		}
		void display_game_board(){
			
			for(int i=0; i<=9; i++){
				display_row(i);
			}
			
		}
		void compare_to_master(int row){
			int k = 0;
			int red_peg = 0;
			
			cout << endl << endl;
			
		 	for(int i = 0; i < 4; i++){
				if(playing_board[row][i] == master_code[k]){
				cout << "You got a red peg\n";
				red_peg++;
				}			
				else if(playing_board[row][i] == master_code[3] || playing_board[row][i] == master_code[2]
				 || playing_board[row][i] == master_code[1] || playing_board[row][i] == master_code[0]){
					cout << "You acquired a white peg\n";
				}else{
					cout << "No Match\n";
				}
				k++;
			}
			if (red_peg == 4){
				cout << "Sweet Job Boi You Guessed Right\n";
				exit(0);
			}
			cout << endl;
		}
		
		void guess_code(int guess_counter) {
			cout << "\nCode Breaker guess the Code" << endl;
			cout << "Enter your guess with spaces\n";
			cout << "Red, Yellow, Blue, Green, Orange, and Purple (case sensitive):\n";
			cin >> color1 >> color2 >> color3 >> color4;
			setrow(guess_counter, color1,color2,color3,color4);
		}		
			
			
};
		



int main()
{
	mastermind game;
	
	string color1, color2, color3, color4;
	
	int guess_counter = 0;
	int compare_row_counter = 0;
	
	cout << "Welcome to Mastermind\n";
	cout << "The computer generates a code for you to guess. \n";
	cout << "The code is 4 colors long.\n";
	cout << "The colors used are Red, Yellow, Blue, Green, Orange, and Purple (case sensitive).\n\n";
	
	game.setcode();
	
	for(int i = 0; i < 10; i++){
		game.guess_code(guess_counter);
		guess_counter++;
		game.compare_to_master(compare_row_counter);
		compare_row_counter++;
		game.display_game_board();	
	}
	
	cout << "This is so sad Alexa play despacito\n";
	
	return 0;
	
}
	

