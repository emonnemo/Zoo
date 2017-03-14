#include "bat.h"
#include<gtest/gtest.h>

class BatTest : public ::testing::Test {
  protected:
    BatTest(){}
};

TEST(BatTest, GetTextMethod) {
  Bat bat(make_pair(1,23));
  ASSERT_EQ("BT", bat.GetID());
  ASSERT_EQ(make_pair(1,23), bat.GetPos());
  ASSERT_EQ(1, bat.Getid());
  ASSERT_FLOAT_EQ(0.15, bat.GetWeight());
  ASSERT_EQ('O', bat.GetType());
  ASSERT_EQ('*', bat.GetLegend());
  Bat bat_2(1.2, make_pair(13,7));
  ASSERT_EQ("BT", bat_2.GetID());
  ASSERT_EQ(make_pair(13,7), bat_2.GetPos());
  ASSERT_EQ(2, bat_2.Getid());
  ASSERT_FLOAT_EQ(1.2, bat_2.GetWeight());
  ASSERT_EQ('O', bat_2.GetType());
  ASSERT_EQ('*', bat_2.GetLegend());
}
