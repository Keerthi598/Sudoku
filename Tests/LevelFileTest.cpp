/**
 * @file LevelFileTest.cpp
 * @author Keerthi Vardhan
 */

#include <pch.h>
#include "gtest/gtest.h"

#include <Game.h>


class LevelFileTest : public ::testing::Test
{

};




TEST_F(LevelFileTest, LoadLevel)
{
    // Check if number of item loaded is correct

    Game game;

    ///Test level 0
    game.Load("levels/level0.xml", 0);
    int num = game.ItemsLoaded();
    ASSERT_EQ(num, 84);
    game.Clear();
    ASSERT_EQ(0, game.ItemsLoaded());

    ///Test level 1
    game.Load("levels/level1.xml", 0);
    num = game.ItemsLoaded();
    ASSERT_EQ(num, 84);
    game.Clear();
    ASSERT_EQ(0, game.ItemsLoaded());

    ///Test level 2
    game.Load("levels/level2.xml", 0);
    num = game.ItemsLoaded();
    ASSERT_EQ(num, 87);
    game.Clear();
    ASSERT_EQ(0, game.ItemsLoaded());
}


