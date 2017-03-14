//File driver_nama.cpp
//unit test untuk kelas Wolf dan sekaligus kelas Animal sebagai parent kelas Wolf

#include "../realAnimals/nama.h"
#include <iostream>
#include <gtest/gtest.h>
using namespace std;

int main(int argc, 
         char * argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}