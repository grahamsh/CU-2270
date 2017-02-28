#include "CommunicationNetwork.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

CommunicationNetwork::CommunicationNetwork(){
this->head=NULL;
this->tail=NULL;

};

CommunicationNetwork::~CommunicationNetwork(){
    deleteNetwork();
}

void CommunicationNetwork::addCity(string cityNew, string cityPrevious){
City *temp;
temp=this->head;
bool validCity = false;
if(this->head == NULL){
    this->head=new City(cityNew,nullptr,nullptr,"");
    this->tail=this->head;
    return;
}
if(cityPrevious==""){
    this->tail->next = new City(cityNew,nullptr,this->tail,"");
    this->tail=this->tail->next;
    return;

    //temp->previous=new City(cityNew,temp,nullptr,"");
    //this->head=this->head->previous;
    //validCity = true;
    //return;
}
/*
if(cityNew == this->tail->cityName){
    this->tail->next = new City(cityNew,nullptr,temp,"");
    this->tail=this->tail->next;
    return;
}
*/

while(temp){
    if(cityPrevious ==temp->cityName){
        validCity = true;
        break;
    }
    temp=temp->next;
}
if(validCity == true){
City *newC;
City *next;
next=temp->next;
newC=new City(cityNew,next,temp,"");
temp->next=newC;
next->previous=newC;
return;
}else{
    cout<<"Not valid previous value"<<endl;
}
}

void CommunicationNetwork::deleteCity(string cityOld){
    City *temp=this->head;
    bool found = false;
    if(cityOld==temp->cityName){
        this->head=this->head->next;
        this->head->previous=NULL;
        cout<<"Deleting "<<temp->cityName<<endl;
        delete temp;
        return;
    }
    if(cityOld==tail->cityName){
        (this->tail->previous)->next=NULL;
        temp=tail;
        tail=tail->previous;
        cout<<"Deleting "<<temp->cityName<<endl;
        delete temp;
        return;
    }
    while(temp->cityName != cityOld){
    temp=temp->next;
    }
        (temp->previous)->next=temp->next;
        (temp->next)->previous=temp->previous;
        cout<<"Deleting "<<temp->cityName<<endl;
        delete temp;
return;
}

void CommunicationNetwork::deleteNetwork(){
while(this->head){
    City *temp=this->head;
    cout<<"Deleting "<<temp->cityName<<endl;
    this->head=this->head->next;
    delete temp;
}

return;
}

void CommunicationNetwork::buildNetwork(){
string cities[]={"Los Angeles","Phoenix","Denver","Dallas","St. Louis","Chicago","Atlanta","Washington, DC","New York","Boston"};
for(int i=0;i<10;i++){
    this->addCity(cities[i],"");
}
}

void CommunicationNetwork::transmitMsg(char *filename){
ifstream file;
string word;
file.open(filename);
cout<<filename<<endl;
if(!file){
    cout<<"error"<<endl;
    return;
}
if(this->head==NULL){
    cout<<"Network not built"<<endl;
    return;
}
while(!file.eof()){
    file>>word;
    City *temp;
    temp=this->head;
    while(temp){
        temp->message=word;
        cout<<temp->cityName<<" received "<<word<<endl;
        temp->message="";
        temp=temp->next;
    }
    temp=this->tail->previous;
    while(temp){
        temp->message=word;
        cout<<temp->cityName<<" received "<<word<<endl;
        temp->message="";
        temp=temp->previous;
    }
}
}

void CommunicationNetwork::printNetwork(){
cout<<"===CURRENT PATH==="<<endl;
City *temp;
temp=this->head;
if(head==NULL){
    cout<<"Empty Network"<<endl;
    return;
}
cout<<"NULL <- ";
while(temp){
    cout<<temp->cityName<<"<->";
    temp=temp->next;
}
cout<<"NULL"<<endl;
cout<<"=================="<<endl;
}



