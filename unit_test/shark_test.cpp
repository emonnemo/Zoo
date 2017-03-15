#include "shark.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class SharkTest : public ::testing::Test {
  protected:
    SharkTest(){}
};

TEST(SharkTest, GetTextMethod) {
  Shark shark(make_pair(1,23));
  ASSERT_EQ("SHK", shark.GetId());
  ASSERT_EQ(make_pair(1,23), shark.GetPos());
  ASSERT_EQ(1, shark.GetNumber());
  ASSERT_FLOAT_EQ(771, shark.GetWeight());
  ASSERT_EQ('K', shark.GetType());
  ASSERT_EQ('7', shark.GetLegend());
  set<char> h1 = {'W'};
  ASSERT_EQ(h1, shark.GetHabitat());
  set<string> c1 = {"SHK", "WHL"};
  ASSERT_EQ(c1, shark.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, shark.GetEat());
  shark.Move(0);
  ASSERT_EQ(make_pair(0,23), shark.GetPos());
  shark.Move(1);
  ASSERT_EQ(make_pair(0,22), shark.GetPos());
  shark.Move(2);
  ASSERT_EQ(make_pair(0,23), shark.GetPos());
  shark.Move(3);
  ASSERT_EQ(make_pair(1,23), shark.GetPos());
  Shark shark_2(1.2, make_pair(13,7));
  ASSERT_EQ("SHK", shark_2.GetId());
  ASSERT_EQ(make_pair(13,7), shark_2.GetPos());
  ASSERT_EQ(2, shark_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, shark_2.GetWeight());
  ASSERT_EQ('K', shark_2.GetType());
  ASSERT_EQ('7', shark_2.GetLegend());
  set<char> h2 = {'W'};
  ASSERT_EQ(h2, shark_2.GetHabitat());
  set<string> c2 = {"SHK","WHL"};
  ASSERT_EQ(c2, shark_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, shark_2.GetEat());
  shark_2.Move(0);
  ASSERT_EQ(make_pair(12,7), shark_2.GetPos());
  shark_2.Move(1);
  ASSERT_EQ(make_pair(12,6), shark_2.GetPos());
  shark_2.Move(2);
  ASSERT_EQ(make_pair(12,7), shark_2.GetPos());
  shark_2.Move(3);
  ASSERT_EQ(make_pair(13,7), shark_2.GetPos());
}
