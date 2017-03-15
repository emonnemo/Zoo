#include "../src/animals/goose/goose.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class GooseTest : public ::testing::Test {
  protected:
    GooseTest(){}
};

TEST(gooseTest, GetTextMethod) {
  Goose goose(make_pair(1,23));
  ASSERT_EQ("GSE", goose.GetId());
  ASSERT_EQ(make_pair(1,23), goose.GetPos());
  ASSERT_EQ(1, goose.GetNumber());
  ASSERT_FLOAT_EQ(4, goose.GetWeight());
  ASSERT_EQ('H', goose.GetType());
  ASSERT_EQ('+', goose.GetLegend());
  set<char> h1 = {'A','W'};
  ASSERT_EQ(h1, goose.GetHabitat());
  set<string> c1 = {"MRE", "DGG", "TRL", "DLP", "WHL", "PNG", "HPP", "HMB",
                    "CKT", "RBN", "BT", "PLC", "GSE", "CRN", "CLG","SGL"};
  ASSERT_EQ(c1, goose.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, goose.GetEat());
  goose.Move(0);
  ASSERT_EQ(make_pair(0,23), goose.GetPos());
  goose.Move(1);
  ASSERT_EQ(make_pair(0,22), goose.GetPos());
  goose.Move(2);
  ASSERT_EQ(make_pair(0,23), goose.GetPos());
  goose.Move(3);
  ASSERT_EQ(make_pair(1,23), goose.GetPos());
  Goose goose_2(1.2, make_pair(13,7));
  ASSERT_EQ("GSE", goose_2.GetId());
  ASSERT_EQ(make_pair(13,7), goose_2.GetPos());
  ASSERT_EQ(2, goose_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, goose_2.GetWeight());
  ASSERT_EQ('H', goose_2.GetType());
  ASSERT_EQ('+', goose_2.GetLegend());
  set<char> h2 = {'A', 'W'};
  ASSERT_EQ(h2, goose_2.GetHabitat());
  set<string> c2 = {"MRE", "DGG", "TRL", "DLP", "WHL", "PNG", "HPP", "HMB",
                    "CKT", "RBN", "BT", "PLC", "GSE", "CRN", "CLG","SGL"};
  ASSERT_EQ(c2, goose_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, goose_2.GetEat());
  goose_2.Move(0);
  ASSERT_EQ(make_pair(12,7), goose_2.GetPos());
  goose_2.Move(1);
  ASSERT_EQ(make_pair(12,6), goose_2.GetPos());
  goose_2.Move(2);
  ASSERT_EQ(make_pair(12,7), goose_2.GetPos());
  goose_2.Move(3);
  ASSERT_EQ(make_pair(13,7), goose_2.GetPos());
}
