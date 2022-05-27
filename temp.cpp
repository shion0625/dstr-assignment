#include <bits/stdc++.h>
#include "lecture_struct.h"

using namespace std;

int tutorIndex = 0;
void addTutor(vector<Tutor>& tutorArray){
    Tutor tutor;
    cout << "Id: ";
    cin >> tutor.TutorID;
    cout << "Name: ";
    cin >> tutor.Name;
    cout << "Date joined: ";
    cin >> tutor.DateJoined;
    cout << "Date terminated: ";
    cin >> tutor.DateTerminated;
    cout << "Pay Rate: ";
    cin >> tutor.HourlyPayRate;
    cout << "Phone: ";
    cin >> tutor.Phone;
    cout << "Address: ";
    cin >> tutor.Address;
    cout << "Center code: ";
    cin >> tutor.TuitionCenterCode;
    cout << "Center Name: ";
    cin >> tutor.TuitionCenterName;
    cout << "Subject code: ";
    cin >> tutor.SubjectCode;
    cout << "Subject name: ";
    cin >> tutor.SubjectName;
    cout << "Rating: ";
    cin >> tutor.SubjectRating;
    tutorArray.push_back(tutor);
    tutorIndex++;
    cout << tutor.Name << "\'s data was saved." << endl;
}

void displayRecords(vector<Tutor>& tutorArray){
    for (int i = 0 ; i < tutorIndex ; i++){
        cout << "Tutor id:: " << tutorArray[i].TutorID << endl;
        cout << "Tutor name:: " << tutorArray[i].Name << endl;
        cout << "Tutor date joined:: " << tutorArray[i].DateJoined << endl;
        cout << "Tutor date terminated:: " << tutorArray[i].DateTerminated << endl;
        cout << "Tutor hourly pay rate:: " << tutorArray[i].HourlyPayRate << endl;
        cout << "Tutor phone:: " << tutorArray[i].Phone << endl;
        cout << "Tutor address:: " << tutorArray[i].Address << endl;
        cout << "Tutor tuition center code:: " << tutorArray[i].TuitionCenterCode << endl;
        cout << "Tuition center name:: " << tutorArray[i].TuitionCenterName << endl;
        cout << "subject code:: " << tutorArray[i].SubjectCode << endl;
        cout << "subject name:: " << tutorArray[i].SubjectName << endl;
        cout << "subject rating:: " << tutorArray[i].SubjectRating << endl;
        cout<<"-----------------------"<<endl;
    }
}

void displaySpecifyRecord(int index, vector<Tutor>& tutorArray){
    cout << "Tutor id:: " << tutorArray[index].TutorID << endl;
    cout << "Tutor name:: " << tutorArray[index].Name << endl;
    cout << "Tutor date joined:: " << tutorArray[index].DateJoined << endl;
    cout << "Tutor date terminated:: " << tutorArray[index].DateTerminated << endl;
    cout << "Tutor hourly pay rate:: " << tutorArray[index].HourlyPayRate << endl;
    cout << "Tutor phone:: " << tutorArray[index].Phone << endl;
    cout << "Tutor address:: " << tutorArray[index].Address << endl;
    cout << "Tutor tuition center code:: " << tutorArray[index].TuitionCenterCode << endl;
    cout << "Tuition center name:: " << tutorArray[index].TuitionCenterName << endl;
    cout << "subject code:: " << tutorArray[index].SubjectCode << endl;
    cout << "subject name:: " << tutorArray[index].SubjectName << endl;
    cout << "subject rating:: " << tutorArray[index].SubjectRating << endl;
}

int binarySearchId(int l,int r,int id, vector<Tutor>& tutorArray){
    if (r >= l) {
        int middle = l + (r - l) / 2;
        if (tutorArray[middle].TutorID == id){
            return middle;
        }
        if (tutorArray[middle].TutorID > id) binarySearchId(l, middle - 1, id, tutorArray);
        binarySearchId(middle + 1, r, id, tutorArray);
    }
    return -1;
}

int searchTutorId(vector<Tutor>& tutorArray){
    int tutorID;
    cout << "Input tutor ID: ";
    cin >> tutorID;
    int flag = binarySearchId(0,tutorIndex, tutorID, tutorArray);
    return flag;
}

