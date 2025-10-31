/**
 * @file ScoreBoard.h
 * @author Keerthi Vardhan
 *
 * Scoreboard class
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
#define ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H

#include <string>

/**
 * Class to keep track of time
 */
class ScoreBoard
{
private:
    double mCurrTime = 0; ///< Current time

    bool mIsRunning = false; ///< Indicate if scoreboard has started

public:
    /// Constructor
    ScoreBoard() {};

    void Start();

    void Update(double elapsed);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    void Stop();

    /**
     * return true if scorboard is running
     * @return
     */
    bool IsRunning() {return mIsRunning;}

};

#endif //ACTIONSUDOKU_SUDOKULIB_SCOREBOARD_H
