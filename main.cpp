#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string contacts[20][3];

void addContact(string name, string lname, string number){
    if(contacts[19][0]=="") {
        for(int x=0; x<20; x++){
            if(contacts[x][0]==""){
                contacts[x][0] = name;
                contacts[x][1] = lname;
                contacts[x][2] = number;
                break;
            }
        }
    } else {
        cout << endl << endl << "Hai superato il limite di 20 contatti!" << endl << endl;
    }
}


void deleteContact(int index){
    for(int x=index; x<20; x++){
        contacts[x][0]=contacts[x+1][0];
        contacts[x][1]=contacts[x+1][1];
        contacts[x][2]=contacts[x+1][2];
    }
}

void print(){
    cout << "CONTATTI" << endl << endl;
    for(int x=0; x<20; x++){
        if(contacts[x][0] != ""){
            cout << x+1 << ": " << contacts[x][0] << " " << contacts[x][1] << " - " << contacts[x][2] << endl;
        }
    }
    
    cout << endl << "----------" << endl << endl << "1: Aggiungi contatto" << endl << "2: Elimina contatto" << endl << "3: Esci" << endl << endl;
    
    int command;
    
    cin >> command;
    
    if(command==1){
        string name, lname, number;
        cout << "Nome: ";
        cin >> name;
        cout << "Cogome: ";
        cin >> lname;
        cout << "Numero: ";
        cin >> number;
        addContact(name, lname, number);
        return;
    } else if(command==2){
        cout << "Quale contatto si vuole eliminare? ";
        cin >> command;
        deleteContact(command-1);
        return;
    } else if(command==3){
        exit(0);
    }
}

int main(){
    string randNames[5] = {"Mario", "Giacomo", "Luca", "Elisa", "Marco"};
    string randLnames[5] = {"Bianchi", "Pini", "Rossi", "Ferrari", "Galli"};
    string randNums[5] = {"+39 3546493949", "+39 3468546869", "+39 3374638949", "+39 3347594538", "+39 3486754535"};
    
    for(int x=0; x<10; x++){
        addContact(
            randNames[rand() % 5],
            randLnames[rand() % 5],
            randNums[rand() % 5]
        );
    }
            
    while(true){
        print();
    }
}
