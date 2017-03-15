#include "../src/animals/hog/hog.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class HogTest : public ::testing::Test {
  protected:
    HogTest(){}
};

TEST(HogTest, GetTextMethod) {
  Hog hog(make_pair(1,23));
  ASSERT_EQ("HG", hog.GetId());
  ASSERT_EQ(make_pair(1,23), hog.GetPos());
  ASSERT_EQ(1, hog.GetNumber());
  ASSERT_FLOAT_EQ(68, hog.GetWeight());
  ASSERT_EQ('O', hog.GetType());
  ASSERT_EQ('6', hog.GetLegend());
  set<char> h1 = {'L'};
  ASSERT_EQ(h1, hog.GetHabitat());
  set<string> c1 = {"ZBR", "ELP", "MCQ", "HG", "HPP"};
  ASSERT_EQ(c1, hog.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, hog.GetEat());
  hog.Move(0);
  ASSERT_EQ(make_pair(0,23), hog.GetPos());
  hog.Move(1);
  ASSERT_EQ(make_pair(0,22), hog.GetPos());
  hog.Move(2);
  ASSERT_EQ(make_pair(0,23), hog.GetPos());
  hog.Move(3);
  ASSERT_EQ(make_pair(1,23), hog.GetPos());
  Hog hog_2(1.2, make_pair(13,7));
  ASSERT_EQ("HG", hog_2.GetId());
  ASSERT_EQ(make_pair(13,7), hog_2.GetPos());
  ASSERT_EQ(2, hog_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, hog_2.GetWeight());
  ASSERT_EQ('O', hog_2.GetType());
  ASSERT_EQ('6', hog_2.GetLegend());
  set<char> h2 = {'L'};
  ASSERT_EQ(h2, hog_2.GetHabitat());
  set<string> c2 = {"ZBR", "ELP", "MCQ", "HG", "HPP"};
  ASSERT_EQ(c2, hog_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.2, hog_2.GetEat());
  hog_2.Move(0);
  ASSERT_EQ(make_pair(12,7), hog_2.GetPos());
  hog_2.Move(1);
  ASSERT_EQ(make_pair(12,6), hog_2.GetPos());
  hog_2.Move(2);
  ASSERT_EQ(make_pair(12,7), hog_2.GetPos());
  hog_2.Move(3);
  ASSERT_EQ(make_pair(13,7), hog_2.GetPos());
}
