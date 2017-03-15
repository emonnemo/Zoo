#include "zebra.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class ZebraTest : public ::testing::Test {
  protected:
    ZebraTest(){}
};

TEST(ZebraTest, GetTextMethod) {
  Zebra zebra(make_pair(1,23));
  ASSERT_EQ("ZBR", zebra.GetId());
  ASSERT_EQ(make_pair(1,23), zebra.GetPos());
  ASSERT_EQ(1, zebra.GetNumber());
  ASSERT_FLOAT_EQ(226, zebra.GetWeight());
  ASSERT_EQ('H', zebra.GetType());
  ASSERT_EQ('3', zebra.GetLegend());
  set<char> h1 = {'L'};
  ASSERT_EQ(h1, zebra.GetHabitat());
  set<string> c1 = {"ZBR","ELP","MCQ","HG","PNG","HPP","DRL","CLG","SGL"};
  ASSERT_EQ(c1, zebra.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, zebra.GetEat());
  zebra.Move(0);
  ASSERT_EQ(make_pair(0,23), zebra.GetPos());
  zebra.Move(1);
  ASSERT_EQ(make_pair(0,22), zebra.GetPos());
  zebra.Move(2);
  ASSERT_EQ(make_pair(0,23), zebra.GetPos());
  zebra.Move(3);
  ASSERT_EQ(make_pair(1,23), zebra.GetPos());
  Zebra zebra_2(1.2, make_pair(13,7));
  ASSERT_EQ("ZBR", zebra_2.GetId());
  ASSERT_EQ(make_pair(13,7), zebra_2.GetPos());
  ASSERT_EQ(2, zebra_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, zebra_2.GetWeight());
  ASSERT_EQ('H', zebra_2.GetType());
  ASSERT_EQ('3', zebra_2.GetLegend());
  set<char> h2 = {'L'};
  ASSERT_EQ(h2, zebra_2.GetHabitat());
  set<string> c2 = {"ZBR","ELP","MCQ","HG","PNG","HPP","DRL","CLG","SGL"};
  ASSERT_EQ(c2, zebra_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, zebra_2.GetEat());
  zebra_2.Move(0);
  ASSERT_EQ(make_pair(12,7), zebra_2.GetPos());
  zebra_2.Move(1);
  ASSERT_EQ(make_pair(12,6), zebra_2.GetPos());
  zebra_2.Move(2);
  ASSERT_EQ(make_pair(12,7), zebra_2.GetPos());
  zebra_2.Move(3);
  ASSERT_EQ(make_pair(13,7), zebra_2.GetPos());
}
