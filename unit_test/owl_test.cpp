#include "owl.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class OwlTest : public ::testing::Test {
  protected:
    OwlTest(){}
};

TEST(OwlTest, GetTextMethod) {
  Owl owl(make_pair(1,23));
  ASSERT_EQ("OW", owl.GetId());
  ASSERT_EQ(make_pair(1,23), owl.GetPos());
  ASSERT_EQ(1, owl.GetNumber());
  ASSERT_FLOAT_EQ(2, owl.GetWeight());
  ASSERT_EQ('K', owl.GetType());
  ASSERT_EQ('$', owl.GetLegend());
  set<char> h1 = {'A'};
  ASSERT_EQ(h1, owl.GetHabitat());
  set<string> c1 = {"EGL", "OW", "PLC", "DRL"};
  ASSERT_EQ(c1, owl.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, owl.GetEat());
  owl.Move(0);
  ASSERT_EQ(make_pair(0,23), owl.GetPos());
  owl.Move(1);
  ASSERT_EQ(make_pair(0,22), owl.GetPos());
  owl.Move(2);
  ASSERT_EQ(make_pair(0,23), owl.GetPos());
  owl.Move(3);
  ASSERT_EQ(make_pair(1,23), owl.GetPos());
  Owl owl_2(1.2, make_pair(13,7));
  ASSERT_EQ("OW", owl_2.GetId());
  ASSERT_EQ(make_pair(13,7), owl_2.GetPos());
  ASSERT_EQ(2, owl_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, owl_2.GetWeight());
  ASSERT_EQ('K', owl_2.GetType());
  ASSERT_EQ('$', owl_2.GetLegend());
  set<char> h2 = {'A'};
  ASSERT_EQ(h2, owl_2.GetHabitat());
  set<string> c2 = {"EGL", "OW", "PLC", "DRL"};
  ASSERT_EQ(c2, owl_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, owl_2.GetEat());
  owl_2.Move(0);
  ASSERT_EQ(make_pair(12,7), owl_2.GetPos());
  owl_2.Move(1);
  ASSERT_EQ(make_pair(12,6), owl_2.GetPos());
  owl_2.Move(2);
  ASSERT_EQ(make_pair(12,7), owl_2.GetPos());
  owl_2.Move(3);
  ASSERT_EQ(make_pair(13,7), owl_2.GetPos());
}
