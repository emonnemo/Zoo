#include "draco_lizard.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class DracoLizardTest : public ::testing::Test {
  protected:
    DracoLizardTest(){}
};

TEST(dracoLizardTest, GetTextMethod) {
  DracoLizard dracoLizard(make_pair(1,23));
  ASSERT_EQ("DRL", dracoLizard.GetId());
  ASSERT_EQ(make_pair(1,23), dracoLizard.GetPos());
  ASSERT_EQ(1, dracoLizard.GetNumber());
  ASSERT_FLOAT_EQ(0.2, dracoLizard.GetWeight());
  ASSERT_EQ('K', dracoLizard.GetType());
  ASSERT_EQ('=', dracoLizard.GetLegend());
  set<char> h1 = {'A','L'};
  ASSERT_EQ(h1, dracoLizard.GetHabitat());
  set<string> c1 = {"RBN", "GSE", "CRN", "CLG", "DRL", "HG", "MCQ", "OW", "PNG", "SGL", "ZBR"};
  ASSERT_EQ(c1, dracoLizard.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, dracoLizard.GetEat());
  dracoLizard.Move(0);
  ASSERT_EQ(make_pair(0,23), dracoLizard.GetPos());
  dracoLizard.Move(1);
  ASSERT_EQ(make_pair(0,22), dracoLizard.GetPos());
  dracoLizard.Move(2);
  ASSERT_EQ(make_pair(0,23), dracoLizard.GetPos());
  dracoLizard.Move(3);
  ASSERT_EQ(make_pair(1,23), dracoLizard.GetPos());
  DracoLizard dracoLizard_2(1.2, make_pair(13,7));
  ASSERT_EQ("DRL", dracoLizard_2.GetId());
  ASSERT_EQ(make_pair(13,7), dracoLizard_2.GetPos());
  ASSERT_EQ(2, dracoLizard_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, dracoLizard_2.GetWeight());
  ASSERT_EQ('K', dracoLizard_2.GetType());
  ASSERT_EQ('=', dracoLizard_2.GetLegend());
  set<char> h2 = {'A','L'};
  ASSERT_EQ(h2, dracoLizard_2.GetHabitat());
  set<string> c2 = {"RBN", "GSE", "CRN", "CLG", "DRL", "HG", "MCQ", "OW", "PNG", "SGL", "ZBR"};
  ASSERT_EQ(c2, dracoLizard_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, dracoLizard_2.GetEat());
  dracoLizard_2.Move(0);
  ASSERT_EQ(make_pair(12,7), dracoLizard_2.GetPos());
  dracoLizard_2.Move(1);
  ASSERT_EQ(make_pair(12,6), dracoLizard_2.GetPos());
  dracoLizard_2.Move(2);
  ASSERT_EQ(make_pair(12,7), dracoLizard_2.GetPos());
  dracoLizard_2.Move(3);
  ASSERT_EQ(make_pair(13,7), dracoLizard_2.GetPos());
}
