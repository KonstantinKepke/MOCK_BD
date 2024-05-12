#include <string>
#include <iostream>
#include <vector>

using namespace std;

#include "./include/db.h"

int main(int argc, char **argv) {
 
   cout << "Start DB prog!" << endl;
    string data_to_db = "I'm terminator!";
    string name = "Kostya";
    string pass = "Kostya";
    DataBaseConnect db_connect; 
    MyDatabase mDB(db_connect);
    
    mDB.Init(name, pass);
        
    mDB.writeDb(data_to_db);

    cout << "Print from DB = " << mDB.readDb() << endl;

    cout << "End DB prog!"<< endl;

  return 0;
}

  
