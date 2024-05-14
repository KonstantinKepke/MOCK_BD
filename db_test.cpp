#include <string>
#include <iostream>
#include <vector>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

#include "./include/db.h"

class MockDB : public DataBaseConnect {
public:
    MockDB () {cout << " DEBUG MockDB\n";};
    MOCK_METHOD0 (fetchRecord, int () );
    MOCK_METHOD1 (logout, bool (string username) );
    MOCK_METHOD2 (login, bool (string username, string password) );
    MOCK_METHOD2 (login2, bool (string username, string password) );
    MOCK_METHOD0 (getBD_State, bool () );
    MOCK_METHOD1 (setBD_State, bool (bool state) );
    MOCK_METHOD0 (getRecord, string () );
};

TEST(MyDBTest, SetRecord){
    cout << " Set Record Test 0\n"; // Arrange
    MockDB mdb;  
    MyDatabase db(mdb);
    EXPECT_CALL(mdb, login("Terminator", "I m back"))
            .Times(AtLeast(1))
            .WillRepeatedly(Return(true));

    EXPECT_CALL(mdb, setBD_State(false))
           .Times(AtLeast(1))
           .WillRepeatedly(Return(false));
    
    EXPECT_CALL(mdb, setBD_State(true))
           .Times(AtLeast(1))
           .WillRepeatedly(Return(true));

    EXPECT_CALL(mdb, getBD_State())
            .  --Times(AtLeast(1))
            .WillRepeatedly(Return(false));
    EXPECT_CALL(mdb, getRecord())
            .Times(AtLeast(1))

            /// new true test
            .WillRepeatedly(Return("test"));

 
               //int retvalue = db.Init("Terminator", "I m back");
    db.Init("Terminator", "I m back");
    db.Disconnect();
    
    bool retvalue = db.writeDb("test");
    ASSERT_NE(retvalue, true);
    db.Connect();
    
    string rets = db.readDb();
   cout << " db.readDb() = " <<  rets << endl;
   string res = "test";
   ASSERT_STREQ(rets.c_str(), res.c_str());
};



// TEST(MyDBTest, LoginTest){
//     cout << " DEBUG 0\n"; // Arrange
//     MockDB mdb;  
//     MyDatabase db(mdb);
//     cout << " DEBUG 1\n";
//     EXPECT_CALL(mdb, login("Terminator", "I m back"))
//             .Times(AtLeast(1))
//             .WillRepeatedly(Return(true));

//     cout << " DEBUG 2\n";
    
//     int retvalue = db.Init("Terminator", "I m back");


//     cout << " DEBUG 3\n"; // Assertion
//     ASSERT_EQ(retvalue, 1);
// };

// TEST(MyDBTest, LoginTest){
//     cout << " DEBUG 0\n"; // Arrange
//     MockDB mdb;  
//     MyDatabase db(mdb);
//     cout << " DEBUG 1\n";
//     EXPECT_CALL(mdb, login("Terminator", _)) // "I m back"))
//     .Times(AtLeast(1))
//     .WillOnce(Return(true)); // Act
//     cout << " DEBUG 2\n";
//     int retvalue = db.Init("Terminator", "I  m back");
// cout << " DEBUG 3\n"; // Assertion
//     ASSERT_EQ(retvalue, 1);
// };

// TEST(MyDBTest, LoginTestFALSE){
//     cout << " DEBUG 0\n"; // Arrange
//     MockDB mdb;  
//     MyDatabase db(mdb);
//     cout << " DEBUG 1\n";
//     EXPECT_CALL(mdb, login("Terminator", "I m back")) // "I m back"))
//     .Times(2)
//     .WillRepeatedly(Return(false)); // Act
//     cout << " DEBUG 2\n";
//     int retvalue = db.Init("Terminator", "I m back");
// cout << " DEBUG 3\n"; // Assertion
//     ASSERT_EQ(retvalue, -1);
// };


int main(int argc, char **argv) {
   std::cout << "KEPKE Mac DB test start!)"<<std::endl;

   ::testing::InitGoogleTest(&argc, argv);

  int i = RUN_ALL_TESTS(); 
  std::cout << " ALL SUPER !) i= "<< i <<std::endl;
  return 0;
}