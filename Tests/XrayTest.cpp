/**
 * @file XrayTest.cpp
 * @author Keerthi Vardhan
 */

#include <pch.h>
#include "gtest/gtest.h"


#include <NumberD.h>
#include <Xray.h>
#include <Game.h>
#include <XrayManip.h>

#include <memory>

using namespace std;

class XrayMock : public Xray
{
public:
    XrayMock(Game *game) : Xray(game)  { Xray::SetCap(3); }
};

class NumberMock : public NumberD
{
public:
    NumberMock(Game *game) : NumberD(game) {}
    NumberD* GetT() {return NumberD::GetThis();}

};

TEST(XrayTest, AddTest)
{
    // Check if items added to xray are working as intended

    Game g;
    Game* game = &g;

    shared_ptr<Item> xray;
    shared_ptr<XrayMock> curr= make_shared<XrayMock>(game);
    shared_ptr<NumberMock> numberA = make_shared<NumberMock>(game);
    NumberD* numA = numberA->GetT();

    game->Load("levels/testlevel.xml", 0);

    xray = curr;
    game->Add(xray, 100, 100);

    ASSERT_FALSE(curr->IsFull());

    curr->AddItem(numA);

    shared_ptr<NumberMock> numberB = make_shared<NumberMock>(game);
    NumberD* numB = numberB->GetT();

    curr->AddItem(numB);

    shared_ptr<NumberMock> numberC = make_shared<NumberMock>(game);
    NumberD* numC = numberC->GetT();

    curr->AddItem(numC);

    ASSERT_TRUE(curr->IsFull());
}

