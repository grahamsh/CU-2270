#include <iostream>
#include "CommunicationNetwork.h"

using namespace std;


int main(int argc, char *argv[]){
int choice;
CommunicationNetwork *cn = new CommunicationNetwork;
do{
    cout<< "======Main Menu======\n";
    cout<< "1. Build Network\n";
    cout<< "2. Print Network Path\n";
    cout<< "3. Transmit Message Coast-To-Coast-To-Coast\n";
    cout<< "4. Add City\n";
    cout<< "5. Delete City\n";
    cout<< "6. Clear Network\n";
    cout<< "7. Quit\n";
    cin >> choice;

    switch (choice){
    case 1:
        //cout<<"Build Network "<<endl;
        cn= new CommunicationNetwork;
        cn->buildNetwork();
        cn->printNetwork();
    break;
    case 2:
        //cout<<"Print Network Path "<<endl;
        cn->printNetwork();
    break;
    case 3:
        //cout<<"Transmit Message Coast-To-Coast "<<endl;
        cn->transmitMsg((char*)argv[1]);
    break;
    case 4:
        {

        //cout<<"Add City "<<endl;
        //cin.clear();    // clear the error flag of cin.
        //cin.ignore(100, '\n');   // ignore the previous newline character.
        string cityNew, cityPrevious;
        cout << "Enter a city name: " << endl;
        cin>>cityNew;
        cout << "Enter a previous city name: " << endl;
        cin>>cityPrevious;
        cn->addCity(cityNew, cityPrevious);
    break;
        }
    case 5:
        {
        string cityOld;
        cout<<"Enter a city name: "<<endl;
        cin>>cityOld;
        cn->deleteCity(cityOld);
    break;
        }
    case 6:
        {
        cn->deleteNetwork();
    break;
        }
    case 7:
        cout<<"Goodbye"<<endl;
    break;
    default:
    cout << "Not a Valid Choice. \n"
    << "Choose again.\n";
    break;
    }
    }while(choice !=7);{
        return 0;
    }
}
