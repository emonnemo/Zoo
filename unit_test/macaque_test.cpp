#include "../src/animals/macaque/macaque.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class MacaqueTest : public ::testing::Test {
  protected:
    MacaqueTest(){}
};

TEST(MacaqueTest, GetTextMethod) {
  Macaque macaque(make_pair(1,23));
  ASSERT_EQ("MCQ", macaque.GetId());
  ASSERT_EQ(make_pair(1,23), macaque.GetPos());
  ASSERT_EQ(1, macaque.GetNumber());
  ASSERT_FLOAT_EQ(9, macaque.GetWeight());
  ASSERT_EQ('O', macaque.GetType());
  ASSERT_EQ('5', macaque.GetLegend());
  set<char> h1 = {'L'};
  ASSERT_EQ(h1, macaque.GetHabitat());
  set<string> c1 = {"ZBR","ELP","MCQ","HG","HPP","DRL","CLG","SGL"};
  ASSERT_EQ(c1, macaque.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, macaque.GetEat());
  macaque.Move(0);
  ASSERT_EQ(make_pair(0,23), macaque.GetPos());
  macaque.Move(1);
  ASSERT_EQ(make_pair(0,22), macaque.GetPos());
  macaque.Move(2);
  ASSERT_EQ(make_pair(0,23), macaque.GetPos());
  macaque.Move(3);
  ASSERT_EQ(make_pair(1,23), macaque.GetPos());
  Macaque macaque_2(1.2, make_pair(13,7));
  ASSERT_EQ("MCQ", macaque_2.GetId());
  ASSERT_EQ(make_pair(13,7), macaque_2.GetPos());
  ASSERT_EQ(2, macaque_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, macaque_2.GetWeight());
  ASSERT_EQ('O', macaque_2.GetType());
  ASSERT_EQ('5', macaque_2.GetLegend());
  set<char> h2 = {'L'};
  ASSERT_EQ(h2, macaque_2.GetHabitat());
  set<string> c2 = {"ZBR","ELP","MCQ","HG","HPP","DRL","CLG","SGL"};
  ASSERT_EQ(c2, macaque_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, macaque_2.GetEat());
  macaque_2.Move(0);
  ASSERT_EQ(make_pair(12,7), macaque_2.GetPos());
  macaque_2.Move(1);
  ASSERT_EQ(make_pair(12,6), macaque_2.GetPos());
  macaque_2.Move(2);
  ASSERT_EQ(make_pair(12,7), macaque_2.GetPos());
  macaque_2.Move(3);
  ASSERT_EQ(make_pair(13,7), macaque_2.GetPos());
}
