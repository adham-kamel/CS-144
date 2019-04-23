#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Person
{
public:
    /**
     * Default constructor
     */
    Person()
        : name(""), spouse_name(""), parent(nullptr) {}

    /**
     * Constructor
     * @param name the name of the person
     */
    Person(string name)
        : name(name), spouse_name(""), parent(nullptr) {}

    /**
     * Constructor
     * @param name the name of the person
     * @param spouse_name the name of the person's spouse
     */
    Person(string name, string spouse_name)
        : name(name), spouse_name(spouse_name), parent(nullptr) {}

    /**
     * Destructor
     * Recursively delete all the persons.
     */
    virtual ~Person();

    /**
     * Procreate (have a child).
     * @param child pointer to the new child.
     */
    void procreate(Person *child);

    /**
     * Print a person and the children recursively.
     */
    void print() const;

private:
    string name;
    string spouse_name;
    Person *parent;
    vector<Person*> children;

    /**
     * Print the vertical bar for this person
     * and recursively for ancestors.
     */
    void print_bar() const;

};

#endif /* PERSON_H_ */
