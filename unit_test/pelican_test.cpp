#include "../src/animals/pelican/pelican.h"
#include <set>
using namespace std;
#include<gtest/gtest.h>

class PelicanTest : public ::testing::Test {
  protected:
    PelicanTest(){}
};

TEST(PelicanTest, GetTextMethod) {
  Pelican pelican(make_pair(1,23));
  ASSERT_EQ("PLC", pelican.GetId());
  ASSERT_EQ(make_pair(1,23), pelican.GetPos());
  ASSERT_EQ(1, pelican.GetNumber());
  ASSERT_FLOAT_EQ(7, pelican.GetWeight());
  ASSERT_EQ('K', pelican.GetType());
  ASSERT_EQ('~', pelican.GetLegend());
  set<char> h1 = {'A','W'};
  ASSERT_EQ(h1, pelican.GetHabitat());
  set<string> c1 = {"MRE","DGG","DLP","WHL","PNG","HPP","PLC","GSE",
                    "CRN","EGL","OW","HMB","CKT","RBN","BT","CLG","SGL"};
  ASSERT_EQ(c1, pelican.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, pelican.GetEat());
  pelican.Move(0);
  ASSERT_EQ(make_pair(0,23), pelican.GetPos());
  pelican.Move(1);
  ASSERT_EQ(make_pair(0,22), pelican.GetPos());
  pelican.Move(2);
  ASSERT_EQ(make_pair(0,23), pelican.GetPos());
  pelican.Move(3);
  ASSERT_EQ(make_pair(1,23), pelican.GetPos());
  Pelican pelican_2(1.2, make_pair(13,7));
  ASSERT_EQ("PLC", pelican_2.GetId());
  ASSERT_EQ(make_pair(13,7), pelican_2.GetPos());
  ASSERT_EQ(2, pelican_2.GetNumber());
  ASSERT_FLOAT_EQ(1.2, pelican_2.GetWeight());
  ASSERT_EQ('K', pelican_2.GetType());
  ASSERT_EQ('~', pelican_2.GetLegend());
  set<char> h2 = {'A','W'};
  ASSERT_EQ(h2, pelican_2.GetHabitat());
  set<string> c2 = {"MRE","DGG","DLP","WHL","PNG","HPP","PLC","GSE",
                    "CRN","EGL","OW","HMB","CKT","RBN","BT","CLG","SGL"};
  ASSERT_EQ(c2, pelican_2.GetCompatible());
  ASSERT_FLOAT_EQ(0.3, pelican_2.GetEat());
  pelican_2.Move(0);
  ASSERT_EQ(make_pair(12,7), pelican_2.GetPos());
  pelican_2.Move(1);
  ASSERT_EQ(make_pair(12,6), pelican_2.GetPos());
  pelican_2.Move(2);
  ASSERT_EQ(make_pair(12,7), pelican_2.GetPos());
  pelican_2.Move(3);
  ASSERT_EQ(make_pair(13,7), pelican_2.GetPos());
}
