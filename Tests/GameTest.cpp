/**
 * @file GameTest.cpp
 * @author Keerthi Vardhan
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Item.h>
#include <NumberD.h>
#include <Game.h>
#include <ScoreBoard.h>

#include <memory>

using namespace std;

class ItemVisitor;

class GameTest : public ::testing::Test
{
};

class GameMock : public Game
{
public:
    GameMock() : Game() {}

    wxPoint GetTarget() {return Game::GetSpartyTarget();}

    bool SpartyMoving() {return Game::SpartyMoving(); }

};

class ItemMock : public Item
{
public:
    ItemMock(Game* game) : Item(game) { Item::SetImage(L"background.png"); }

    void SetDim(double x, double y) { Item::SetWidth(x); Item::SetHeight(y);}
    void Accept(ItemVisitor* visitor) override {};
};

class NumberMock : public NumberD
{
public:
    NumberMock(Game *game) : NumberD(game) {Item::SetHeight(48); Item::SetWidth(48);}
};

TEST_F(GameTest, HitTest)
{
    // Hit test for items

    Game g;
    Game* game = &g;

    game->Load("levels/testlevel.xml", 0);

    auto curr = make_shared<ItemMock>(game);
    curr->SetDim(48, 48);

    game->Add(curr, 11, 4);

    ASSERT_EQ(curr->HitTest(0, 0), false);

    ASSERT_TRUE(curr->HitTest(528, 192)); //Top left

    ASSERT_TRUE(curr->HitTest(576, 240)); //Bottom Right

    ASSERT_FALSE(curr->HitTest(527, 210)); //Slightly to the left

    ASSERT_FALSE(curr->HitTest(550, 191)); //Slightly to the top
}

TEST_F(GameTest, SpartyMovement)
{
    // Check if sparty is moving when moved

    GameMock g;
    GameMock* game = &g;

    game->Load("levels/level1.xml", 0);

    auto target = game->GetTarget();   //Initial target

    ASSERT_EQ(target.x, 0);
    ASSERT_EQ(target.y, 0);

    game->Move(300, 300);

    auto newTarget = game->GetTarget();


    ASSERT_EQ(newTarget.x, 228); // New targets
    ASSERT_EQ(newTarget.y, 228);

    ASSERT_TRUE(game->SpartyMoving());

}

TEST_F(GameTest, ScoreBoard)
{
    // Check if the scoreboard class works

    ScoreBoard newScore;

    ASSERT_FALSE(newScore.IsRunning());
    newScore.Start();

    ASSERT_TRUE(newScore.IsRunning());
    newScore.Stop();

    ASSERT_FALSE(newScore.IsRunning());
}

TEST_F(GameTest, SpartyEatTest)
{
    // Check if eaten numbers are in a container (xray)

    GameMock g;
    GameMock* game = &g;

    game->Load("levels/testlevel.xml", 0);

    shared_ptr<NumberD> number = make_shared<NumberMock>(game);


    // Number at a location that can be eaten
    game->Add(number, 2.5, 11);


    number->SetImage(L"0b.png");

    // On board
    ASSERT_EQ(number->GetContainer(), nullptr);

    // Eat the number
    game->Eat();

    // Number should be in xray
    ASSERT_FALSE(number->GetContainer() == nullptr);

}