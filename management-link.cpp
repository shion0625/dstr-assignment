//
// Created by 國分竜二 on 2022/05/27.
//
#include <stdio.h>
#include <iostream>
#include <list>
#include "lecture_struct.h"
using namespace std;
int idx = 0;

struct node {
    Tutor tutor;
    node *next;
}*head,*tail,*curr,*nodePtr,*previousNode;


void push(Tutor comingTutor)
{
    curr = (node*) malloc (sizeof(node));
    curr->tutor = comingTutor;
    curr->next = NULL;

    if (head == NULL)
    {
        head = curr;
        tail = curr;
    }
    else
    {
        tail->next = curr;
        tail = curr;
    }
}

void viewTutor() {
    curr = head;

    while(curr != NULL)
    {
        cout << "Tutor id:: " << curr->tutor.TutorID << endl;
        cout << "Tutor name:: " << curr->tutor.Name << endl;
        cout << "Tutor dateJoined:: " << curr->tutor.DateJoined << endl;
        cout << "Tutor dateTerminated:: " << curr->tutor.DateTerminated<< endl;
        cout << "Tutor hourly payrate:: " << curr->tutor.HourlyPayRate << endl;
        cout << "Tutor phone:: " << curr->tutor.Phone << endl;
        cout << "Tutor Address:: " << curr->tutor.Address << endl;
        cout << "Tutor TuitionCenterCode:: " << curr->tutor.TuitionCenterCode << endl;
        cout << "Tutor TuitionCenterName:: " << curr->tutor.TuitionCenterName << endl;
        cout << "Tutor SubjectCode:: " << curr->tutor.SubjectCode << endl;
        cout << "Tutor SubjectName:: " << curr->tutor.SubjectName << endl;
        cout << "Tutor SubjectRating:: " << curr->tutor.SubjectRating << endl;

        cout << "------------------------" << endl ;
        curr = curr->next;
    }
}
void addTutor(){
    Tutor temp;

    cout << "Id: ";
    cin >> temp.TutorID;
    cout << "Name: ";
    cin >> temp.Name;

    cout << "Pay Rate: ";
    cin >> temp.HourlyPayRate;


    cout << "Rating: ";
    cin >> temp.SubjectRating;

    cout << "Date joined: ";
    cin >> temp.DateJoined;

    cout << "Date terminated: ";
    cin >> temp.DateTerminated;

    cout << "Phone: ";
    cin >> temp.Phone;

    cout << "Address: ";
    cin >> temp.Address;

    cout << "Center code: ";
    cin >> temp.TuitionCenterCode;
    cout << "Center Name: ";
    cin >> temp.TuitionCenterName;


    cout << "Subject code: ";
    cin >> temp.SubjectCode;
    cout << "Subject name: ";
    cin >> temp.SubjectName;

    push(temp);
}

void displayRecords(){
    viewTutor();
}

void searchTutorId(){
    int id;
    cout << "Input tutor id: ";

    cin >> id;

    curr = head;

    cout << "Tutor name with tutor id " << id << endl;

    while (curr != NULL)
    {
        if (curr->tutor.TutorID == id){
            cout << "Tutor name: " << curr->tutor.Name << endl;

        }
        curr = curr->next;
    }
    cout << endl;


    return;
}
//void binarySearchRate(int l,int r,int rate){
//
//    if (r >= l) {
//        int mid = l + (r - l) / 2;
//        if (tutor[mid].SubjectRating == rate){
//            cout << "Tutor name: " << tutor[mid].Name << endl;
//        }
//
//        if (tutor[mid].SubjectRating > rate) binarySearchRate(l, mid - 1, rate);
//
//        binarySearchRate(mid + 1, r, rate);
//    }
//    return;
//}
void searchTutorbyRating(){
    int rate;
    cout << "Input tutor rate: ";
    cin >> rate;
    curr = head;

    cout << "Tutor name with tutor rate " << rate << endl;
    while (curr != NULL)
    {
        if (curr->tutor.SubjectRating == rate){
            cout << "Tutor name: " << curr->tutor.Name << endl;
        }
        curr = curr->next;
    }
    cout << endl;

    cout << "Tutor name with tutor rate " << rate << endl;
//    binarySearchRate(0,idx,rate);
    return;
}

