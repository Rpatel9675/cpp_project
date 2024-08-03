#include"bits/stdc++.h"
#include<conio.h>
using namespace std;

void generateOtp(){
    char otp[5],c;
    int i;
    srand((unsigned)time(NULL));
    for(i=0;i<4;)  {
        c=rand()%127;
        if(isalnum(c)){
           otp[i]=c;
           i++;
        }
    }
    otp[i]='\0';
    printf("%s", otp);

}

bool stafflogin();
int input(){
    cout<<"Enter 1 for Staff login: "<<endl;
    cout<<"Enter 2 for student login: "<<endl;
    int key;
    cin>>key;
    return key;
    //if(key==1) stafflogin();

}
bool stafflogin(){
    bool flag=false;
    string s,pass;
    cout<<"Enter User Id: "<<endl;
    cin>>s;
    if(s=="pprl735757@gmail.com"){
        cout<<"Enter password"<<endl;
        cin>>pass;
        if(pass=="Rocky@7061"){
            flag=true;
        }
        else{
            cout<<"Wrong Password !"<<endl; 
        }
    }
    else{
        cout<<"Invalid User Id: Try again !!"<<endl;
        //input();
    }
    return flag;
}
class Node{
    public:
        int roll_no;
        string student_name;
        float student_marks;
        string student_gender;

        Node *next_add;


};
class student_Details{
    public:
       Node *head =NULL;
       void Insert(int roll){
            string name;
            float marks;
            string gender;
            //char MAX_NAME_LEN;
            cout<<"Enter Student's Name  "<<endl;
            cin>>name;
            cout<<"Enter Student's Marks.  "<<endl;
            cin>>marks;
            cout<<"Enter Student's Gender  "<<endl;
            cin>>gender;
            Node *new_node=new Node;
            new_node->roll_no=roll;
            new_node->student_name=name;
            new_node->student_marks=marks;
            new_node->student_gender=gender;
            new_node->next_add=NULL;
            if(head==NULL) head=new_node;
            else {
                Node *ptr=head;
                while(ptr->next_add!=NULL){
                    ptr=ptr->next_add;
                }
                ptr->next_add=new_node;
            }
        
            cout<<endl<<"New Node Inserted successfully...."<<endl;
       }
        void search(){
            bool found=false;
            if(head==NULL) found=false;
            else {
                int n;
                //bool found= false;
                cout<<"Enter Roll no:  ";
                cin>>n;
                Node *ptr=head;
                while(ptr!=NULL){
                    if(n==ptr->roll_no){
                        cout<<"Roll no:  "<<ptr->roll_no<<endl;
                        cout<<"Name: "<<ptr->student_name<<endl;;
                        cout<<"Marks: "<<ptr->student_marks<<endl;
                        cout<<"Gender: "<<ptr->student_gender<<endl;
                        found=true;
                    }
                    ptr=ptr->next_add;
                }
                if(found==false) cout<<"! Data note Found.."<<endl;

            }

        }
        bool check(int roll){
            bool found=false;
            if(head==NULL) found=false;
            else {
                int n=roll;
                //bool found= false;
                Node *ptr=head;
                while(ptr!=NULL){
                    if(n==ptr->roll_no){
                        found=true;
                    }
                    ptr=ptr->next_add;
                }

            }
            return found;

        }
        void count(){
                int c=0;
                Node *ptr=head;
                while (ptr!=NULL)
                {
                    c++;
                    ptr=ptr->next_add;
                }
                if(c>0) cout<<"total No. of Student's are : "<<c<<endl;
                
            
        }
        void update(){
            if(head==NULL) cout<<"Empty List"<<endl;
            else {
                int n;
                bool found= false;
                cout<<"Enter Roll no:  ";
                cin>>n;
                Node *ptr=head;
                while(ptr!=NULL){
                    if(n==ptr->roll_no){
                        cout<<"Enter Student's Roll no.  "<<endl;
                        cin>>ptr->roll_no;
                        cout<<"Enter Student's Name  "<<endl;
                        cin>>ptr->student_name;
                        cout<<"Enter Student's Updated Marks.  "<<endl;
                        cin>>ptr->student_marks;
                        cout<<"Enter Student's Gender  "<<endl;
                        cin>>ptr->student_gender;
                        cout<<"Record updated successfully...."<<endl;
                        found=true;
                    }
                    ptr=ptr->next_add;
                }
                if(found==false) cout<<"!! Data note Found.."<<endl;

            }

        }
        void del(){
            if(head==NULL) cout<<"Empty List"<<endl;
            else {
                int n;
                cout<<"Enter Roll no. for Deletion: "<<endl;
                cin>>n;
                bool found= false;
                if(n==head->roll_no){
                    Node *ptr=head;
                    head=head->next_add;
                    cout<<"Record Deleted Successfully..."<<endl;
                    delete ptr;
                    found=true;
                
                }
                else{
                    Node *pre=head;
                    Node *ptr=head->next_add;
                    while(ptr!=NULL){
                        if(n==ptr->roll_no) {
                            pre->next_add=ptr->next_add;
                            found=true;
                            cout<<"Record Deleted Successfully..."<<endl;
                            delete ptr;
                            break;

                        }
                        pre=ptr;
                        ptr=pre->next_add;
                    }
                }
                if(found==false) cout<<"!! Roll no. note Found.."<<endl;

            }

        }
        void show(){
            if(head==NULL) cout<<"Empty List"<<endl;
            else {
                Node *ptr=head;
                while(ptr!=NULL){
                    cout<<"Name: "<<ptr->student_name<<endl;
                    cout<<"Roll no:  "<<ptr->roll_no<<endl;
                    cout<<"Marks: "<<ptr->student_marks<<endl;
                    cout<<"Gender: "<<ptr->student_gender<<endl;
                    cout<<endl;
                    ptr=ptr->next_add;
                }
                

            }

        }

       


};

int main(){
    generateOtp();
    int dis=178;
    char x=dis;
    cout<<endl<<endl<<endl;
    for(int i=0;i<15;i++) cout<<x;
    cout<<"  WELL COME  ";
    for(int i=0;i<15;i++) cout<<x;
    cout<<endl<<endl;;
    int inpu=input();
    if(inpu==1){
        if(stafflogin()){
            int roll;
            student_Details students;
            p:
            system("cls");
            int your_choice;
            cout<<"press 1 for save student's details "<<endl;
            cout<<"press 2 for search student's details "<<endl;
            cout<<"press 3 to student's show details "<<endl;
            cout<<"press 4 for update student's details "<<endl;
            cout<<"press 5 for delete student's details "<<endl;
            cout<<"press 6 for Exit "<<endl;
            cin>>your_choice;
            switch (your_choice)
            {
            case 1:
                system("cls");
                cout<<"Enter Student's Roll no.  "<<endl;
                cin>>roll;
                if(students.check(roll)) cout<<"Already exits"<<endl;
                else students.Insert(roll);
                break;
            case 2:
                system("cls");
                students.search();
                break;
            case 3:
                system("cls");
                students.count();
                students.show();
                break;
            case 4:
                system("cls");
                students.update();
                break;
            case 5:
                system("cls");
                students.del();
                break;
            case 6:
                exit(0);
            
            default:
                cout<<"! Invalid choice... Try again.";
            }
            getch();
            goto p;
        }
    }


}