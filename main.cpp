#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void addContact();


void deleteContact(){
	
}

void print(string contacts[20][3]){
	for(int x=0; x<20; x++){
		if(contacts[x][0] != ""){
			cout << x << ": " << contacts[x][0] << " " << contacts[x][1] << " - " << contacts[x][2] << endl;
		}
	}
}

int main(){
	string randNames[5] = {"Mario", "Giacomo", "Luca", "Elisa", "Silvia"};
	string randLnames[5] = {"Bianchi", "Pini", "Rossi", "Ferrari", "Galli"};
	string randNums[5] = {"3546493949", "5468546869", "5374638949", "5347594538", "5486754535"};
	
	string contacts[20][3];
	for(int x=0; x<10; x++){
		contacts[x][0] = randNames[rand() % 5];
		contacts[x][1] = randLnames[rand() % 5];
		contacts[x][2] = randNums[rand() % 5];
	}
	
	print(contacts);
}
