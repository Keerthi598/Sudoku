/**
 * @file ScreenText.h
 * @author Keerthi Vardhan
 *
 * Class to display the texts on screen
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_SCREENTEXT_H
#define ACTIONSUDOKU_SUDOKULIB_SCREENTEXT_H

/**
 * Display appropriate text on screen
 */
class ScreenText
{
private:
    double mTime = 0;

    bool mIsCorrect = false;
    bool mInCorrect = false;

    bool mAdvanceLevel = false;


public:
    ScreenText() {}

    void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, double w, double h);

    void Update(double elapsed);

    bool Pause() {return mTime > 0;}

    bool AdvanceLevel();

    void IsCorrect() {mIsCorrect = true; mTime = 0.001;}

    void Incorrect() {mInCorrect = true; mTime = 0.001;}

    void LevelCompleteText(std::shared_ptr<wxGraphicsContext> graphics, double w, double h);

    void LevelIncorrectText(std::shared_ptr<wxGraphicsContext> graphics, double w, double h);

};

#endif //ACTIONSUDOKU_SUDOKULIB_SCREENTEXT_H
