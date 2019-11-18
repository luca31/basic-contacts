#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

string contacts[20][3];

void requireValue(string name, string &value){
    do{
        cout << name << ": ";
        getline(cin, value);
        if(value.empty()){
            cout << "  -> Questo campo è obbligatorio!" << endl;
        } else {
            cout << endl;
            break;
        }
    } while (true);
}

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
    for(int x=index; x<19; x++){
        contacts[x][0]=contacts[x+1][0];
        contacts[x][1]=contacts[x+1][1];
        contacts[x][2]=contacts[x+1][2];
    }
}

void print(){
    cout << "CONTATTI" << endl << endl;
    for(int x=0; x<20; x++){
        if(contacts[x][0] != ""){
            cout << x+1 << ": " << contacts[x][0] << " " << contacts[x][1] << " ~ " << contacts[x][2] << endl;
        }
    }
    
    cout << endl << "----------" << endl << endl << "1: Aggiungi contatto" << endl << "2: Elimina contatto" << endl << "3: Esci" << endl << endl;
}

void init(){
    string randNames[5] = {"Mario", "Giacomo", "Luca", "Elisa", "Marco"};
    string randLnames[5] = {"Bianchi", "Pini", "Rossi", "Ferrari", "Galli"};
    string randNums[5] = {"+393546493949", "+393468546869", "+393374638949", "+393347594538", "+393486754535"};
    
    for(int x=0; x<10; x++){
        addContact(
            randNames[rand() % 5],
            randLnames[rand() % 5],
            randNums[rand() % 5]
        );
    }
    addContact("Super", "Mario", "Here we go!");
}

int main(){
    int command;
    string tmp, name, lname, number;
    
    init();
    
    while(true){
        print();
        
        cin >> command;
        
        switch(command){
            case 1:
                getline(cin, tmp);
                requireValue("Nome", name);
                requireValue("Cognome", lname);
                requireValue("Numero di telefono", number);
                addContact(name, lname, number);
                break;
            case 2:
                int n;
                cout << "Quale contatto si vuole eliminare? ";
                cin >> n;
                if(cin.fail()) {
                    cin.clear();
                    cin.ignore(999,'\n');
                    break;
                }
                deleteContact(n-1);
                break;
            case 3:
                exit(0);
                break;
        }
    }
}
