#include "hippopotamus.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class HippopotamusTest : public ::testing::Test {
  protected:
    HippopotamusTest(){}
};

TEST(HippopotamusTest, GetTextMethod) {
  Hippopotamus hippopotamus(make_pair(1,23));
  ASSERT_EQ("HPP", hippopotamus.GetId());
  ASSERT_EQ(make_pair(1,23), hippopotamus.GetPos());
  ASSERT_EQ(1, hippopotamus.GetNumber());
  ASSERT_FLOAT_EQ(1496, hippopotamus.GetWeight());
  ASSERT_EQ('H', hippopotamus.GetType());
  ASSERT_EQ(')', hippopotamus.GetLegend());
  set<char> h1 = {'L','W'};
  ASSERT_EQ(h1, hippopotamus.GetHabitat());
  set<string> c1 = {"PLC", "GSE", "CRN", "WF", "ZBR", "ELP","MCQ", "HG",
                    "PNG", "HPP", "CLG", "MRE", "DGG", "TRL", "DLP", "WHL"};
  ASSERT_EQ(c1, hippopotamus.GetCompatible());
  ASSERT_FLOAT_EQ(0.65, hippopotamus.GetEat());
  hippopotamus.Move(0);
  ASSERT_EQ(make_pair(0,23), hippopotamus.GetPos());
  hippopotamus.Move(1);
  ASSERT_EQ(make_pair(0,22), hippopotamus.GetPos());
  hippopotamus.Move(2);
  ASSERT_EQ(make_pair(0,23), hippopotamus.GetPos());
  hippopotamus.Move(3);
  ASSERT_EQ(make_pair(1,23), hippopotamus.GetPos());
  Hippopotamus hippopotamus_2(1.2, make_pair(13,7));
  ASSERT_EQ("HPP", hippopotamus_2.GetId());
  ASSERT_EQ(make_pair(13,7), hippopotamus_2.GetPos());
  ASSERT_EQ(2, hippopotamus_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, hippopotamus_2.GetWeight());
  ASSERT_EQ('H', hippopotamus_2.GetType());
  ASSERT_EQ(')', hippopotamus_2.GetLegend());
  set<char> h2 = {'L','W'};
  ASSERT_EQ(h2, hippopotamus_2.GetHabitat());
  set<string> c2 = {"PLC", "GSE", "CRN", "WF", "ZBR", "ELP","MCQ", "HG",
                    "PNG", "HPP", "CLG", "MRE", "DGG", "TRL", "DLP", "WHL"};
  ASSERT_EQ(c2, hippopotamus_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.65, hippopotamus_2.GetEat());
  hippopotamus_2.Move(0);
  ASSERT_EQ(make_pair(12,7), hippopotamus_2.GetPos());
  hippopotamus_2.Move(1);
  ASSERT_EQ(make_pair(12,6), hippopotamus_2.GetPos());
  hippopotamus_2.Move(2);
  ASSERT_EQ(make_pair(12,7), hippopotamus_2.GetPos());
  hippopotamus_2.Move(3);
  ASSERT_EQ(make_pair(13,7), hippopotamus_2.GetPos());
}
