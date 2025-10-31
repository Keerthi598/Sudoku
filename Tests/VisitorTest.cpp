/**
 * @file VisitorTest.cpp
 * @author Keerthi Vardhan
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Game.h>
#include <Background.h>
#include <SpecialContainer.h>
#include <NumberG.h>
#include <NumberD.h>
#include <ItemVisitor.h>


class TestVisitor : public ItemVisitor
{
public:
    int mBgNum = 0;
    int mSpConNum = 0;
    int mGNum = 0;
    int mDNum = 0;

    void VisitBackground(Background* background) override {mBgNum++;}
    void VisitSpecialContainer(SpecialContainer* spCont) override {mSpConNum++;}
    void VisitGiven(NumberG* given) override {mGNum++;}
    void VisitDigit(NumberD* digit) override {mDNum++;}
};

TEST(VisitorTest, Visitor)
{
    // Check if visitor works

    Game game;

    game.Load("levels/level0.xml", 0);

    TestVisitor visitor;
    game.Accept(&visitor);

    ASSERT_EQ(visitor.mBgNum, 1);
    ASSERT_EQ(visitor.mSpConNum, 0);
    ASSERT_EQ(visitor.mGNum, 81); //Include all digits
    ASSERT_EQ(visitor.mDNum, 12);

    game.Clear();

    game.Load("levels/level2.xml", 0);

    TestVisitor visitorA;
    game.Accept(&visitorA);

    ASSERT_EQ(visitorA.mBgNum, 2);
    ASSERT_EQ(visitorA.mSpConNum, 2);
    ASSERT_EQ(visitorA.mGNum, 81); //Includes all digits
    ASSERT_EQ(visitorA.mDNum, 47);
}