void modifyRecord () {
    Tutor currentNode;
    int tutorId;
    bool flag;
    cout << "Please input tutor Id which you want to change" << endl;
    cin >> tutorId;
    curr = head;
    while (curr != NULL) {
        if (curr->tutor.TutorID == tutorId ) {
            cout << "Find!" << endl;
            currentNode = curr->tutor;
            flag = true;
            break;
        }
        curr = curr->next;
    }
    if (flag) {
        int n;
        cout << "enter the element which you want to modify" << endl;
        cout << "==========\n1.Name\n2.HourlyRate\n3.PhoneNumber\n4.Address\n5.Rating\n6.Cancel\n==========" << endl;
        cin >> n;
        string element;
        switch(n){
            case 1:
                cout << "please enter name" << endl;
                cin >> element;
                currentNode.Name = element;
                break;
            case 2:
                cout << "please enter hourlyrate" << endl;
                cin >> element;
                currentNode.HourlyPayRate = stoi(element);
                break;
            case 3:
                cout << "please enter phoneNumber" << endl;
                cin >> element;
                currentNode.Phone = element;
                break;
            case 4:
                cout << "please enter address" << endl;
                cin >> element;
                currentNode.Address = element;
                break;
            case 5:
                cout << "please enter rating" << endl;
                cin >> element;
                currentNode.SubjectRating = stoi(element);
                break;
            case 6:
                cout << "bye" << endl;
                break;
            default:
                cout << "error" << endl;
        }
        curr->tutor = currentNode;
        displayRecords();
    } else {
        cout << "there is not exist that id tutor" << endl;
    }
}

void deleteModify() {
    Tutor currentNode;
    int tutorId;
    cout << "please enter tutor id which you want to delete" << endl;
    cin >> tutorId;
    if (!head) {
        cout << "error" << endl;
        return;
    }

    if (head->tutor.TutorID == tutorId) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        cout << "not head delete" << endl;
    } else {
        nodePtr = head;
        while (nodePtr != NULL && nodePtr->tutor.TutorID != tutorId ) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            cout << "go next" << endl;
        }
        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
            cout << "deelte!" << endl;
        }
    }
}

void sortById() {
    Tutor temp;
    for(auto i = head; i->next != nullptr; i=i->next){
        for(auto j=i->next; j!= nullptr; j=j->next) {
            if(i->tutor.TutorID > j->tutor.TutorID){
                temp = i->tutor;
                i->tutor = j->tutor;
                j->tutor =temp;
            }
        }
    }
}

void sortByPayrate() {
    Tutor temp;
    for(auto i = head; i->next != nullptr; i=i->next){
        for(auto j=i->next; j!= nullptr; j=j->next) {
            if(i->tutor.HourlyPayRate > j->tutor.HourlyPayRate){
                temp = i->tutor;
                i->tutor = j->tutor;
                j->tutor =temp;
            }
        }
    }
}

void sortByPerformance() {
    Tutor temp;
    for(auto i = head; i->next != nullptr; i=i->next){
        for(auto j=i->next; j!= nullptr; j=j->next) {
            if(i->tutor.SubjectRating > j->tutor.SubjectRating){
                temp = i->tutor;
                i->tutor = j->tutor;
                j->tutor =temp;
            }
        }
    }
}


void menu() {
    cout << "==================" << endl;
    cout << "Tutor Management System" << endl;
    cout << "1. Add Tutor Record" << endl;
    cout << "2. Display All Records" << endl;
    cout << "3. Search a Tutor by Tutor ID" << endl;
    cout << "4. Search Tutors by overall performance (Rating)" << endl;
    cout << "5. Sort and display by Tutors ID in ascending order" << endl;
    cout << "6. Sort and display by Tutors Hourly Pay Rate in ascending order" << endl;
    cout << "7. Sort and display by Tutors ID in performance order" << endl;
    cout << "8. Modify a Tutor Record" << endl;
    cout << "9. Delete a Tutor Record" << endl;
    cout << "10. Exit" << endl;
    cout << "==================" << endl;
    cout << ">> ";
}
int main() {
    int input = 0;
    do {
        menu();
        cin >> input;
        switch (input) {
            case 1:
                addTutor();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchTutorId();
                break;
            case 4:
                searchTutorbyRating();
                break;
            case 5:
                sortById();
                displayRecords();
                break;
            case 6:
                sortByPayrate();
                displayRecords();
                break;
            case 7:
                sortByPerformance();
                displayRecords();
                break;
            case 8:
                modifyRecord();
                break;
            case 9:
                deleteModify();
                break;
            case 10:
                break;
            default:
                cout << "please enter correct number" << endl;
        }
    }while (input != 10);
        return 0;
}