#include "TicTacToe.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
	cout<<"Hello\n";
	// Player p1;
	// p1.setName("Rake");
	// cout<<p1.getName()<<endl;


	// vector<Player>players(2);
	// players[0].setName("Rake");
	// players[1].setName("Sunil");
	// cout<<players[0].getName()<<" "<<players[1].getName()<<endl;
	string user_name_1 = "Mary";
	string user_name_2 = "Sam";
	TicTacToe board = TicTacToe(user_name_1,user_name_2);
	int ret_val;
	string nxt_turn;
	nxt_turn = board.next_turn_query();
	cout<<nxt_turn<<endl;
	//board.viewBoard();


	return 0;
}