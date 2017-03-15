#include "../src/animals/robin/robin.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class RobinTest : public ::testing::Test {
  protected:
    RobinTest(){}
};

TEST(RobinTest, GetTextMethod) {
  Robin robin(make_pair(1,23));
  ASSERT_EQ("RBN", robin.GetId());
  ASSERT_EQ(make_pair(1,23), robin.GetPos());
  ASSERT_EQ(1, robin.GetNumber());
  ASSERT_FLOAT_EQ(0.06, robin.GetWeight());
  ASSERT_EQ('O', robin.GetType());
  ASSERT_EQ('&', robin.GetLegend());
  set<char> h1 = {'A'};
  ASSERT_EQ(h1, robin.GetHabitat());
  set<string> c1 = {"HMB", "CKT", "RBN", "BT", "PLC", "GSE", "CRN", "CLG", "DRL"};
  ASSERT_EQ(c1, robin.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, robin.GetEat());
  robin.Move(0);
  ASSERT_EQ(make_pair(0,23), robin.GetPos());
  robin.Move(1);
  ASSERT_EQ(make_pair(0,22), robin.GetPos());
  robin.Move(2);
  ASSERT_EQ(make_pair(0,23), robin.GetPos());
  robin.Move(3);
  ASSERT_EQ(make_pair(1,23), robin.GetPos());
  Robin robin_2(1.2, make_pair(13,7));
  ASSERT_EQ("RBN", robin_2.GetId());
  ASSERT_EQ(make_pair(13,7), robin_2.GetPos());
  ASSERT_EQ(2, robin_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, robin_2.GetWeight());
  ASSERT_EQ('O', robin_2.GetType());
  ASSERT_EQ('&', robin_2.GetLegend());
  set<char> h2 = {'A'};
  ASSERT_EQ(h2, robin_2.GetHabitat());
  set<string> c2 = {"HMB","CKT","RBN","BT","PLC","GSE","CRN", "CLG", "DRL"};
  ASSERT_EQ(c2, robin_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, robin_2.GetEat());
  robin_2.Move(0);
  ASSERT_EQ(make_pair(12,7), robin_2.GetPos());
  robin_2.Move(1);
  ASSERT_EQ(make_pair(12,6), robin_2.GetPos());
  robin_2.Move(2);
  ASSERT_EQ(make_pair(12,7), robin_2.GetPos());
  robin_2.Move(3);
  ASSERT_EQ(make_pair(13,7), robin_2.GetPos());
}
