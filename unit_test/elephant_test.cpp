#include "../src/animals/elephant/elephant.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class ElephantTest : public ::testing::Test {
  protected:
    ElephantTest(){}
};

TEST(ElephantTest, GetTextMethod) {
  Elephant Elephant(make_pair(1,23));
  ASSERT_EQ("ELP", Elephant.GetId());
  ASSERT_EQ(make_pair(1,23), Elephant.GetPos());
  ASSERT_EQ(1, Elephant.GetNumber());
  ASSERT_FLOAT_EQ(4, Elephant.GetWeight());
  ASSERT_EQ('K', Elephant.GetType());
  ASSERT_EQ('#', Elephant.GetLegend());
  set<char> h1 = {'A'};
  ASSERT_EQ(h1, Elephant.GetHabitat());
  set<string> c1 = {"EGL", "PLC", "OW"};
  ASSERT_EQ(c1, Elephant.GetCompatible());
  ASSERT_FLOAT_EQ(0.7, Elephant.GetEat());
  Elephant.Move(0);
  ASSERT_EQ(make_pair(0,23), Elephant.GetPos());
  Elephant.Move(1);
  ASSERT_EQ(make_pair(0,22), Elephant.GetPos());
  Elephant.Move(2);
  ASSERT_EQ(make_pair(0,23), Elephant.GetPos());
  Elephant.Move(3);
  ASSERT_EQ(make_pair(1,23), Elephant.GetPos());
  Elephant Elephant_2(1.2, make_pair(13,7));
  ASSERT_EQ("EGL", Elephant_2.GetId());
  ASSERT_EQ(make_pair(13,7), Elephant_2.GetPos());
  ASSERT_EQ(2, Elephant_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, Elephant_2.GetWeight());
  ASSERT_EQ('K', Elephant_2.GetType());
  ASSERT_EQ('#', Elephant_2.GetLegend());
  set<char> h2 = {'A'};
  ASSERT_EQ(h2, Elephant_2.GetHabitat());
  set<string> c2 = {"EGL", "PLC", "OW"};
  ASSERT_EQ(c2, Elephant_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.7, Elephant_2.GetEat());
  Elephant_2.Move(0);
  ASSERT_EQ(make_pair(12,7), Elephant_2.GetPos());
  Elephant_2.Move(1);
  ASSERT_EQ(make_pair(12,6), Elephant_2.GetPos());
  Elephant_2.Move(2);
  ASSERT_EQ(make_pair(12,7), Elephant_2.GetPos());
  Elephant_2.Move(3);
  ASSERT_EQ(make_pair(13,7), Elephant_2.GetPos());
}
