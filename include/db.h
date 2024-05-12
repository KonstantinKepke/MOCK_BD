#include <string>
#include <iostream>
#include <vector>

class DataBaseConnect {
public:
    string Data;
    bool state = false;
    virtual bool login (string username, string password) { 
        cout << " DB login \n";
        state = true;
        return true; 
    }
    virtual bool login2 (string username, string password) { 
        cout << " DB login2  6\n";
        return true; 
    }
    virtual bool logout (string username) {
        cout << " DB logout  6\n";
        return true; 
    }
    virtual int fetchRecord () { 
        return -1; 
    }
    
    virtual bool setRecord (string str) { 
        if( getBD_State() == true ){
            Data = str;
            return true;
        }
        else { return false; }
    }
    virtual string getRecord () { 
        if(state == true ){
            return Data;
        }
        else { return "ERROR DATA!"; }
    }
    virtual bool getBD_State() {
        return state;
    }
    virtual bool setBD_State(bool st) {
        state = st;
        return true;
    }
};
 
class MyDatabase {
    DataBaseConnect & dbC;
    string Name;

public:
    MyDatabase (DataBaseConnect & _dbC) : dbC(_dbC) {
        cout << "MyDatabase (DataBaseConnect & _dbC) : dbC(_dbC)\n";
    };
    
    int Init (string username, string password) { 
        cout << "INIT MyDatabase \n";
        int rval = rand() %2;
        if(rval == 1 ){
            cout << "rval=  " << rval << endl;
            if(dbC.login(username,  password) != true)
            { 
                if(dbC.login(username,  password) != true) {
                    cout << " DB 2nd attempt Login Error\n"; return -1;
                };
                return -1;
            } else { 
                cout << " DB Login SUCCESS \n"; return 1;
                dbC.setBD_State(true);
            };
        } else {
            return dbC.login2(username,  password);
        };
    };
    
    int Disconnect () {
        dbC.setBD_State(false);
        return 1;
    }
    
    bool writeDb (string str){
        if ( dbC.setRecord(str)) {
            return true;
        }
        else {
            return false;
        }
    };
    
    string readDb (){
        return dbC.getRecord();
    };

};
