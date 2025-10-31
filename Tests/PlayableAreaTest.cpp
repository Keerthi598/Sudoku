/**
 * @file PlayableAreaTest.cpp
 * @author Keerthi Vardhan
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Game.h>
#include <PlayableArea.h>

#include <memory>

using namespace std;

class AreaMock : public PlayableArea
{
public:
    AreaMock(Game *game) : PlayableArea(game) {PlayableArea::SetPos(4, 3); }

    void Set() {PlayableArea::SetLoc();}

};

TEST(PlayableAreaTest, HitTest)
{
    // Check if the hit test for main playing area is working

    Game g;
    Game* game = &g;

    game->Load("levels/testlevel.xml", 0);

    auto curr = make_shared<AreaMock>(game);

    game->SetPlayableArea(curr);
    curr->Set();

    ASSERT_FALSE(curr->HitTest(0, 0));

    ASSERT_TRUE(curr->HitTest(300, 300)); //Random point in playable area

    ASSERT_TRUE(curr->HitTest(192, 144)); //Top Left Point

    ASSERT_TRUE(curr->HitTest(192, 576)); //Bottom Left Point

    ASSERT_FALSE(curr->HitTest(300, 577)); //Slightly under
}


TEST(PlayableArea, BoardCoordsTest)
{
    // Check if the clicked box on board in empty or full

    Game g;
    Game* game = &g;

    game->Load("levels/level1.xml", 0);

    auto curr = make_shared<AreaMock>(game);

    game->SetPlayableArea(curr);
    curr->Set();

    wxPoint a(200, 150);
    wxPoint b(300, 150);

    ASSERT_FALSE(curr->CheckBoard(a));   //Number exists
    ASSERT_TRUE(curr->CheckBoard(b));    //Empty box
}


TEST(PlayableArea, BoardMiddleCoordsTest)
{
    // Find the middle point of a box in the board

    Game g;
    Game* game = &g;

    game->Load("levels/level1.xml", 0);

    auto curr = make_shared<AreaMock>(game);

    game->SetPlayableArea(curr);
    curr->Set();

    wxPoint a(200, 150);
    wxPoint b(300, 150);

    auto aP = curr->GetBoardCoords(a.x, a.y);

    ASSERT_TRUE(aP.x == 216);
    ASSERT_TRUE(aP.y == 168);

    auto bP = curr->GetBoardCoords(b.x, b.y);

    ASSERT_TRUE(bP.y == 168);
    ASSERT_TRUE(bP.x == 312);

}