#include "whale.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class WhaleTest : public ::testing::Test {
  protected:
    WhaleTest(){}
};

TEST(WhaleTest, GetTextMethod) {
  Whale whale(make_pair(1,23));
  ASSERT_EQ("WHL", whale.GetId());
  ASSERT_EQ(make_pair(1,23), whale.GetPos());
  ASSERT_EQ(1, whale.GetNumber());
  ASSERT_FLOAT_EQ(40000, whale.GetWeight());
  ASSERT_EQ('O', whale.GetType());
  ASSERT_EQ('@', whale.GetLegend());
  set<char> h1 = {'W'};
  ASSERT_EQ(h1, whale.GetHabitat());
  set<string> c1 = {"SHK","MRE","DGG","TRL","DLP","WHL","PNG","HPP","PLC","GSE","CRN"};
  ASSERT_EQ(c1, whale.GetCompatible());
  ASSERT_FLOAT_EQ(0.1, whale.GetEat());
  whale.Move(0);
  ASSERT_EQ(make_pair(0,23), whale.GetPos());
  whale.Move(1);
  ASSERT_EQ(make_pair(0,22), whale.GetPos());
  whale.Move(2);
  ASSERT_EQ(make_pair(0,23), whale.GetPos());
  whale.Move(3);
  ASSERT_EQ(make_pair(1,23), whale.GetPos());
  Whale whale_2(1.2, make_pair(13,7));
  ASSERT_EQ("WHL", whale_2.GetId());
  ASSERT_EQ(make_pair(13,7), whale_2.GetPos());
  ASSERT_EQ(2, whale_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, whale_2.GetWeight());
  ASSERT_EQ('O', whale_2.GetType());
  ASSERT_EQ('@', whale_2.GetLegend());
  set<char> h2 = {'W'};
  ASSERT_EQ(h2, whale_2.GetHabitat());
  set<string> c2 = {"SHK","MRE","DGG","TRL","DLP","WHL","PNG","HPP","PLC","GSE","CRN"};
  ASSERT_EQ(c2, whale_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.1, whale_2.GetEat());
  whale_2.Move(0);
  ASSERT_EQ(make_pair(12,7), whale_2.GetPos());
  whale_2.Move(1);
  ASSERT_EQ(make_pair(12,6), whale_2.GetPos());
  whale_2.Move(2);
  ASSERT_EQ(make_pair(12,7), whale_2.GetPos());
  whale_2.Move(3);
  ASSERT_EQ(make_pair(13,7), whale_2.GetPos());
}
