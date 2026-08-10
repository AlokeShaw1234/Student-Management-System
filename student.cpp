#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Student{             //    class Student
public :
    int roll;
    string name;
    int age;
    float marks;
    char grade;

    Student(int r,string n,int a,float m){
        roll = r;
        name = n;
        age = a;
        marks = m;

        if(marks >= 90) grade = 'A';
        else if(marks >= 75) grade = 'B';
        else if(marks >= 60) grade = 'C';
        else if(marks >= 40) grade = 'D';
        else grade = 'E';
    }
};

vector<Student> student;         

void addStudent(){                 //   adding student
    int roll;
    int age;
    float marks;
    string name;

    cout<<"Enter the roll number : ";
    cin>>roll;

    for(auto &s : student){
        if(s.roll == roll){
            cout << "Roll number already exists.\n";
            return;
        }
    }
    
    cin.ignore();

    cout<<endl;

    cout<<"Enter the name of the student : ";
    getline(cin,name);

    cout<<endl;

    cout<<"Enter the age of the student : ";
    cin>>age;
    
    cout<<endl;

    cout<<"Enter the marks obtained : ";
    cin>>marks;

    cout<<endl;

    student.push_back(Student(roll,name,age,marks));

    cout<<"Student details have been added";

    cout<<endl;
}

void displayStudent(){                  //  printing all the students with their details
    if(student.size() == 0){
        cout<<"No students found";
        cout<<endl;
        return;
    }

    cout<<"The student details are : ";

    int n = student.size();

    for(int i=0;i<n;i++){
        cout<<"Roll No : "<<student[i].roll;
        cout<<endl;

        cout<<"Name : "<<student[i].name;
        cout<<endl;

        cout<<"Age : "<<student[i].age;
        cout<<endl;

        cout<<"Marks : "<<student[i].marks;
        cout<<endl;

        cout<<"Grade : "<<student[i].grade;
        cout<<endl;
    }
}

void searchStudent(){                     //   searching for student using roll no
    int roll;
    cout<<"Enter the roll no of the student : ";
    cin>>roll;

    int n = student.size();

    cout<<endl;

    for(int i=0;i<n;i++){
        if(student[i].roll == roll){
            cout<<"Student found";

            cout<<"Roll No : "<<student[i].roll;
            cout<<endl;
            cout<<"Name : "<<student[i].name;
            cout<<endl;
            cout<<"Age : "<<student[i].age;
            cout<<endl;
            cout<<"Marks : "<<student[i].marks;
            cout<<endl;
            cout<<"Grade : "<<student[i].grade;
            cout<<endl;

            return;
        }
    }
    cout<<"No student found";
    cout<<endl;
}

void updateStudent(){                           //    updating student deatils 
    int roll; 
    cout<<"Enter the roll no of the student : ";
    cin>>roll;

    cout<<endl;

    int n = student.size();

    for(int i=0;i<n;i++){
        if(student[i].roll == roll){
            cin.ignore();

            cout<<"Enter new name of the student : ";
            getline(cin,student[i].name);

            cout<<"Enter the new age of the student : ";
            cin>>student[i].age;

            cout<<"Enter the new marks obtained : ";
            cin>>student[i].marks;

            if(student[i].marks >= 90){                 //   updating the grade of the student
                student[i].grade = 'A';
            }              
            else if(student[i].marks >= 75){
                student[i].grade = 'B';
            }
            else if(student[i].marks >= 60){
                student[i].grade = 'C';
            }
            else if(student[i].marks >= 40){
                student[i].grade = 'D';
            }
            else{
                student[i].grade = 'E';
            }

            cout<<"Student details have been updated";

            cout<<endl;

            return;
        }
    }
    cout<<"Student not found";
    cout<<endl;
}

void deleteStudent(){                           //    deleting student details
    int roll;
    cout<<"Enter the roll no of the student : ";
    cin>>roll;

    cout<<endl;

    int n = student.size();

    for(int i=0;i<n;i++){
        if(student[i].roll == roll){
            student.erase(student.begin()+i);

            cout<<"Student deleted successfully";
            return;
        }
    }
    cout<<"Student not found";

    cout<<endl;
}

int main()
{
    int choice;

    while(true){
        cout<<"----------------Student Management System------------------";

        cout<<"1. Add Student";
        cout<<endl;

        cout<<"2. Display Student";
        cout<<endl;

        cout<<"3. Search Student";
        cout<<endl;

        cout<<"4. Update Student";
        cout<<endl;

        cout<<"5. Delete Student";
        cout<<endl;

        cout<<"6. Exit";
        cout<<endl;

        cout<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){

            case 1:
                addStudent();
                break;

            case 2:
                displayStudent();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout<<"Thank you";
                return 0;

            default:
                cout<<"Please enter a valid choice (between 1 to 6) : ";
        }
    }
    
    return 0;
}