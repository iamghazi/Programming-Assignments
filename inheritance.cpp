#include <bits/stdc++.h> 

  

using namespace std; 

  

//A Base class Pet that includes the name and details of the animal 

//Including functions to set and get some information and pure virtual function to print all the info 

class Pet 

{ 

private: 

    string name; 

    bool neuterSpayed=false; 

    bool talks=false; 

public: 

    void setname(string a){ name =a ;} 

    void setneeu(bool a){neuterSpayed=a;} 

    void settalks(bool a){talks = a;} 

    string getname(){return name;} 

    bool getneu(){return neuterSpayed;} 

    bool gettalks(){return talks;} 

    virtual void printDescription()=0; 

}; 

  

//An inherited class Dog that includes info of Dog 

class Dog :public Pet 

{ 

public: 

    void printDescription(){ 

        cout << "Dog named " << getname() << endl; 

        cout << "Neuter/Spayed: " <<getneu(); 

    } 

  

}; 

  

//An inherited class Cat that includes info of Cat 

class Cat :public Pet 

{ 

public: 

    void printDescription(){ 

        cout << "Cat named " << getname() << endl; 

        cout << "Neuter/Spayed: " <<getneu(); 

    } 

  

}; 

  

//An inherited class Bird that includes info of Bird 

class Bird :public Pet 

{ 

public: 

    void printDescription(){ 

        cout << "Bird named " << getname() << endl; 

        cout << "Talks: " << gettalks() << endl; 

         } 

}; 

  

int main() 

{ 

    // A vector to store classes 

    vector <Pet*> vec; 

  

    vec.push_back(new Dog); 

    vec[0]->setname("Tommy"); 

    vec[0]->settalks(1); 

  

    vec.push_back(new Cat); 

    vec[1]->setname("Meawoo"); 

    vec[1]->settalks(0); 

  

    vec.push_back(new Bird); 

    vec[2]->setname("Chinky"); 

    vec[2]->settalks(1); 

  

    //A for loop to print all information of animals 

    for (int i=0;i<3;++i) 

   { 

        cout<<endl; 

        vec[i]->printDescription(); 

        cout<<endl; 

    } 

    return 0; 

} 

 

 

 

 

 

//Sample Output: 

  Dog named Tommy 

  Neuter/Spayed: 0 

 

  Cat named Meawoo 

  Neuter/Spayed: 0 

  

  Bird named Chinky 

  Neuter/Spayed: 0