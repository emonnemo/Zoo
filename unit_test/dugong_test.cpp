#include "dugong.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class DugongTest : public ::testing::Test {
  protected:
    DugongTest(){}
};

TEST(DugongTest, GetTextMethod) {
  Dugong dugong(make_pair(1,23));
  ASSERT_EQ("DGG", dugong.GetId());
  ASSERT_EQ(make_pair(1,23), dugong.GetPos());
  ASSERT_EQ(1, dugong.GetNumber());
  ASSERT_FLOAT_EQ(294, dugong.GetWeight());
  ASSERT_EQ('H', dugong.GetType());
  ASSERT_EQ('9', dugong.GetLegend());
  set<char> h1 = {'W'};
  ASSERT_EQ(h1, dugong.GetHabitat());
  set<string> c1 = {"PLC", "GSE", "CRN", "DGG", "DLP", "HPP", "MRE", "PNG", "TRL", "WHL"};
  ASSERT_EQ(c1, dugong.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, dugong.GetEat());
  dugong.Move(0);
  ASSERT_EQ(make_pair(0,23), dugong.GetPos());
  dugong.Move(1);
  ASSERT_EQ(make_pair(0,22), dugong.GetPos());
  dugong.Move(2);
  ASSERT_EQ(make_pair(0,23), dugong.GetPos());
  dugong.Move(3);
  ASSERT_EQ(make_pair(1,23), dugong.GetPos());
  Dugong dugong_2(1.2, make_pair(13,7));
  ASSERT_EQ("DGG", dugong_2.GetId());
  ASSERT_EQ(make_pair(13,7), dugong_2.GetPos());
  ASSERT_EQ(2, dugong_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, dugong_2.GetWeight());
  ASSERT_EQ('H', dugong_2.GetType());
  ASSERT_EQ('9', dugong_2.GetLegend());
  set<char> h2 = {'W'};
  ASSERT_EQ(h2, dugong_2.GetHabitat());
  set<string> c2 = {"PLC", "GSE", "CRN", "DGG", "DLP", "HPP", "MRE", "PNG", "TRL", "WHL"};
  ASSERT_EQ(c2, dugong_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, dugong_2.GetEat());
  dugong_2.Move(0);
  ASSERT_EQ(make_pair(12,7), dugong_2.GetPos());
  dugong_2.Move(1);
  ASSERT_EQ(make_pair(12,6), dugong_2.GetPos());
  dugong_2.Move(2);
  ASSERT_EQ(make_pair(12,7), dugong_2.GetPos());
  dugong_2.Move(3);
  ASSERT_EQ(make_pair(13,7), dugong_2.GetPos());
}
