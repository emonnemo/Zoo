#include "sugar_glider.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class SugarGliderTest : public ::testing::Test {
  protected:
    SugarGliderTest(){}
};

TEST(SugarGliderTest, GetTextMethod) {
  SugarGlider sugarGlider(make_pair(1,23));
  ASSERT_EQ("SGL", sugarGlider.GetId());
  ASSERT_EQ(make_pair(1,23), sugarGlider.GetPos());
  ASSERT_EQ(1, sugarGlider.GetNumber());
  ASSERT_FLOAT_EQ(0.12, sugarGlider.GetWeight());
  ASSERT_EQ('O', sugarGlider.GetType());
  ASSERT_EQ('>', sugarGlider.GetLegend());
  set<char> h1 = {'A','L'};
  ASSERT_EQ(h1, sugarGlider.GetHabitat());
  set<string> c1 = {"HMB", "ZBR", "MCQ", "HG", "PNG", "DRL", "CLG","SGL","GSE","CRN"};
  ASSERT_EQ(c1, sugarGlider.GetCompatible());
  ASSERT_FLOAT_EQ(0.5, sugarGlider.GetEat());
  sugarGlider.Move(0);
  ASSERT_EQ(make_pair(0,23), sugarGlider.GetPos());
  sugarGlider.Move(1);
  ASSERT_EQ(make_pair(0,22), sugarGlider.GetPos());
  sugarGlider.Move(2);
  ASSERT_EQ(make_pair(0,23), sugarGlider.GetPos());
  sugarGlider.Move(3);
  ASSERT_EQ(make_pair(1,23), sugarGlider.GetPos());
  SugarGlider sugarGlider_2(1.2, make_pair(13,7));
  ASSERT_EQ("SGL", sugarGlider_2.GetId());
  ASSERT_EQ(make_pair(13,7), sugarGlider_2.GetPos());
  ASSERT_EQ(2, sugarGlider_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, sugarGlider_2.GetWeight());
  ASSERT_EQ('O', sugarGlider_2.GetType());
  ASSERT_EQ('>', sugarGlider_2.GetLegend());
  set<char> h2 = {'A','L'};
  ASSERT_EQ(h2, sugarGlider_2.GetHabitat());
  set<string> c2 = {"HMB", "ZBR", "MCQ", "HG", "PNG", "DRL", "CLG","SGL","GSE","CRN"};
  ASSERT_EQ(c2, sugarGlider_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.5, sugarGlider_2.GetEat());
  sugarGlider_2.Move(0);
  ASSERT_EQ(make_pair(12,7), sugarGlider_2.GetPos());
  sugarGlider_2.Move(1);
  ASSERT_EQ(make_pair(12,6), sugarGlider_2.GetPos());
  sugarGlider_2.Move(2);
  ASSERT_EQ(make_pair(12,7), sugarGlider_2.GetPos());
  sugarGlider_2.Move(3);
  ASSERT_EQ(make_pair(13,7), sugarGlider_2.GetPos());
}
