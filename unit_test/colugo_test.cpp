#include "../src/animals/colugo/colugo.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class ColugoTest : public ::testing::Test {
  protected:
    ColugoTest(){}
};

TEST(ColugoTest, GetTextMethod) {
  Colugo colugo(make_pair(1,23));
  ASSERT_EQ("CLG", colugo.GetId());
  ASSERT_EQ(make_pair(1,23), colugo.GetPos());
  ASSERT_EQ(1, colugo.GetNumber());
  ASSERT_FLOAT_EQ(0.035, colugo.GetWeight());
  ASSERT_EQ('H', colugo.GetType());
  ASSERT_EQ('<', colugo.GetLegend());
  set<char> h1 = {'A','L'};
  ASSERT_EQ(h1, colugo.GetHabitat());
  set<string> c1 = {"HMB", "CKT", "CLG", "DRL", "HG", "HPP", "MCQ", "PNG",
                    "RBN", "GSE", "CRN", "SGL", "ZBR"};
  ASSERT_EQ(c1, colugo.GetCompatible());
  ASSERT_FLOAT_EQ(0.25, colugo.GetEat());
  colugo.Move(0);
  ASSERT_EQ(make_pair(0,23), colugo.GetPos());
  colugo.Move(1);
  ASSERT_EQ(make_pair(0,22), colugo.GetPos());
  colugo.Move(2);
  ASSERT_EQ(make_pair(0,23), colugo.GetPos());
  colugo.Move(3);
  ASSERT_EQ(make_pair(1,23), colugo.GetPos());
  Colugo colugo_2(1.2, make_pair(13,7));
  ASSERT_EQ("CLG", colugo_2.GetId());
  ASSERT_EQ(make_pair(13,7), colugo_2.GetPos());
  ASSERT_EQ(2, colugo_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, colugo_2.GetWeight());
  ASSERT_EQ('H', colugo_2.GetType());
  ASSERT_EQ('<', colugo_2.GetLegend());
  set<char> h2 = {'A','L'};
  ASSERT_EQ(h2, colugo_2.GetHabitat());
  set<string> c2 = {"HMB", "CKT", "CLG", "DRL", "HG", "HPP", "MCQ", "PNG",
                    "RBN", "GSE", "CRN", "SGL", "ZBR"};
  ASSERT_EQ(c2, colugo_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.25, colugo_2.GetEat());
  colugo_2.Move(0);
  ASSERT_EQ(make_pair(12,7), colugo_2.GetPos());
  colugo_2.Move(1);
  ASSERT_EQ(make_pair(12,6), colugo_2.GetPos());
  colugo_2.Move(2);
  ASSERT_EQ(make_pair(12,7), colugo_2.GetPos());
  colugo_2.Move(3);
  ASSERT_EQ(make_pair(13,7), colugo_2.GetPos());
}
