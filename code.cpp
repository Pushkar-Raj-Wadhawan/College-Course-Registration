#include<bits/stdc++.h>
using namespace std;


class Course;
class Department;
class Professor;
class Student;


class Department {
    static int departmentID;
    
    public:
    static int departments;
    static unordered_map<int, Department*> deptById;
    string name;
    int id;
    int courses;
    int professors;
    
    Department(string dept) {
        departments++;
        id = ++departmentID;
        name = dept;
        courses = 0;
        professors = 0;
        deptById[id] = this;
        // cout << name << " branch inaugurated successfuly with id : " << id << "\n\n";
    }

    void addCourseToDept(string crsName);
    void addProfToDept(string profName);
};

int Department::departmentID = 0;
int Department::departments = 0;
unordered_map<int, Department*> Department::deptById;



class Course {
    static unordered_map<int, int> courseID;
    // static unordered_map<int, unordered_set<int>> coursesByDept; // to get all courses available under various depts
    public:
    string name;
    int id;
    int deptId; // represents to which department the course associates, via departmentId
    static map<pair<int,int>, Course*> courseById;

    Course(string crs, int depID) {
        name = crs;
        id = ++courseID[depID];
        deptId = depID;
        courseById[{deptId, id}] = this;
        // cout << "Course " << name << " added to department " << Department::deptById[depID]->name << "\n";    
    } 
};

unordered_map<int,int> Course::courseID;
map<pair<int, int>, Course*> Course::courseById;



void Department::addCourseToDept(string crsName) {
    Course* crs = new Course(crsName, id);
    courses++;
}




class Professor {
public:
    string name;
    int id;
    static unordered_map<int, int> profID;
    static map<pair<int, int>, Professor*> profByID;


    Professor(string profName, int deptID) {
        name = profName;
        id = ++profID[deptID];
        profByID[{deptID,id}] = this;
    }
};

unordered_map<int,int> Professor::profID;
map<pair<int, int>, Professor*> Professor::profByID;
    

void Department::addProfToDept(string profName) {
    Professor* prof = new Professor(profName, id);
    professors++;
}

class Student {
    
};
    
    
    
    void printData() {
    for(int i = 1; i <= Department::departments; i++) {
        Department* dept = Department::deptById[i];
        cout << i << " " << dept->name << "\n";
        for(int k = 1; k <= dept->courses; k++) {
            cout << "\t" << k << " " << Course::courseById[{i,k}]->name << "\n";
        }
        cout << endl;
    }
}


int main() {
    Department CS("CSE");
    Department AI("AI");
    Department EE("EE");

    CS.addCourseToDept("ITP");
    CS.addCourseToDept("OOP");
    CS.addCourseToDept("DBMS");

    AI.addCourseToDept("ML");
    AI.addCourseToDept("DL");
    AI.addCourseToDept("RL");
    
    EE.addCourseToDept("BEE");
    EE.addCourseToDept("VLSI");
    EE.addCourseToDept("CM");

    printData();

    CS.addProfToDept("Jonathan");
    CS.addProfToDept("Toto Wolff");
    EE.addProfToDept("Zak Brown");
    
}
