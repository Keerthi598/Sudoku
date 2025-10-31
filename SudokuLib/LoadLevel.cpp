/**
 * @file LoadLevel.cpp
 * @author Keerthi Vardhan
 */

#include "pch.h"

#include "LoadLevel.h"
#include "Item.h"
#include "Background.h"
#include "NumberG.h"
#include "Xray.h"
#include "NumberD.h"
#include "PlayableArea.h"
#include "SpecialContainer.h"

#include "Vault.h"
#include "Game.h"

#include <vector>
#include <string>


using namespace std;


/**
 * Constructor and load the level
 * @param doc Level document
 * @param game Game
 */
LoadLevel::LoadLevel(wxXmlDocument* doc, Game* game)
{
    mDoc = doc;
    mGame = game;

    auto root = mDoc->GetRoot();

    Load(root);

}

/**
 * Load the level
 * @param root
 */
void LoadLevel::Load(wxXmlNode* root)
{
    auto decRoot = root->GetChildren();

    if (!decRoot)
        return;

    auto decNode = decRoot->GetChildren();

    for( ; decNode; decNode=decNode->GetNext())
    {
        LoadDec(decNode);
    }

    //End of declarations

    auto solutionRoot = decRoot->GetNext();

    shared_ptr<PlayableArea> playableArea = make_shared<PlayableArea>(mGame);
    mGame->SetPlayableArea(playableArea);
    playableArea->XmlLoad(solutionRoot);

    //Playable area solution

    auto itemRoot = solutionRoot->GetNext();

    auto itemNode = itemRoot->GetChildren();

    for( ; itemNode; itemNode=itemNode->GetNext())
    {
        LoadItem(itemNode);
    }

    //End of items

}

/**
 * Create and store declarations
 * @param decNode
 */
void LoadLevel::LoadDec(wxXmlNode *decNode)
{
    shared_ptr<Declaration> dec;

    long width, height;
    wstring id, image;

    id = decNode->GetAttribute(L"id").ToStdWstring();
    image = decNode->GetAttribute(L"image", L"").ToStdWstring();

    decNode->GetAttribute(L"width", L"0").ToLong(&width);
    decNode->GetAttribute(L"height", L"0").ToLong(&height);

    if( decNode->GetName() == L"background" )
        dec = make_shared<Declaration>(int(width), int(height), image);

    else if( decNode->GetName() == L"given" || decNode->GetName() == L"digit" )
    {
        int value;
        decNode->GetAttribute(L"value", L"0").ToInt(&value);
        dec = make_shared<DeclarationNum>(int(width), int(height), image, value);
    }

    else if( decNode->GetName() == L"xray")
    {
        int capacity;
        decNode->GetAttribute(L"capacity").ToInt(&capacity);
        dec = make_shared<DeclarationXray>(int(width), int(height), image, capacity);
    }

    else if( decNode->GetName() == L"container" )
    {
        wstring front = decNode->GetAttribute(L"front").ToStdWstring();
        dec = make_shared<DeclarationContainer>(int(width), int(height), image, front);
    }

    else if( decNode->GetName() == L"vault")
    {
        wstring front, leverImage, bulbImage;

        int leverWidth, leverHeight, bulbWidth, bulbHeight;
        std::vector<int> leverDimensions, bulbDimensions;

        front = decNode->GetAttribute(L"front").ToStdWstring();

        leverImage = decNode->GetAttribute(L"leverImage").ToStdWstring();
        bulbImage = decNode->GetAttribute(L"bulbImage").ToStdWstring();

        decNode->GetAttribute(L"leverWidth").ToInt(&leverWidth);
        decNode->GetAttribute(L"leverHeight").ToInt(&leverHeight);
        decNode->GetAttribute(L"bulbWidth").ToInt(&bulbWidth);
        decNode->GetAttribute(L"bulbHeight").ToInt(&bulbHeight);

        leverDimensions.push_back(leverWidth);
        leverDimensions.push_back(leverHeight);

        bulbDimensions.push_back(bulbWidth);
        bulbDimensions.push_back(bulbHeight);

        dec = make_shared<DeclarationVault>(int(width), int(height), image, front,
                                            leverImage, leverDimensions,
                                            bulbImage, bulbDimensions);
    }

    else if( decNode->GetName() == L"sparty" )
    {

        int front, tx, ty;
        double hpa, hpx, hpy, mpa, mpx, mpy;
        wstring imgA, imgB;

        decNode->GetAttribute(L"front").ToInt(&front);

        decNode->GetAttribute(L"head-pivot-angle").ToDouble(&hpa);
        decNode->GetAttribute(L"head-pivot-x").ToDouble(&hpx);
        decNode->GetAttribute(L"head-pivot-y").ToDouble(&hpy);

        imgA = decNode->GetAttribute(L"image1").ToStdWstring();
        imgB = decNode->GetAttribute(L"image2").ToStdWstring();

        decNode->GetAttribute(L"mouth-pivot-angle").ToDouble(&mpa);
        decNode->GetAttribute(L"mouth-pivot-x").ToDouble(&mpx);
        decNode->GetAttribute(L"mouth-pivot-y").ToDouble(&mpy);

        decNode->GetAttribute(L"target-x").ToInt(&tx);
        decNode->GetAttribute(L"target-y").ToInt(&ty);

        vector<int> target;
        vector<double> pivot;
        vector<wstring> images;

        target.push_back(front);
        target.push_back(tx);
        target.push_back(ty);

        pivot.push_back(hpa);
        pivot.push_back(hpx);
        pivot.push_back(hpy);
        pivot.push_back(mpa);
        pivot.push_back(mpx);
        pivot.push_back(mpy);

        images.push_back(imgA);
        images.push_back(imgB);

        dec = make_shared<DeclarationSparty>(int(width), int(height), target, pivot, images);

    }

    mDecMap[id] = dec;

}


