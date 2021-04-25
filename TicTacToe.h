#include <iostream>
#include <string>
#include <vector>
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
	string checkforWinner();


private:
	int lastmove=-1;
	Cell Board[3][3];
	//int currentPlayer=-2;
	Player players[2];
	vector<int>moves;
	bool gameover=false;
	string statement=" ";
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
	gameover=false;
	statement=" ";
	//viewBoard(); testing statement

} 


string TicTacToe::next_turn_query(){
	if(lastmove==-1){
		return "Anyone";
	}

	int current=1-lastmove;
	return players[current].getName();
}

string TicTacToe::checkforWinner(){
	bool win_x=false,win_o=false;
	int mark=1;
	// first check for x

	// check for rows
	for(int i=0;i<3;i++){
		if(Board[i][0].getMark()==mark && Board[i][1].getMark()==mark && Board[i][2].getMark()==mark ){
			win_x=true;
			break;
		}
	}

	// check the columns
	for(int j=0;j<3;j++){
		if(Board[0][j].getMark()==mark && Board[1][j].getMark()==mark && Board[2][j].getMark()==mark ){
			win_x=true;
			break;
		}
	}


	// check the main diagonal
	if(Board[0][0].getMark()==mark && Board[1][1].getMark()==mark && Board[2][2].getMark()==mark ){
		win_x=true;
	}

	// check the transverse diagonal
	if(Board[0][2].getMark()==mark && Board[1][1].getMark()==mark && Board[2][0].getMark()==mark ){
		win_x=true;
	}

	// Now check for O
	mark=0;
	// check for rows
	for(int i=0;i<3;i++){
		if(Board[i][0].getMark()==mark && Board[i][1].getMark()==mark && Board[i][2].getMark()==mark ){
			win_o=true;
			break;
		}
	}

	// check the columns
	for(int j=0;j<3;j++){
		if(Board[0][j].getMark()==mark && Board[1][j].getMark()==mark && Board[2][j].getMark()==mark ){
			win_o=true;
			break;
		}
	}


	// check the main diagonal
	if(Board[0][0].getMark()==mark && Board[1][1].getMark()==mark && Board[2][2].getMark()==mark ){
		win_o=true;
	}

	// check the transverse diagonal
	if(Board[0][2].getMark()==mark && Board[1][1].getMark()==mark && Board[2][0].getMark()==mark ){
		win_o=true;
	}

	/*if(win_x && win_o){
		cout<<"Garbar hai"<<endl;
		return "Nonsense";
	}*/

	if(win_x){
		return "win";
	}

	if(win_o){
		return "win";
	}

	return "nothing";


}


int TicTacToe::place_x(int pl,int i,int j){

	if(gameover){
		cout<<statement<<endl;
		return 2;
	}
	// check for invalid conditions
	if(!(pl==1 || pl==2)){
		cout<<"invalid input"<<endl;
		return 0;
	}

	if(i<0 || i>2 || j<0 || j>2){
		cout<<"invalid input"<<endl;
		return 0;
	}

	if((pl-1)==lastmove){
		cout<<"invalid input"<<endl;
		return 0;
	}

	if(Board[i][j].getMark()!=-2){
		cout<<"invalid input"<<endl;
		return 0;
	}

	// make the move
	Board[i][j].setMark(1);
	pl--;
	moves.push_back(pl);
	lastmove=pl;

	// ask if there is a winner or it is a tie
	string ch=checkforWinner();
	// if(ch=="Garbar"){
	// 	return 0;
	// }

	if(ch=="win"){
		string winner=players[pl].getName();
		cout<<"game over! "<<winner<<" wins!"<<endl;
		statement="game over! "+winner+" wins!";
		//cout<<"("<<winner<<" made the most recent move that led to a winning condition)"<<endl;
		gameover=true;
		return 2;
	}

	if(moves.size()>=9){
		// then it is a tie
		cout<<"game over! It is a tie!"<<endl;
		statement="game over! It is a tie!";
		gameover=true;
		return 2;
	}

	return 1;

	


}


int TicTacToe::place_o(int pl,int i,int j){

	if(gameover){
		cout<<statement<<endl;
		return 2;
	}


	// check for invalid conditions
	if(pl!=1 && pl!=2){
		cout<<"invalid input"<<endl;
		return 0;
	}

	if(i<0 || i>2 || j<0 || j>2){
		cout<<"invalid input"<<endl;
		return 0;
	}

	if((pl-1)==lastmove){
		cout<<"invalid input"<<endl;
		return 0;
	}

	if(Board[i][j].getMark()!=-2){
		cout<<"invalid input"<<endl;
		return 0;
	}

	// make the move
	Board[i][j].setMark(0);
	pl--;
	moves.push_back(pl);
	lastmove=pl;

	// ask if there is a winner or it is a tie
	string ch=checkforWinner();
	// if(ch=="Garbar"){
	// 	return 0;
	// }

	if(ch=="win"){
		string winner=players[pl].getName();
		cout<<"game over! "<<winner<<" wins!"<<endl;
		statement="game over! "+winner+" wins!";
		//cout<<"("<<winner<<" made the most recent move that led to a winning condition)"<<endl;
		gameover=true;
		return 2;
	}

	if(moves.size()==9){
		// then it is a tie
		cout<<"game over! It is a tie!"<<endl;
		statement="game over! It is a tie!";
		gameover=true;
		return 2;
	}

	return 1;
}


