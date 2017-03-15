#include "../src/animals/penguin/penguin.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class PenguinTest : public ::testing::Test {
  protected:
    PenguinTest(){}
};

TEST(PenguinTest, GetTextMethod) {
  Penguin penguin(make_pair(1,23));
  ASSERT_EQ("PNG", penguin.GetId());
  ASSERT_EQ(make_pair(1,23), penguin.GetPos());
  ASSERT_EQ(1, penguin.GetNumber());
  ASSERT_FLOAT_EQ(22, penguin.GetWeight());
  ASSERT_EQ('K', penguin.GetType());
  ASSERT_EQ('(', penguin.GetLegend());
  set<char> h1 = {'L','W'};
  ASSERT_EQ(h1, penguin.GetHabitat());
  set<string> c1 = {"ZBR","ELP","PNG","HPP","DRL","CLG","SGL","DGG",
                    "TRL","DLP","WHL","PLC","GSE","CRN"};
  ASSERT_EQ(c1, penguin.GetCompatible());
  ASSERT_FLOAT_EQ(0.25, penguin.GetEat());
  penguin.Move(0);
  ASSERT_EQ(make_pair(0,23), penguin.GetPos());
  penguin.Move(1);
  ASSERT_EQ(make_pair(0,22), penguin.GetPos());
  penguin.Move(2);
  ASSERT_EQ(make_pair(0,23), penguin.GetPos());
  penguin.Move(3);
  ASSERT_EQ(make_pair(1,23), penguin.GetPos());
  Penguin penguin_2(1.2, make_pair(13,7));
  ASSERT_EQ("PNG", penguin_2.GetId());
  ASSERT_EQ(make_pair(13,7), penguin_2.GetPos());
  ASSERT_EQ(2, penguin_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, penguin_2.GetWeight());
  ASSERT_EQ('K', penguin_2.GetType());
  ASSERT_EQ('(', penguin_2.GetLegend());
  set<char> h2 = {'L','W'};
  ASSERT_EQ(h2, penguin_2.GetHabitat());
  set<string> c2 = {"ZBR","ELP","PNG","HPP","DRL","CLG","SGL","DGG",
                    "TRL","DLP","WHL","PLC","GSE","CRN"};
  ASSERT_EQ(c2, penguin_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.25, penguin_2.GetEat());
  penguin_2.Move(0);
  ASSERT_EQ(make_pair(12,7), penguin_2.GetPos());
  penguin_2.Move(1);
  ASSERT_EQ(make_pair(12,6), penguin_2.GetPos());
  penguin_2.Move(2);
  ASSERT_EQ(make_pair(12,7), penguin_2.GetPos());
  penguin_2.Move(3);
  ASSERT_EQ(make_pair(13,7), penguin_2.GetPos());
}