/**
 * Load the item using declarations
 * @param itemNode
 */
void LoadLevel::LoadItem(wxXmlNode *itemNode)
{
    shared_ptr<Item> item;
    double column, row;

    wstring id = itemNode->GetAttribute(L"id").ToStdWstring();
    itemNode->GetAttribute(L"col", L"0").ToDouble(&column);
    itemNode->GetAttribute(L"row", L"0").ToDouble(&row);

    auto dec = mDecMap[id];

    if (dec.get() == nullptr)
        return;

    if( itemNode->GetName() == L"background" )
    {
        item = make_shared<Background>(mGame);
        item->XmlLoad(dec);
    }

    else if( itemNode->GetName() == L"given" )
    {
        item = make_shared<NumberG>(mGame);
        item->XmlLoad(dec);
    }

    else if( itemNode->GetName() == L"digit" )
    {
        item = make_shared<NumberD>(mGame);
        item->XmlLoad(dec);
    }

    else if( itemNode->GetName() == L"xray")
    {
        item = make_shared<Xray>(mGame);
        item->XmlLoad(dec);
    }

    else if( itemNode->GetName() == L"sparty" )
    {
        item = make_shared<Sparty>(mGame);
        item->XmlLoad(dec);
    }

    else if( itemNode->GetName() == L"container" )
    {
        auto container = make_shared<SpecialContainer>(mGame);

        container->XmlLoad(dec);

        LoadContainer(itemNode, container);

        item = container;
    }

    else if ( itemNode->GetName() == L"vault")
    {
        auto vault = make_shared<Vault>(mGame);

        vault->XmlLoad(dec);

        LoadVault(itemNode, vault);

        item = vault;
    }

    else
        return;


    mGame->Add(item, column, row);
}

/**
 * Add items into container
 * @param containerNode The xml node of the container
 * @param container The container
 */
void LoadLevel::LoadContainer(wxXmlNode *containerNode, std::shared_ptr<SpecialContainer> container)
{
    auto itemNode = containerNode->GetChildren();

    for( ; itemNode; itemNode=itemNode->GetNext())
    {
        shared_ptr<Item> item;
        double column, row;

        wstring id = itemNode->GetAttribute(L"id").ToStdWstring();
        itemNode->GetAttribute(L"col", L"0").ToDouble(&column);
        itemNode->GetAttribute(L"row", L"0").ToDouble(&row);

        auto dec = mDecMap[id];

        auto curr = make_shared<NumberD>(mGame);
        curr->SetContainer(container.get());

        curr->XmlLoad(dec);

        container->Add(curr);

        item = curr;


        mGame->Add(item, column, row);
    }

}

void LoadLevel::LoadVault(wxXmlNode *containerNode, std::shared_ptr<Vault> vault)
{
    // Need to implement this function
}