void binarySearchRate(int l,int r,int rate, vector<Tutor>& tutorArray){
    if (r >= l) {
        int middle = l + (r - l) / 2;
        if (tutorArray[middle].SubjectRating == rate){
            displaySpecifyRecord(middle, tutorArray);
        }
        if (tutorArray[middle].SubjectRating > rate) binarySearchRate(l, middle - 1, rate, tutorArray);
        binarySearchRate(middle + 1, r, rate, tutorArray);
    }
    return;
}

void searchTutorByRating(vector<Tutor>& tutorArray){
    int rate;
    cout << "Input tutor rate: ";
    cin >> rate;
    binarySearchRate(0,tutorIndex,rate, tutorArray);
}

void sortAccessingOrderTutorsID(vector<Tutor>& tutorArray){
    int out = 0;
    Tutor x;
    do {
        out = 0;
        for (int i = 0; i < tutorIndex-1; i++) {
            if (tutorArray[i].TutorID > tutorArray[i + 1].TutorID) {
                x = tutorArray[i];
                tutorArray[i]= tutorArray[i + 1];
                tutorArray[i + 1] = x;
                out += 1;
            }
        }
    } while (out != 0);
}

void sortAccessingOrderTutorsHourlyPayRate(vector<Tutor>& tutorArray){
    int out = 0;
    Tutor x;
    do {
        out = 0;
        for (int i = 0; i < tutorIndex-1; i++) {
            if (tutorArray[i].HourlyPayRate > tutorArray[i + 1].HourlyPayRate) {
                x = tutorArray[i];
                tutorArray[i]= tutorArray[i + 1];
                tutorArray[i + 1] = x;
                out += 1;
            }
        }
    } while (out != 0);
}
void sortAccessingOrderTutorsOverallPerformance(vector<Tutor>& tutorArray){
    int out = 0;
    Tutor x;
    do {
        out = 0;
        for (int i = 0; i < tutorIndex-1; i++) {
            if (tutorArray[i].SubjectRating > tutorArray[i + 1].SubjectRating) {
                x = tutorArray[i];
                tutorArray[i]= tutorArray[i + 1];
                tutorArray[i + 1] = x;
                out += 1;
            }
        }
    } while (out != 0);
}

void modifyRecode (vector<Tutor>& tutorArray) {
    int flag = searchTutorId(tutorArray);
    if (flag != -1) {
        int n;
        cout << "enter the element which you want to modify" << endl;
        cout << "==========\n1.Name\n2.HourlyRate\n3.PhoneNumber\n4.Address\n5.Rating\n==========" << endl;
        cin >> n;
        string element;
        Tutor currentNode = tutorArray[flag];
        switch(n){
            case 1:
                cout << "please enter name" << endl;
                cin >> element;
                currentNode.Name = element;
                break;
            case 2:
                cout << "please enter hourly rate" << endl;
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
        tutorArray[flag] = currentNode;
    } else {
        cout << "can not find " << endl;
    }
}

void deleteRecode(vector<Tutor>& tutorArray){
    cout << tutorIndex << endl;
    int flag = searchTutorId(tutorArray);
    cout << "flag :" << flag << endl;
    if (flag != -1) {
        auto elem_to_remove = tutorArray.begin() + flag;
        tutorArray.erase(elem_to_remove);
        tutorIndex--;
        for(int i = 0; i < tutorArray.size(); i++){
            cout << tutorArray[i].Name << endl;
        }
    } else {
        cout << "can not find " << endl;
    }
}

void menu() {
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
    cout << ">>  ";
}

int main(){
    vector<Tutor> tutorArray;
    int input=0;
    int middle;
    do{
        menu();
        cin >> input;
        switch(input){
            case 1:
                addTutor(tutorArray);
                break;
            case 2:
                displayRecords(tutorArray);
                break;
            case 3:
                middle = searchTutorId(tutorArray);
                displaySpecifyRecord(middle, tutorArray);
                break;
            case 4:
                searchTutorByRating(tutorArray);
                break;
            case 5:
                sortAccessingOrderTutorsID(tutorArray);
                displayRecords(tutorArray);
                break;
            case 6:
                sortAccessingOrderTutorsHourlyPayRate(tutorArray);
                displayRecords(tutorArray);
                break;
            case 7:
                sortAccessingOrderTutorsOverallPerformance(tutorArray);
                displayRecords(tutorArray);
                break;
            case 8:
                modifyRecode(tutorArray);
                break;
            case 9:
                deleteRecode(tutorArray);
                break;
            case 10:
                cout << "bye!!!" << endl;
                break;
            default:
                cout << "please enter correct number" << endl;
        }
    }while(input!=10);
    return 0;
}
