#include "dolphin.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class DolphinTest : public ::testing::Test {
  protected:
    DolphinTest(){}
};

TEST(DolphinTest, GetTextMethod) {
  Dolphin dolphin(make_pair(1,23));
  ASSERT_EQ("DLP", dolphin.GetId());
  ASSERT_EQ(make_pair(1,23), dolphin.GetPos());
  ASSERT_EQ(1, dolphin.GetNumber());
  ASSERT_FLOAT_EQ(226, dolphin.GetWeight());
  ASSERT_EQ('K', dolphin.GetType());
  ASSERT_EQ('!', dolphin.GetLegend());
  set<char> h1 = {'W'};
  ASSERT_EQ(h1, dolphin.GetHabitat());
  set<string> c1 = {"PLC", "GSE", "CRN", "DGG", "DLP", "HPP", "MRE", "PLC", "PNG", "TRL", "WHL"};
  ASSERT_EQ(c1, dolphin.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, dolphin.GetEat());
  dolphin.Move(0);
  ASSERT_EQ(make_pair(0,23), dolphin.GetPos());
  dolphin.Move(1);
  ASSERT_EQ(make_pair(0,22), dolphin.GetPos());
  dolphin.Move(2);
  ASSERT_EQ(make_pair(0,23), dolphin.GetPos());
  dolphin.Move(3);
  ASSERT_EQ(make_pair(1,23), dolphin.GetPos());
  Dolphin dolphin_2(1.2, make_pair(13,7));
  ASSERT_EQ("DLP", dolphin_2.GetId());
  ASSERT_EQ(make_pair(13,7), dolphin_2.GetPos());
  ASSERT_EQ(2, dolphin_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, dolphin_2.GetWeight());
  ASSERT_EQ('K', dolphin_2.GetType());
  ASSERT_EQ('!', dolphin_2.GetLegend());
  set<char> h2 = {'W'};
  ASSERT_EQ(h2, dolphin_2.GetHabitat());
  set<string> c2 = {"PLC", "GSE", "CRN", "DGG", "DLP", "HPP", "MRE", "PLC", "PNG", "TRL", "WHL"};
  ASSERT_EQ(c2, dolphin_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, dolphin_2.GetEat());
  dolphin_2.Move(0);
  ASSERT_EQ(make_pair(12,7), dolphin_2.GetPos());
  dolphin_2.Move(1);
  ASSERT_EQ(make_pair(12,6), dolphin_2.GetPos());
  dolphin_2.Move(2);
  ASSERT_EQ(make_pair(12,7), dolphin_2.GetPos());
  dolphin_2.Move(3);
  ASSERT_EQ(make_pair(13,7), dolphin_2.GetPos());
}
