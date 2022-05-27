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

//    cout << "Pay Rate: ";
//    cin >> temp.HourlyPayRate;
//
//
//    cout << "Rating: ";
//    cin >> temp.SubjectRating;
//
//    cout << "Date joined: ";
//    cin >> temp.DateJoined;
//
//    cout << "Date terminated: ";
//    cin >> temp.DateTerminated;
//
//    cout << "Phone: ";
//    cin >> temp.Phone;
//
//    cout << "Address: ";
//    cin >> temp.Address;
//
//    cout << "Center code: ";
//    cin >> temp.TuitionCenterCode;
//    cout << "Center Name: ";
//    cin >> temp.TuitionCenterName;
//
//
//    cout << "Subject code: ";
//    cin >> temp.SubjectCode;
//    cout << "Subject name: ";
//    cin >> temp.SubjectName;

    push(temp);
}

void displayRecords(){
    viewTutor();
}
//void binarySearchId(int l,int r,int id){
//
//    if (r >= l) {
//        int mid = l + (r - l) / 2;
//        if (tutor[mid].TutorID == id){
//            cout << "Tutir name: " << tutor[mid].Name << endl;
//        }
//
//        if (tutor[mid].TutorID > id) binarySearchId(l, mid - 1, id);
//
//        binarySearchId(mid + 1, r, id);
//    }
//    return;
//}
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

//static struct node *concatante(struct node *a, struct node *b) {
//    struct node *p;
//    if (a == NULL) return b;
//    else if (b == NULL) return a;
//    for (p=a;p->next != NULL;p = p->next);
//    p->next = b;
//    return a;
//}
//
//
//struct node * quick_sort_lust (struct node *c) {
//    int pivot;
//    struct node *t;
//    struct node *l_pivot = NULL;
//    struct node *e_pivot = NULL;
//    struct node *r_pivot = NULL;
//
//    if (c==NULL || c->next == NULL) return c;
//    pivot = c->tutor.TutorID;
//
//    for (;c != NULL; c = t) {
//        t = c ->next;
//        if (c->next == l_pivot){
//            c->next = l_pivot;
//            l_pivot = c;
//        }else if (c ->tutor.TutorID == pivot) {
//            c->next = e_pivot;
//            e_pivot = c;
//        } else if (c ->tutor.TutorID > pivot) {
//            c->next = r_pivot;
//            r_pivot = c;
//        }
//    }
//
//    l_pivot = quick_sort_lust(l_pivot);
//    r_pivot = quick_sort_lust(r_pivot);
//    return concatante(l_pivot, concatante(e_pivot, r_pivot));
//}

//void *sortList(node *head) {
//    node *headUnsorted, *headSorted;
//    node *max, *prevMax, *prevComp;
//
//    headUnsorted = head;
//    headSorted = NULL;
//    while(headUnsorted != NULL) {
//        max = headUnsorted;
//        prevMax = NULL;
//        prevComp = headUnsorted;
//        while (prevComp->next != NULL) {
//            if ((prevComp->next)->tutor.TutorID > max->tutor.TutorID) {
//                max = prevComp->next;
//                prevMax = prevComp;
//            }
//            prevComp = prevComp->next;
//        }
//
//        if (prevMax == NULL) {
//            headUnsorted = max->next;
//        }
//        else {
//            prevMax->next = max->next;
//        }
//
//        if (headSorted == NULL) {
//            headSorted = max;
//            max->next = NULL;
//        }
//        else {
//            max->next = headSorted;
//            headSorted = max;
//        }
//    }
//    return headSorted;
//}


void menu() {
    cout << "==================" << endl;
    cout << "Tutor Management System" << endl;
    cout << "1. Add Tutor Record" << endl;
    cout << "2. Display All Records" << endl;
    cout << "3. Search a Tutor by Tutor ID" << endl;
    cout << "4. Search Tutors by overall performance (Rating)" << endl;
    cout << "5. Sort and display by Tutors ID in ascending order" << endl;
    cout << "6. Sort and display by Tutors Hourly Pay Rate in ascending order" << endl;
    cout << "7. Sort and display by Tutors ID in ascending order" << endl;
    cout << "8. Modify a Tutor Record" << endl;
    cout << "9. Delete a Tutor Record" << endl;
    cout << "10. Exit" << endl;
    cout << "==================" << endl;
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
//            case 4:
//                searchTutorByRating();
//                break;
            case 5:
//                quick_sort_lust(head);
                displayRecords();
                break;
//            case 6:
//                sortAccessingOrderTutorsHourlyPayRate();
//                displayRecords();
//                break;
//            case 7:
//                sortAccessingOrderTutorsOverallPerformance();
//                displayRecords();
//                break;
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