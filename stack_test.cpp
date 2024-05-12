#include <string>
#include <iostream>
#include <vector>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;

class Stack {
    vector<int> vstack = {};
public:
    void push(int val){
        vstack.push_back(val);
    }
    int pop(){
        if (vstack.size()>0){
            int value;
            value = vstack.back();
            vstack.pop_back();
            return value;
        } else {
            return -1;
        }
    };
    int size(){ return vstack.size(); };
};

struct stackTest : public testing::Test 
{
    Stack sl;
    void SetUp() { 
        int value[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (auto &el : value){ sl.push(el); }
    }
    
    void TearDown() { cout << " Destructor TearDown end\n"; }
};

TEST_F(stackTest, Increment_by_10){

    int lastVal = 11;
    while( lastVal >= 1 ) {
        cout << " Assert for val = " << lastVal << endl;
        EXPECT_EQ(sl.pop(), lastVal--);
        
    }
        
};

int main(int argc, char **argv) {

  std::cout << " KEPKE Unit test 1 start !)"<<std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  int i = RUN_ALL_TESTS(); 
  std::cout << " ALL SUPER !)"<<std::endl;
  return 0;
}