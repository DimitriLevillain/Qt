#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<string> vect;
    vect.push_back( "C" );
    vect.push_back( "C++" );
    vect.push_back( "Java" );

    list<string> lst;
    // boucle sur un vecteur de la STL
    for(const string & str : vect)
    {
        lst.push_front( str );
    }

    for (const string & str : lst)
    {
        cout << str << " - ";
    }
    cout << endl;

    return a.exec();
}
