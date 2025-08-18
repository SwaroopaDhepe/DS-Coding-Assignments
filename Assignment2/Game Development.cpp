/*Game Development:
Write a game development program that implements the Bubble Sort algorithm. The program will simulate a simple game where the player can input a set of numbers, and the numbers will be sorted using Bubble Sort to simulate a "level-up" scenario where the player's scores are sorted in ascending order.*/

#include<iostream>
#include<string>
using namespace std;
int main(){
	int player1[5], player2[5];
	cout<<"Enter scores of player 1:\n";
	for(int i=0; i<5; i++){
		cin>>player1[i];
	}
	cout<<"Enter scores of player 2:\n";
	for(int i=0; i<5; i++){
		cin>>player2[i];
	}
	for( int p=0; p<5; p++){
		for(int j=0; j<5-p-1; j++){
			if(player1[j]<player1[j+1]){
				int temp= player1[j];
				player1[j]= player1[j+1];
				player1[j+1]= temp;
				cout<<"\nSwapping score"<<" "<<player1[j]<<" "<<"with"<<" "<<player1[j+1]<<" "<<"\nLevel up!\n";
			}
		}
	}
	for( int p=0; p<5; p++){
		for(int j=0; j<5-p-1; j++){
			if(player2[j]<player2[j+1]){
				int temp= player2[j];
				player2[j]= player2[j+1];
				player2[j+1]= temp;
				cout<<"\nSwapping score"<<" "<<player2[j]<<" "<<"with"<<" "<<player2[j+1]<<" "<<"\nLevel up!\n";
			}
		}
	}
	cout<<"\nSorted scores of player 1: ";
	for(int i=0; i<5; i++){
		cout<<player1[i]<<" ";
	}
	cout<<"\nSorted scores of player 2: ";
	for(int i=0; i<5; i++){
		cout<<player2[i]<<" ";
	}
	if(player1[0]>player2[0]){
		cout<<"\n--------------------------------";
		cout<<"\nPlayer 1 is the winner!";
	}
	else if(player2[0]>player1[0]){
		cout<<"\n--------------------------------";
		cout<<"\nPlayer 2 is the winner!";
	}
	else{
		cout<<"\n--------------------------------";
		cout<<"\nThere is a tie!";
	}
	return 0;
}
