#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
using namespace std;

Person *make_tree();

/**
 * Main
 */
int main()
{
    Person *root = make_tree();
    root->print();

    cout << endl;
    delete root;

    return 0;
}

/**
 * Dynamically construct a genealogy tree.
 * @return the root of the tree.
 */
Person *make_tree()
{
    Person *charles = new Person("Charles", "Mary");

    Person *susan   = new Person("Susan", "Bob");
    Person *george  = new Person("George");
    Person *tom     = new Person("Tom", "Alice");

    charles->procreate(susan);
    charles->procreate(george);
    charles->procreate(tom);
    //charles->print_children();

    Person *dick  = new Person("Dick", "Cindy");
    Person *harry = new Person("Harry");

    susan->procreate(dick);
    susan->procreate(harry);

    Person *ron = new Person("Ron");
    dick->procreate(ron);
    //ron->print();

    Person *eliza     = new Person("Eliza", "Bud");
    Person *charlotte = new Person("Charlotte", "Frank");
    Person *emily     = new Person("Emily", "Carl");

    tom->procreate(eliza);
    tom->procreate(emily);
    tom->procreate(charlotte);

    Person *tim = new Person("Tim");
    emily->procreate(tim);

    Person *carol = new Person("Carol");
    Person *sara  = new Person("Sara");

    charlotte->procreate(carol);
    charlotte->procreate(sara);

    return charles;
}
