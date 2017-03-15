#include "../src/animals/eagle/eagle.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class EagleTest : public ::testing::Test {
  protected:
    EagleTest(){}
};

TEST(EagleTest, GetTextMethod) {
  Eagle eagle(make_pair(1,23));
  ASSERT_EQ("EGL", eagle.GetId());
  ASSERT_EQ(make_pair(1,23), eagle.GetPos());
  ASSERT_EQ(1, eagle.GetNumber());
  ASSERT_FLOAT_EQ(4, eagle.GetWeight());
  ASSERT_EQ('K', eagle.GetType());
  ASSERT_EQ('#', eagle.GetLegend());
  set<char> h1 = {'A'};
  ASSERT_EQ(h1, eagle.GetHabitat());
  set<string> c1 = {"EGL", "PLC", "OW"};
  ASSERT_EQ(c1, eagle.GetCompatible());
  ASSERT_FLOAT_EQ(0.7, eagle.GetEat());
  eagle.Move(0);
  ASSERT_EQ(make_pair(0,23), eagle.GetPos());
  eagle.Move(1);
  ASSERT_EQ(make_pair(0,22), eagle.GetPos());
  eagle.Move(2);
  ASSERT_EQ(make_pair(0,23), eagle.GetPos());
  eagle.Move(3);
  ASSERT_EQ(make_pair(1,23), eagle.GetPos());
  Eagle eagle_2(1.2, make_pair(13,7));
  ASSERT_EQ("EGL", eagle_2.GetId());
  ASSERT_EQ(make_pair(13,7), eagle_2.GetPos());
  ASSERT_EQ(2, eagle_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, eagle_2.GetWeight());
  ASSERT_EQ('K', eagle_2.GetType());
  ASSERT_EQ('#', eagle_2.GetLegend());
  set<char> h2 = {'A'};
  ASSERT_EQ(h2, eagle_2.GetHabitat());
  set<string> c2 = {"EGL", "PLC", "OW"};
  ASSERT_EQ(c2, eagle_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.7, eagle_2.GetEat());
  eagle_2.Move(0);
  ASSERT_EQ(make_pair(12,7), eagle_2.GetPos());
  eagle_2.Move(1);
  ASSERT_EQ(make_pair(12,6), eagle_2.GetPos());
  eagle_2.Move(2);
  ASSERT_EQ(make_pair(12,7), eagle_2.GetPos());
  eagle_2.Move(3);
  ASSERT_EQ(make_pair(13,7), eagle_2.GetPos());
}
