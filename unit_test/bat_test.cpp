#include "bat.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class BatTest : public ::testing::Test {
  protected:
    BatTest(){}
};

TEST(BatTest, GetTextMethod) {
  Bat bat(make_pair(1,23));
  ASSERT_EQ("BT", bat.GetId());
  ASSERT_EQ(make_pair(1,23), bat.GetPos());
  ASSERT_EQ(1, bat.GetNumber());
  ASSERT_FLOAT_EQ(0.15, bat.GetWeight());
  ASSERT_EQ('O', bat.GetType());
  ASSERT_EQ('*', bat.GetLegend());
  set<char> h1 = {'A'};
  ASSERT_EQ(h1, bat.GetHabitat());
  set<string> c1 = {"HMB", "CKT", "RBN", "BT", "PLC", "GSE", "CRN"};
  ASSERT_EQ(c1, bat.GetCompatible());
  ASSERT_FLOAT_EQ(0.4, bat.GetEat());
  bat.Move(0);
  ASSERT_EQ(make_pair(0,23), bat.GetPos());
  bat.Move(1);
  ASSERT_EQ(make_pair(0,22), bat.GetPos());
  bat.Move(2);
  ASSERT_EQ(make_pair(0,23), bat.GetPos());
  bat.Move(3);
  ASSERT_EQ(make_pair(1,23), bat.GetPos());
  Bat bat_2(1.2, make_pair(13,7));
  ASSERT_EQ("BT", bat_2.GetId());
  ASSERT_EQ(make_pair(13,7), bat_2.GetPos());
  ASSERT_EQ(2, bat_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, bat_2.GetWeight());
  ASSERT_EQ('O', bat_2.GetType());
  ASSERT_EQ('*', bat_2.GetLegend());
  set<char> h2 = {'A'};
  ASSERT_EQ(h2, bat_2.GetHabitat());
  set<string> c2 = {"HMB","CKT","RBN","BT","PLC","GSE","CRN"};
  ASSERT_EQ(c2, bat_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.4, bat_2.GetEat());
  bat_2.Move(0);
  ASSERT_EQ(make_pair(12,7), bat_2.GetPos());
  bat_2.Move(1);
  ASSERT_EQ(make_pair(12,6), bat_2.GetPos());
  bat_2.Move(2);
  ASSERT_EQ(make_pair(12,7), bat_2.GetPos());
  bat_2.Move(3);
  ASSERT_EQ(make_pair(13,7), bat_2.GetPos());
}
