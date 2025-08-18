/*Load Balancing:
For example, imagine you have a set of servers that handle requests for a web application. The
key to load balancing is using the hash value of a client's IP address or a request ID to
determine which server should handle the request. The hash function is typically designed so
that the data is evenly distributed across the servers, ensuring that no single server is
overloaded. Write a program of a load balancing system*/

#include<iostream>
using namespace std;
int main(){
int servers;
cout<<"Enter the number of servers: ";
cin>>servers;
//Check if the number of servers is valid(> 0)
if(servers <= 0){
cout<<"Invalid number of servers!"<<endl;
}
//Define the maximum number of requests the program can handle
const int max_req=100;
//Arrays to store request IDs and assigned server numbers
int req[max_req];
int assign[max_req];
int count=0;
int requestID;
//Counter to keep track of how many requests have been processed
char choice;
cout<<"\n---Load Balancer Started---\n";
do{
cout<<"Enter request ID (integer): ";
cin>>requestID;
//Using modulo operation to distribute requests evenly among servers
int hash_val = requestID % servers;
cout<<"Request "<<requestID <<" is assigned to Server " <<hash_val<<endl;
//Store request and assignment
req[count] = requestID;
assign[count] = hash_val;
count++;
cout<<"Do you want to add another request? (y/n): ";
cin>>choice;
}while(choice == 'y' || choice == 'Y');
cout<<"\n--- Load Balancer Stopped ---"<<endl;
cout << "\nSummary of Requests Assigned:\n";
cout << "--------------------------------\n";
cout << "Request ID\tAssigned Server\n";
cout << "--------------------------------\n";
for (int i = 0; i < count; i++) {
cout <<req[i] << "\t\tServer " << assign[i] <<" \n";
}
cout << "--------------------------------\n";
return 0;
}
