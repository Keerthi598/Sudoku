/**
 * @file Declaration.h
 * @author Keerthi Vardhan
 *
 * The declaration class
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_DECLARATION_H
#define ACTIONSUDOKU_SUDOKULIB_DECLARATION_H

#include <vector>

/**
 * The declaration class holding the details of an item
 */
class Declaration
{
private:

    int mWidth;          ///<The width
    int mHeight;         ///<The height
    std::wstring mImage; ///<The image filename


public:
    Declaration(int width, int height, std::wstring image);

    /**
     * Get the width
     * @return width
     */
    int GetWidth() { return mWidth; }

    /**
     * Get the height
     * @return height
     */
    int GetHeight() { return mHeight; }

    /**
     * Get the image
     * @return image
     */
    std::wstring GetImage() { return mImage; }

    /**
     * Return value if exists
     * @return value
     */
    virtual int GetValue() { return 0; }

    /**
     * Return capacity if exists
     * @return
     */
    virtual int GetCap() { return 0; }

    /**
     * Get the target ints for sparty
     * @return vector of target points
     */
    virtual std::vector<int> GetTarget() { return std::vector<int> {}; }

    /**
     * Get the pivot values for sparty
     * @return vector of pivot points
     */
    virtual std::vector<double> GetPivot() { return std::vector<double> {}; }

    /**
     * Return sparty images
     * @return
     */
    virtual std::vector<std::wstring> GetImages() {return std::vector<std::wstring> {};}

    /**
     * Return front image
     * @return image
     */
    virtual std::wstring GetFront() { return L""; }


    /**
     * Return lever image
     * @return image
     */
     virtual std::wstring GetLeverImage() { return L""; }

     /**
      * Return bulb image
      * @return image
      */
     virtual std::wstring GetBulbImage() { return L""; }


     /**
      * Get lever width and height
      * @return vector of lever width and height in pixels
      */
      virtual std::vector<int> GetLeverDimensions() { return std::vector<int> {}; }

     /**
      * Get bulb width and height
      * @return vector of bulb width and height in pixels
      */
      virtual std::vector<int> GetBulbDimensions() { return std::vector<int> {}; }




};

#endif //ACTIONSUDOKU_SUDOKULIB_DECLARATION_H
