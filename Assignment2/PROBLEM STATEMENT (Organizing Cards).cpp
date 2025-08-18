/*PROBLEM STATEMENT (Organizing Cards in a Hand):
Application: When playing card games, players often use an approach similar to insertion sort to organize their cards. They pick one card at a time and insert it into the correct position in their hand, maintaining a sorted sequence. Write a program that demonstrates how to organize (sort) cards in a hand using insertion sort.*/

#include<iostream>
using namespace std;
void displayHand(int cards[], int n){
	for(int i=0; i<n; i++){
		cout<<cards[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter number of cards: ";
	cin>>n;
	int cards[n];
	cout<<"\nEnter card values (eg. 8 1 4):\n";
	for(int i=0; i<n; i++){
		cin>>cards[i];
	}
	cout<<"\nOrganizing cards using Insertion Sort\n";
	for(int i=0; i<n; i++){
		int key=cards[i];
		int j=i-1;
		//Shift larger number to right
		while(j>=0 && cards[j]>key){
			cards[j+1]=cards[j];
			j--;
		}
		cards[j+1]=key;
		//Displaying cards after insertion sort
		cout<<"Step "<<i<<": ";
		displayHand( cards, n);
	}
	cout<<"\nFinal sorted hand: ";
	displayHand(cards, n);
	return 0;
} 
