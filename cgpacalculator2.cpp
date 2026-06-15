#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){

    cout<<"************GPA AND CGPA CALCULATOR***********"<<endl;

    string name;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);

    string program_name;
    cout << "Enter your program name ";
    getline(cin, program_name);

    int coursesnumber;
    cout<<"enter the number of courses you took this year"<<endl;
    cin>>coursesnumber;

    double totalcredits_sem=0;
    double totalgradepoints_sem=0;

    for(int i=0;i<coursesnumber;i++){
        double grade;
        double credits;
        string course_name;  

        cout<<"enter course_name "<<i<<endl;
        cin.ignore();                       
        getline(cin, course_name);           

        cout<<"enter grade you got (e.g : 4.0,3.0,3.5): ";
        cin>>grade;
        cout<<"enter credit hours(eg: 3,4 ,5): ";
        cin>>credits;

        totalcredits_sem=totalcredits_sem+credits;
        totalgradepoints_sem=totalgradepoints_sem+(grade*credits);
    }

    double semestergpa=totalgradepoints_sem/totalcredits_sem;

    double totalcredits=totalcredits_sem;
    double totalgradepoints=totalgradepoints_sem;

    char prior;
    cout<<"do you have any prior semesters to include in the cgpa?"<<endl;
    cin>>prior;

    if(prior=='y'||prior=='Y'){
        double priorcredits;
        double priorpoints;

        cout<<"enter prior credit hours "<<endl;
        cin>>priorcredits;

        cout<<" enter total prior points"<<endl;
        cin>>priorpoints;

        totalcredits=totalcredits+priorcredits;
        totalgradepoints=totalgradepoints+priorpoints;
    }

    double overallcgpa=totalgradepoints/totalcredits;
    cout<<endl;
    cout << fixed << setprecision(2);

    cout<<"**********************************************"<<endl;
    cout<<"***** FINAL RESULTS ARE AS LISTED BELOW******"<<endl;
    cout<<"student: "<<name<<endl;
    cout<<"program name: "<<program_name<<endl;          
    cout<<"your total semester credits are"<<" "<<totalcredits_sem<<endl;  
    cout<<"Semester gpa is" <<" "<<semestergpa<<endl;
    cout<<"overall  cgpa is "<< " "<<overallcgpa<<endl;
    cout<<"**********************************************"<<endl;

    return 0;
}