#include "lion.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class LionTest : public ::testing::Test {
  protected:
    LionTest(){}
};

TEST(LionTest, GetTextMethod) {
  Lion lion(make_pair(1,23));
  ASSERT_EQ("LI", lion.GetId());
  ASSERT_EQ(make_pair(1,23), lion.GetPos());
  ASSERT_EQ(1, lion.GetNumber());
  ASSERT_FLOAT_EQ(158, lion.GetWeight());
  ASSERT_EQ('K', lion.GetType());
  ASSERT_EQ('2', lion.GetLegend());
  set<char> h1 = {'L'};
  ASSERT_EQ(h1, lion.GetHabitat());
  set<string> c1 = {"LI"};
  ASSERT_EQ(c1, lion.GetCompatible());
  ASSERT_FLOAT_EQ(0.5, lion.GetEat());
  lion.Move(0);
  ASSERT_EQ(make_pair(0,23), lion.GetPos());
  lion.Move(1);
  ASSERT_EQ(make_pair(0,22), lion.GetPos());
  lion.Move(2);
  ASSERT_EQ(make_pair(0,23), lion.GetPos());
  lion.Move(3);
  ASSERT_EQ(make_pair(1,23), lion.GetPos());
  Lion lion_2(1.2, make_pair(13,7));
  ASSERT_EQ("LI", lion_2.GetId());
  ASSERT_EQ(make_pair(13,7), lion_2.GetPos());
  ASSERT_EQ(2, lion_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, lion_2.GetWeight());
  ASSERT_EQ('K', lion_2.GetType());
  ASSERT_EQ('2', lion_2.GetLegend());
  set<char> h2 = {'L'};
  ASSERT_EQ(h2, lion_2.GetHabitat());
  set<string> c2 = {"LI"};
  ASSERT_EQ(c2, lion_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.5, lion_2.GetEat());
  lion_2.Move(0);
  ASSERT_EQ(make_pair(12,7), lion_2.GetPos());
  lion_2.Move(1);
  ASSERT_EQ(make_pair(12,6), lion_2.GetPos());
  lion_2.Move(2);
  ASSERT_EQ(make_pair(12,7), lion_2.GetPos());
  lion_2.Move(3);
  ASSERT_EQ(make_pair(13,7), lion_2.GetPos());
}
