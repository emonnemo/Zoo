#include "../src/animals/wolf/wolf.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class WolfTest : public ::testing::Test {
  protected:
    WolfTest(){}
};

TEST(WolfTest, GetTextMethod) {
  Wolf wolf(make_pair(1,23));
  ASSERT_EQ("WF", wolf.GetId());
  ASSERT_EQ(make_pair(1,23), wolf.GetPos());
  ASSERT_EQ(1, wolf.GetNumber());
  ASSERT_FLOAT_EQ(45, wolf.GetWeight());
  ASSERT_EQ('K', wolf.GetType());
  ASSERT_EQ('1', wolf.GetLegend());
  set<char> h1 = {'L'};
  ASSERT_EQ(h1, wolf.GetHabitat());
  set<string> c1 = {"LI","ELP","HPP"};
  ASSERT_EQ(c1, wolf.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, wolf.GetEat());
  wolf.Move(0);
  ASSERT_EQ(make_pair(0,23), wolf.GetPos());
  wolf.Move(1);
  ASSERT_EQ(make_pair(0,22), wolf.GetPos());
  wolf.Move(2);
  ASSERT_EQ(make_pair(0,23), wolf.GetPos());
  wolf.Move(3);
  ASSERT_EQ(make_pair(1,23), wolf.GetPos());
  Wolf wolf_2(1.2, make_pair(13,7));
  ASSERT_EQ("WF", wolf_2.GetId());
  ASSERT_EQ(make_pair(13,7), wolf_2.GetPos());
  ASSERT_EQ(2, wolf_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, wolf_2.GetWeight());
  ASSERT_EQ('K', wolf_2.GetType());
  ASSERT_EQ('1', wolf_2.GetLegend());
  set<char> h2 = {'L'};
  ASSERT_EQ(h2, wolf_2.GetHabitat());
  set<string> c2 = {"LI","ELP","HPP"};
  ASSERT_EQ(c2, wolf_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, wolf_2.GetEat());
  wolf_2.Move(0);
  ASSERT_EQ(make_pair(12,7), wolf_2.GetPos());
  wolf_2.Move(1);
  ASSERT_EQ(make_pair(12,6), wolf_2.GetPos());
  wolf_2.Move(2);
  ASSERT_EQ(make_pair(12,7), wolf_2.GetPos());
  wolf_2.Move(3);
  ASSERT_EQ(make_pair(13,7), wolf_2.GetPos());
}
