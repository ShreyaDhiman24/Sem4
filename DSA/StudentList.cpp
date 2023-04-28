#include <iostream>
#include <vector>
using namespace std;

// Define a struct to represent a student
struct Student
{
    int rollNo;
    string name;
    float cgpi;
    int semester;
};

// Function to display all records of students with CGPI greater than k
void displayRecords(vector<Student> &students, float k)
{
    cout << "Records of students with CGPI greater than " << k << ":\n";
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].cgpi > k)
        {
            cout << "Roll No.: " << students[i].rollNo << "\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "CGPI: " << students[i].cgpi << "\n";
            cout << "Semester: " << students[i].semester << "\n\n";
        }
    }
}

// Function to insert a new record of a student at the kth position
void insertRecord(vector<Student> &students, int k)
{
    Student newStudent;
    cout << "Enter the roll no., name, CGPI, and semester of the new student:\n";
    cin >> newStudent.rollNo >> newStudent.name >> newStudent.cgpi >> newStudent.semester;
    students.insert(students.begin() + k - 1, newStudent);
    cout << "New record added at position " << k << ":\n";
    cout << "Roll No.: " << students[k - 1].rollNo << "\n";
    cout << "Name: " << students[k - 1].name << "\n";
    cout << "CGPI: " << students[k - 1].cgpi << "\n";
    cout << "Semester: " << students[k - 1].semester << "\n\n";
}

int main()
{
    vector<Student> students;
    for (int i = 0; i < 5; i++)
    {
        Student s;
        cout << "Enter the roll no., name, CGPI, and semester of student " << i + 1 << ":\n";
        cin >> s.rollNo >> s.name >> s.cgpi >> s.semester;
        students.push_back(s);
    }

    float k;
    cout << "Enter the value of k:\n";
    cin >> k;
    displayRecords(students, k);

    int pos;
    cout << "Enter the position at which you want to insert the new record:\n";
    cin >> pos;
    insertRecord(students, pos);

    return 0;
}
