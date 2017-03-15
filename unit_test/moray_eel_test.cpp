#include "moray_eel.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class MorayEelTest : public ::testing::Test {
  protected:
    MorayEelTest(){}
};

TEST(MorayEelTest, GetTextMethod) {
  MorayEel morayEel(make_pair(1,23));
  ASSERT_EQ("MRE", morayEel.GetId());
  ASSERT_EQ(make_pair(1,23), morayEel.GetPos());
  ASSERT_EQ(1, morayEel.GetNumber());
  ASSERT_FLOAT_EQ(13, morayEel.GetWeight());
  ASSERT_EQ('K', morayEel.GetType());
  ASSERT_EQ('8', morayEel.GetLegend());
  set<char> h1 = {'W'};
  ASSERT_EQ(h1, morayEel.GetHabitat());
  set<string> c1 = {"MRE","DGG","TRL","DLP","WHL","HPP"};
  ASSERT_EQ(c1, morayEel.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, morayEel.GetEat());
  morayEel.Move(0);
  ASSERT_EQ(make_pair(0,23), morayEel.GetPos());
  morayEel.Move(1);
  ASSERT_EQ(make_pair(0,22), morayEel.GetPos());
  morayEel.Move(2);
  ASSERT_EQ(make_pair(0,23), morayEel.GetPos());
  morayEel.Move(3);
  ASSERT_EQ(make_pair(1,23), morayEel.GetPos());
  MorayEel morayEel_2(1.2, make_pair(13,7));
  ASSERT_EQ("MRE", morayEel_2.GetId());
  ASSERT_EQ(make_pair(13,7), morayEel_2.GetPos());
  ASSERT_EQ(2, morayEel_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, morayEel_2.GetWeight());
  ASSERT_EQ('K', morayEel_2.GetType());
  ASSERT_EQ('8', morayEel_2.GetLegend());
  set<char> h2 = {'W'};
  ASSERT_EQ(h2, morayEel_2.GetHabitat());
  set<string> c2 = {"MRE","DGG","TRL","DLP","WHL","HPP"};
  ASSERT_EQ(c2, morayEel_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, morayEel_2.GetEat());
  morayEel_2.Move(0);
  ASSERT_EQ(make_pair(12,7), morayEel_2.GetPos());
  morayEel_2.Move(1);
  ASSERT_EQ(make_pair(12,6), morayEel_2.GetPos());
  morayEel_2.Move(2);
  ASSERT_EQ(make_pair(12,7), morayEel_2.GetPos());
  morayEel_2.Move(3);
  ASSERT_EQ(make_pair(13,7), morayEel_2.GetPos());
}
