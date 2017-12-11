#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>

using namespace std;

class Address{
    public:
        void Validate();
        void Validate(char*,char*,char*,int,char*);
        void Output_As_Label();
    private:
        char Street[30];
        char City[30];
        char State[30];
        int Postal_Code;
        char Country[30];
};

void Address::Output_As_Label(){
    cout<<"Street: " << Street<<endl;
    cout<<"City: " <<City<<endl;
    cout<<"State: " <<State<<endl;
    cout<<"Postal_Code: " <<Postal_Code<<endl;
    cout<<"Country: " <<Country<<endl;

}

void Address::Validate(char *Street,char *City,char * State, int Postal_code, char *Country){
    strcpy(Address::City,Street);
    strcpy(Address::City,City);
    strcpy(Address::State,State);
    Address::Postal_Code = Postal_code;
    strcpy(Address::Country,Country);
}

class Person{
    public:
        void Parchuse_Parking_pass();
        void Parchuse_Parking_pass(char*,int,char*);
    protected:
        char Name[30];
        int Phone_Number;
        char Email_Address[30];
        Address *address;

};

void Person::Parchuse_Parking_pass(char *Name,int Phone_Number,char *Email_Address){
    strcpy(Person::Name,Name);
    Person::Phone_Number = Phone_Number;
    strcpy(Person::Email_Address,Email_Address);
}

void Person::Parchuse_Parking_pass(){
    cout<<"Name: " <<Name<<endl;
    cout<<"Phone_Number: " <<Phone_Number<<endl;
    cout<<"Email_Address: " <<Email_Address<<endl;
}

class Professor : public Person {
    public:
        void Parking(char*,int,char*,int);//ingresamos datos a la herencia
        void Print_Data();//imprimimos los datos que entran a profesor
    protected:
        int Salary;
};

void Professor::Parking(char *Name,int Phone_Number,char *Email_Address,int Salary){
    Parchuse_Parking_pass(Name,Phone_Number,Email_Address);
    Professor::Salary = Salary;
}

void Professor::Print_Data(){
    Parchuse_Parking_pass();
    cout<<"Salary: " <<Salary<<endl;
}

class Student : public Person {
    public:
        void Is_Elegible_To_Enrroll();
        void Get_Seminars_Taken();
    protected:
        int Student_Number;
        double Average_Mark;
};

void Student::Is_Elegible_To_Enrroll(){}
void Student::Get_Seminars_Taken(){}

int main()
{
    Person *check1 = new Person();
    check1->Parchuse_Parking_pass("Henrry",32553598,"henrry26k@gmail.com");
    check1->Parchuse_Parking_pass();
    cout<<"-------------"<<endl;
    Professor *check2 = new Professor();
    check2->Parking("Michael",6689764,"m@Gmail.com",6559);
    check2->Print_Data();
    cout<<"-------------"<<endl;
    check1->Parchuse_Parking_pass();
    cout<<"-------------"<<endl;
    check2->Parchuse_Parking_pass();

    check1->address->Output_As_Label();

    return 0;
}
