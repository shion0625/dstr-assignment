#include<iostream>
#include "lecture_struct.h"
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//trim
std::string trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n"){
    std::string result;
// Find the position where you can find anything other than the characters you want to trim from the left side.
    std::string::size_type left = string.find_first_not_of(trimCharacterList);
    if (left != std::string::npos) {
// If you find something other than the characters you want to trim from the left side, search from the right side as wellecture.
        std::string::size_type right = string.find_last_not_of(trimCharacterList);
// Determines the return value. Here, even if you search from the right side, it is not necessary to judge because there are always characters other than the characters to be trimmed.
        result = string.substr(left, right - left + 1);
    }
    return result;
}

//split func
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            item = trim(item);
            elems.push_back(item);
        }
    }
    return elems;
}
// read lecture file
vector<string> readFile(){
    vector<string> lines;
    string line;
    const char *path = "/Users/kokubunryuuji/Devspace/dstr-assignment/lecture.txt";

    ifstream ifs(path);
    if ( !ifs.is_open() ) {
        cerr << "Could not open the file - '"
             << path << "'" << endl;
        return lines;
    }

    while (getline(ifs, line)){
        lines.push_back(line);
    }

    ifs.close();
    return lines;
}
//
Lecture initStruct(string line) {
    Lecture lecture;
    const auto &res = split(line, '/');
    lecture.TutorID = stoi(res[0]);
    lecture.Name = res[1];
    lecture.DateJoined = res[2];
    lecture.DateTerminated = res[3];
    lecture.HourlyPayRate = stoi(res[4]);
    lecture.Phone = res[5];
    lecture.Address = res[6];
    lecture.TuitionCenterCode = stoi(res[7]);
    lecture.SubjectName = res[8];
    lecture.SubjectCode = stoi(res[9]);
    lecture.SubjectName = res[10];
    lecture.SubjectRating = stoi(res[11]);

    return lecture;
}

int main() {
    const auto &line = readFile();
    
    //get the number of lecture
    int number_of_lecture = line.size();
    Lecture lecture[number_of_lecture];

    int index = 0;
    for (const auto &i : line){
        lecture[index] = initStruct(i);
        index++;
    }

//    for (int i = 0; i < index; i++){
//        cout << "Name:" << lecture[i].Name  << " Payrate:" << lecture[i].HourlyPayRate << endl;
//    }
}



