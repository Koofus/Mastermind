#include <iostream>;
#include <string>;

using namespace std;

class mastermind {
	
	private:
		int guess_counter = 0;
		int compare_row_counter = 0;
		bool quit_game = false;
		string color1, color2, color3, color4;
		string master_code[4] = {"black","black","black","black"};
		string playing_board[12][4] = {{"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
									   {"     ","     ","     ","     "},
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
		void setcode(string one, string two, string three, string four){
			
			master_code[0] = one;
			master_code[1] = two;
			master_code[2] = three;
			master_code[3] = four;
			
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
			
			for(int i=0; i<=11; i++){
				display_row(i);
			}
			
		}
		
		void compare_to_master(int row){
			int k = 0;
			int red_peg = 0;
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
				if (red_peg == 4) {
					string choice;
					cout << "You guessed the right code!!!!!!!\nWould you like to play again? Type yes or no";
					cin >> choice;
					if (choice == "no") { 
						
						system("quit");
						
					}		
				}
				k++;
		}
		
		}
		void guess_code(int guess_counter) {
			cout << "Code Breaker guess the Code" << endl;
			cout << "Enter first color\n";
			cin >> color1;
			cout << "Enter second color\n";
			cin >> color2;
			cout << "Enter third color\n";
			cin >> color3;
			cout << "Enter fourth color\n";
			cin >> color4;
			setrow(guess_counter, color1,color2,color3,color4);
		}		
		
		void play_game(){
			
			cout << "Welcome to Mastermind\n";
			cout << "Code Maker\nEnter your Color Code Using Blue, Yellow, Red, Orange, Purple, Green Colors\nNo Duplicates No Empties for Now\n";
	
			cout << "Enter first color\n";
			cin >> color1;
			cout << "Enter second color\n";
			cin >> color2;
			cout << "Enter third color\n";
			cin >> color3;
			cout << "Enter fourth color\n";
			cin >> color4;
			setcode(color1,color2,color3,color4);
			
			for(int i = 0; i < 12; i++){
				guess_code(guess_counter);
				guess_counter++;
				compare_to_master(compare_row_counter);
				compare_row_counter++;
				display_game_board();	
			}
		}
			
};
		


int main()
{
	mastermind game;
	
	string color1, color2, color3, color4;
	bool run_state = true;
	while(run_state){
		game.play_game();
	}
}
		
	
	

