#include "crane.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class CraneTest : public ::testing::Test {
  protected:
    CraneTest(){}
};

TEST(CraneTest, GetTextMethod) {
  Crane crane(make_pair(1,23));
  ASSERT_EQ("CRN", crane.GetId());
  ASSERT_EQ(make_pair(1,23), crane.GetPos());
  ASSERT_EQ(1, crane.GetNumber());
  ASSERT_FLOAT_EQ(3, crane.GetWeight());
  ASSERT_EQ('O', crane.GetType());
  ASSERT_EQ('-', crane.GetLegend());
  set<char> h1 = {'A', 'W'};
  ASSERT_EQ(h1, crane.GetHabitat());
  set<string> c1 = {"HMB", "CLG", "DGG", "DLP", "DRL", "HPP", "MRE", "PNG", "SGL", "CKT", "TRL", "WHL", "RBN", "BT", "PLC", "GSE", "CRN"};
  ASSERT_EQ(c1, crane.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, crane.GetEat());
  crane.Move(0);
  ASSERT_EQ(make_pair(0,23), crane.GetPos());
  crane.Move(1);
  ASSERT_EQ(make_pair(0,22), crane.GetPos());
  crane.Move(2);
  ASSERT_EQ(make_pair(0,23), crane.GetPos());
  crane.Move(3);
  ASSERT_EQ(make_pair(1,23), crane.GetPos());
  Crane crane_2(1.2, make_pair(13,7));
  ASSERT_EQ("CRN", crane_2.GetId());
  ASSERT_EQ(make_pair(13,7), crane_2.GetPos());
  ASSERT_EQ(2, crane_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, crane_2.GetWeight());
  ASSERT_EQ('O', crane_2.GetType());
  ASSERT_EQ('-', crane_2.GetLegend());
  set<char> h2 = {'A', 'W'};
  ASSERT_EQ(h2, crane_2.GetHabitat());
  set<string> c2 = {"HMB", "CLG", "DGG", "DLP", "DRL", "HPP", "MRE", "PNG", "SGL", "CKT", "TRL", "WHL", "RBN", "BT", "PLC", "GSE", "CRN"};
  ASSERT_EQ(c2, crane_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, crane_2.GetEat());
  crane_2.Move(0);
  ASSERT_EQ(make_pair(12,7), crane_2.GetPos());
  crane_2.Move(1);
  ASSERT_EQ(make_pair(12,6), crane_2.GetPos());
  crane_2.Move(2);
  ASSERT_EQ(make_pair(12,7), crane_2.GetPos());
  crane_2.Move(3);
  ASSERT_EQ(make_pair(13,7), crane_2.GetPos());
}
