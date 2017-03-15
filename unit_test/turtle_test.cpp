#include "../src/animals/turtle/turtle.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class TurtleTest : public ::testing::Test {
  protected:
    TurtleTest(){}
};

TEST(TurtleTest, GetTextMethod) {
  Turtle turtle(make_pair(1,23));
  ASSERT_EQ("TRL", turtle.GetId());
  ASSERT_EQ(make_pair(1,23), turtle.GetPos());
  ASSERT_EQ(1, turtle.GetNumber());
  ASSERT_FLOAT_EQ(453, turtle.GetWeight());
  ASSERT_EQ('H', turtle.GetType());
  ASSERT_EQ('0', turtle.GetLegend());
  set<char> h1 = {'W'};
  ASSERT_EQ(h1, turtle.GetHabitat());
  set<string> c1 = {"MRE","DGG","TRL","DLP","WHL","PNG","HPP","GSE","CRN"};
  ASSERT_EQ(c1, turtle.GetCompatible());
  ASSERT_FLOAT_EQ(0.05, turtle.GetEat());
  turtle.Move(0);
  ASSERT_EQ(make_pair(0,23), turtle.GetPos());
  turtle.Move(1);
  ASSERT_EQ(make_pair(0,22), turtle.GetPos());
  turtle.Move(2);
  ASSERT_EQ(make_pair(0,23), turtle.GetPos());
  turtle.Move(3);
  ASSERT_EQ(make_pair(1,23), turtle.GetPos());
  Turtle turtle_2(1.2, make_pair(13,7));
  ASSERT_EQ("TRL", turtle_2.GetId());
  ASSERT_EQ(make_pair(13,7), turtle_2.GetPos());
  ASSERT_EQ(2, turtle_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, turtle_2.GetWeight());
  ASSERT_EQ('H', turtle_2.GetType());
  ASSERT_EQ('0', turtle_2.GetLegend());
  set<char> h2 = {'W'};
  ASSERT_EQ(h2, turtle_2.GetHabitat());
  set<string> c2 = {"MRE","DGG","TRL","DLP","WHL","PNG","HPP","GSE","CRN"};
  ASSERT_EQ(c2, turtle_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.05, turtle_2.GetEat());
  turtle_2.Move(0);
  ASSERT_EQ(make_pair(12,7), turtle_2.GetPos());
  turtle_2.Move(1);
  ASSERT_EQ(make_pair(12,6), turtle_2.GetPos());
  turtle_2.Move(2);
  ASSERT_EQ(make_pair(12,7), turtle_2.GetPos());
  turtle_2.Move(3);
  ASSERT_EQ(make_pair(13,7), turtle_2.GetPos());
}
