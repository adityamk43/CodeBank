#include <bits/stdc++.h>

using namespace std;

class Person
{
    public:
    Person()
    {
        cout << "Hello Person" << endl;
    }

};

class Student : public Person
{
    public:
    Student()
    {
        cout << "Hello Student" << endl;
    }
};

main()
{
    Student s = new Person;
    return 0;
}