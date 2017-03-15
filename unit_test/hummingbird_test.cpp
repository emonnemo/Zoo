#include "hummingbird.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class HummingbirdTest : public ::testing::Test {
  protected:
    HummingbirdTest(){}
};

TEST(HummingbirdTest, GetTextMethod) {
  Hummingbird hummingbird(make_pair(1,23));
  ASSERT_EQ("HMB", hummingbird.GetId());
  ASSERT_EQ(make_pair(1,23), hummingbird.GetPos());
  ASSERT_EQ(1, hummingbird.GetNumber());
  ASSERT_FLOAT_EQ(0.0002, hummingbird.GetWeight());
  ASSERT_EQ('H', hummingbird.GetType());
  ASSERT_EQ('%', hummingbird.GetLegend());
  set<char> h1 = {'A'};
  ASSERT_EQ(h1, hummingbird.GetHabitat());
  set<string> c1 = {"HMB", "CKT", "RBN", "BT", "PLC", "GSE", "CRN", "CLG", "SGL"};
  ASSERT_EQ(c1, hummingbird.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, hummingbird.GetEat());
  hummingbird.Move(0);
  ASSERT_EQ(make_pair(0,23), hummingbird.GetPos());
  hummingbird.Move(1);
  ASSERT_EQ(make_pair(0,22), hummingbird.GetPos());
  hummingbird.Move(2);
  ASSERT_EQ(make_pair(0,23), hummingbird.GetPos());
  hummingbird.Move(3);
  ASSERT_EQ(make_pair(1,23), hummingbird.GetPos());
  Hummingbird hummingbird_2(1.2, make_pair(13,7));
  ASSERT_EQ("HMB", hummingbird_2.GetId());
  ASSERT_EQ(make_pair(13,7), hummingbird_2.GetPos());
  ASSERT_EQ(2, hummingbird_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, hummingbird_2.GetWeight());
  ASSERT_EQ('H', hummingbird_2.GetType());
  ASSERT_EQ('%', hummingbird_2.GetLegend());
  set<char> h2 = {'A'};
  ASSERT_EQ(h2, hummingbird_2.GetHabitat());
  set<string> c2 = {"HMB","CKT","RBN","BT","PLC","GSE","CRN", "CLG", "SGL"};
  ASSERT_EQ(c2, hummingbird_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, hummingbird_2.GetEat());
  hummingbird_2.Move(0);
  ASSERT_EQ(make_pair(12,7), hummingbird_2.GetPos());
  hummingbird_2.Move(1);
  ASSERT_EQ(make_pair(12,6), hummingbird_2.GetPos());
  hummingbird_2.Move(2);
  ASSERT_EQ(make_pair(12,7), hummingbird_2.GetPos());
  hummingbird_2.Move(3);
  ASSERT_EQ(make_pair(13,7), hummingbird_2.GetPos());
}
