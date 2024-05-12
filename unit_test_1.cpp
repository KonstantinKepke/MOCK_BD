#include <string>
#include <iostream>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace std;
class MyClass {
    int BaseValue;
public:
    MyClass (int _bv): BaseValue(_bv){}
    void Increment(int ByValue){  BaseValue += ByValue; }
    int GetValue () { return BaseValue; }
};

struct MyClassTest : public testing::Test {
    MyClass *mc;
    void SetUp() { 
        cout << " SetUp start\n";
        mc = new MyClass(100); }
    void TearDown() { 
        delete mc; 
        cout << " Destructor TearDown end\n";
    }
};

TEST_F(MyClassTest, Increment_by_10){
//Act
    mc->Increment(10);
//Assert
    ASSERT_EQ(mc->GetValue(), 110);
};

TEST_F(MyClassTest, Increment_by_5){
//Act
    mc->Increment(5);
//Assert
    ASSERT_EQ(mc->GetValue(), 105);
};

int main(int argc, char **argv) {

  std::cout << " KEPKE Unit test 1 start !)"<<std::endl;
  ::testing::InitGoogleTest(&argc, argv);
  int i = RUN_ALL_TESTS(); 
  std::cout << " ALL SUPER !)"<<std::endl;
  return 0;
}