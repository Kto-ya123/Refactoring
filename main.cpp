#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Human{
public:

    Human(string name): Name(name){}

    virtual void Walk(string destination) const {
        cout << Profession() <<": " << Name << " walks to: " << destination << endl;
    }

    string Profession() const {
        string profession = typeid(*this).name();
        return profession.substr(1);
    }

public:
    string Name;
};

class Student : public Human {
public:

    Student(string name, string favouriteSong) : Human(name) {
        FavouriteSong = favouriteSong;
    }

    void Learn() const {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(string destination) const {
        Human::Walk(destination);
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }
public:
    string FavouriteSong;
};


class Teacher : public Human {
public:

    Teacher(string name, string subject): Human(name){
        Subject = subject;
    }

    void Teach() const {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

public:
    string Subject;
};


class Policeman : public Human {
public:
    Policeman(string name): Human(name) {}
    void Check(const Human& h) const{
        cout << "Policeman: " << Name << " checks "<< h.Profession() << ". "<< h.Profession() <<"'s name is: " << h.Name << endl;
    }
};

void VisitPlaces(const Human& h, vector<string> places){
    for (auto p : places) {
        h.Walk(p);
    }
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
