#include <bits/stdc++.h>
using namespace std;

class Cell {

	public:
       Cell();
	   void setMark( int );
	   int getMark();

	private:
           int mark;


};

Cell::Cell() {	
	mark = -2; // this is initial value, set 0 for O and 1 for x
   }

   void Cell::setMark( int iVal) {
	mark = iVal;
   }

   int Cell::getMark() {
	return( mark );
   }


class Player {

   public:	
	Player();
	Player( string);

	// void inputPlayerInfo();
	void setName( string );
	string getName();
	
	
	void setPlayerToken( string );	
	string getToken();

   private:
	string Name;
	
	string token;


};

Player::Player() {
	Name = " ";
	token=" ";
}

Player::Player( string fname) {
		setName( fname );
}

	// void Player::inputPlayerInfo() {
		
	// string fname;
	// string lname; 
	// static int personCounter = 1;

	// cout << "Player " << personCounter << ":  Enter your first name: " << endl;
	//     cin >> fname;
	//     setFirstName( fname );
	//     cout << "Enter your last name: " << endl;
	//     cin >> lname;
	//     setLastName( lname );	
	// personCounter++;	
	// }	

	void Player::setName( string fname ) {
		Name = fname;
	}

	string Player::getName() {
		return( Name );
	}

	void Player::setPlayerToken( string marker ) {
		token = marker;
	}

	string Player::getToken() {
		return( token );
}


class TicTacToe{
public:
	TicTacToe();
	TicTacToe(string,string);
	void reset();
	string next_turn_query();
	int place_x(int,int,int);
	int place_o(int,int,int);

	void viewBoard();


private:
	int lastmove=-1;
	Cell Board[3][3];
	//int currentPlayer=-2;
	Player players[2];
	vector<int>moves;
};

// default constructor
TicTacToe::TicTacToe(){

}

TicTacToe::TicTacToe(string name1,string name2){
	players[0].setName(name1);
	players[1].setName(name2);

}

void TicTacToe::viewBoard(){
	cout<<"Board: "<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<Board[i][j].getMark();
		}
		cout<<endl;
	}
	cout<<endl;

}

void TicTacToe::reset(){
	// set all values of cells to -2
	// clearing the cells
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			Board[i][j].setMark(-2);
		}
	}

	moves.clear();
	lastmove=-1;
	//viewBoard(); testing statement

} 


string TicTacToe::next_turn_query(){
	if(lastmove==-1){
		return "Anyone";
	}

	int current=1-lastmove;
	return players[current].getName();
}


int TicTacToe::place_x(int pl,int i,int j){
	if(pl!=1 || pl!=2){
		cout<<"invalid input"<<endl;
		return 0;
	}

	if(i<0 || i>2 || j<0 || j>2){
		cout<<"invalid input"<<e
		return 0;
	}

	if(pl==lastmove){
		cout<<"invalid input"<<e
		return 0;
	}

	if(Board[i][j].getMark()!=-2){
		cout<<"invalid input"<<e
		return 0;
	}

	


}









