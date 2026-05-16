#include <iostream>
#include "string"
using namespace std;


class Subject{
    protected:
        string subjectname;
        int credithours;
        string teachername;

    public:
        Subject(string subjectname,int credithours,string teachername)
        :subjectname(subjectname),credithours(credithours),teachername(teachername){

        }

        void displaysubjectdetails(){
            cout<<"----Displaying Subject Details----"<<endl;
            cout<<"Subject Name: "<<subjectname<<endl;
            cout<<"Credit Hours: "<<credithours<<endl;
            cout<<"Teacher Name: "<<teachername<<endl;

        }

};


class studysession{
    private:
        int duration;
        string topic;
        string date; //format: DD/MM/YY
    public:

        studysession(){
            //default const
        }

        studysession(int duration,string topic,string date)
        :duration(duration),topic(topic),date(date){}

        void displaysession(){
            cout<<"----Session Details----"<<endl;
            cout<<"Duration: "<<duration<<endl;
            cout<<"Topic: "<<topic<<endl;
            cout<<"Date: "<<date<<endl;
        }

        int getduration(){
            return duration;
        }
};

class Student{
    private:
        int studentid;
        static int studentcount;
        string name;
        int totalstudyhours;
        Subject thissubject;

        studysession thesesessions[10];
        int sessioncount=0;

    public:
        Student(string name,int totalstudyhours,string sn,int ch,string tn)
        : thissubject(sn,ch,tn),name(name),totalstudyhours(totalstudyhours){
            studentcount=studentcount+1;
            studentid=studentcount;
        }

        void settotalstudyhours(int hours){
            totalstudyhours=hours;
        }

        int getstudyhours(){
            return totalstudyhours;
        }

        int getid(){
            return studentid;
        }

        void addstudyhours(int hours){
            totalstudyhours=totalstudyhours+hours;
        }

        void displaystudentdetails(){
            cout<<"-----Displaying Student Details-----"<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Student ID: "<<studentid<<endl;
            cout<<"Total Study Hours: "<<totalstudyhours<<endl;
        }

        static int getttotalstudents(){
            return studentcount;
        }

        void addstudysession(studysession s){
            if(sessioncount<10){
                thesesessions[sessioncount]=s;
                sessioncount=sessioncount+1;
                cout<<"Study Session Added."<<endl;

            }
            else{
                cout<<"No More Session Can Be Added."<<endl;
            }
        }

        void viewallstudysession(){
            for(int i=0;i<sessioncount;i++){
                cout<<"Session "<<i+1<<" :"<<endl;
                thesesessions[i].displaysession();
                cout<<"----------------------"<<endl;
            }
        }
};

int Student::studentcount=0;


int main(){
    //creating student object
    Student s1("Ayesha Nehal",2,"OOP",3,"Mr. TS");
    Student s2("Ayes",2,"OOP Theory",3,"Mr. TS");
    Student s3("Ms. Ayesha Nehal",23,"OOP Lab",3,"Mr. TS");

    int choice;

    do{//this do while loop will work till 5 is entered as it will exit this loop on 5
        cout<<"-------Study Tracker Application Menu--------"<<endl;
        cout<<"Enter 1 to Add a Study Session"<<endl;
        cout<<"Enter 2 to View Student Details"<<endl;
        cout<<"Enter 3 to View All Study Sessions"<<endl;
        cout<<"Enter 4 to View All Students Data Available in the system"<<endl;
        cout<<"Enter 5 to Exit The System"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){

            case 1:{
                cout<<"------------Adding Study Session--------------"<<endl;
                int duration;
                string topic;
                string date;

                cout<<"Enter duration of the session: ";
                cin>>duration;

                cin.ignore(); // clear buffer
                //You need cin.ignore() when:
                // using cin >> followed by getline()
                // mixing numeric + string input
                // used to clear up any garbage values of input

                cout<<"Enter topic: ";
                getline(cin,topic);

                cout<<"Enter date (DD/MM/YY): ";
                getline(cin,date);

                studysession s(duration,topic,date);
                s1.addstudysession(s);
                s2.addstudysession(s);
                s3.addstudysession(s);


                break;
            }

            case 2:{
                cout<<"------------Displaying Student Details------------"<<endl;
                s1.displaystudentdetails();
                s2.displaystudentdetails();
                s3.displaystudentdetails();
                break;
            }

            case 3:{
                cout<<"------------Viewing All Study Session Details--------------"<<endl;
                s1.viewallstudysession();
                s2.viewallstudysession();
                s3.viewallstudysession();
                
                break;
            }

            case 4:{
                cout<<"---------Displaying Total Number Of Students In The System---------"<<endl;
                cout<<"Total Students: "<<Student::getttotalstudents()<<endl;
                break;
            }

            case 5:{
                cout<<"------Exiting The System-------"<<endl;
                break;
            }

            default:{
                cout<<"Invalid choice! Try again."<<endl;
            }
        }

    }while(choice != 5);

    return 0;
}