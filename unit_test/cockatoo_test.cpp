#include "cockatoo.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class CockatooTest : public ::testing::Test {
  protected:
    CockatooTest(){}
};

TEST(CockatooTest, GetTextMethod) {
  Cockatoo cockatoo(make_pair(1,23));
  ASSERT_EQ("CKT", cockatoo.GetId());
  ASSERT_EQ(make_pair(1,23), cockatoo.GetPos());
  ASSERT_EQ(1, cockatoo.GetNumber());
  ASSERT_FLOAT_EQ(0.09, cockatoo.GetWeight());
  ASSERT_EQ('H', cockatoo.GetType());
  ASSERT_EQ('^', cockatoo.GetLegend());
  set<char> h1 = {'A'};
  ASSERT_EQ(h1, cockatoo.GetHabitat());
  set<string> c1 = {"HMB", "CKT", "RBN", "BT", "PLC", "GSE", "CRN", "CLG"};
  ASSERT_EQ(c1, cockatoo.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, cockatoo.GetEat());
  cockatoo.Move(0);
  ASSERT_EQ(make_pair(0,23), cockatoo.GetPos());
  cockatoo.Move(1);
  ASSERT_EQ(make_pair(0,22), cockatoo.GetPos());
  cockatoo.Move(2);
  ASSERT_EQ(make_pair(0,23), cockatoo.GetPos());
  cockatoo.Move(3);
  ASSERT_EQ(make_pair(1,23), cockatoo.GetPos());
  Cockatoo cockatoo_2(1.2, make_pair(13,7));
  ASSERT_EQ("CKT", cockatoo_2.GetId());
  ASSERT_EQ(make_pair(13,7), cockatoo_2.GetPos());
  ASSERT_EQ(2, cockatoo_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, cockatoo_2.GetWeight());
  ASSERT_EQ('H', cockatoo_2.GetType());
  ASSERT_EQ('^', cockatoo_2.GetLegend());
  set<char> h2 = {'A'};
  ASSERT_EQ(h2, cockatoo_2.GetHabitat());
  set<string> c2 = {"HMB","CKT","RBN","BT","PLC","GSE","CRN", "CLG"};
  ASSERT_EQ(c2, cockatoo_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, cockatoo_2.GetEat());
  cockatoo_2.Move(0);
  ASSERT_EQ(make_pair(12,7), cockatoo_2.GetPos());
  cockatoo_2.Move(1);
  ASSERT_EQ(make_pair(12,6), cockatoo_2.GetPos());
  cockatoo_2.Move(2);
  ASSERT_EQ(make_pair(12,7), cockatoo_2.GetPos());
  cockatoo_2.Move(3);
  ASSERT_EQ(make_pair(13,7), cockatoo_2.GetPos());
}
