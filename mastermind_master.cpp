#include <iostream>;
#include <string>;

using namespace std;

class mastermind {
	
	private:
		string color1, color2, color3, color4;
		string master_code[4] = {"black","black","black","black"};
		string playing_board[12][4] = {{"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"},
									   {"black","black","black","black"}
		};
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
				k++;
				red_peg++;
				if (red_peg == 4){
					cout << "You won the game" << endl;
				}
					
				continue;
				}			
				else if(playing_board[row][i] == master_code[k+1] || playing_board[row][i] == master_code[k+2] || playing_board[row][i] == master_code[k+3]){
					cout << "You acquired a white peg\n";
				}
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
			
			
};
		



int main()
{
	mastermind game;
	
	string color1, color2, color3, color4;
	
	int guess_counter = 0;
	int compare_counter = 0;
	
	cout << "Welcome to Mastermind\n";
	cout << "Code Maker Enter your Code Using Four Colors No Duplicates No Empties for now\n";
	
	cout << "Enter first color\n";
	cin >> color1;
	cout << "Enter second color\n";
	cin >> color2;
	cout << "Enter third color\n";
	cin >> color3;
	cout << "Enter fourth color\n";
	cin >> color4;
	game.setcode(color1,color2,color3,color4);
	
	game.guess_code(guess_counter);
	guess_counter++;
	game.compare_to_master(compare_counter);
	
}
	

