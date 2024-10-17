#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student{ 
//ACCESS MODIFIERS: Private(by default), Public (accessible everywhere), Protected(accessible inside class 
// and to its derived class- used in inheritance)

    int rollnumber;
    string name;
    //by default all properties and methods are private(cannot be accessed outside class)
    //to declare them explicitly we do

    public: //now all things below it are publically accessible
    string college;
    float cgpa;

    void getpercentage(){
        cout<<"The percentage is: "<<cgpa*10<<endl;
    }

//GETTERS AND SETTERS- normal funcs that will store and return the values of our attributes/properties
//we use them when our attributes are private, since then direct access for storing and access is not allowed

    void setName(string nameval){
        name=nameval;
    }

    void setRollnumber(int roll){
        rollnumber=roll;
    }

    string getName(){
        return name;
    }

    int getRollnumber(){
        return rollnumber;
    }
};

int main(){
    Student s1; //memory allocated to the object the moment it is made
    cout<<sizeof(s1); 
    cout<<endl;
    //all below info modifyable and accessible since we declared them public
    // s1.name="Suhani";  cout<<s1.name;-allowed when it is public
    s1.setName("Suhani");
    cout<<s1.getName();
    s1.cgpa=9;
    s1.getpercentage();
    cout<<endl;
   


    return 0;
}