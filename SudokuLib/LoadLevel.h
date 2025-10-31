/**
 * @file LoadLevel.h
 * @author Keerthi Vardhan
 *
 * Class that loads the levels into the game
 */

#ifndef ACTIONSUDOKU_SUDOKULIB_LOADLEVEL_H
#define ACTIONSUDOKU_SUDOKULIB_LOADLEVEL_H

#include <memory>
#include <unordered_map>

#include "Declaration.h"
#include "DeclarationNum.h"
#include "DeclarationXray.h"
#include "DeclarationVault.h"
#include "DeclarationSparty.h"
#include "DeclarationContainer.h"

class Game;
class SpecialContainer;
class Vault;


/**
 * Class that loads the levels
 */
class LoadLevel
{
private:

    Game *mGame;          ///< The game the level is being loaded into
    wxXmlDocument* mDoc;  ///< The level document

    /// Hashmap storing the ids with declarations
    std::unordered_map<std::wstring, std::shared_ptr<Declaration>> mDecMap;

    void Load(wxXmlNode* root);

    void LoadDec(wxXmlNode* decNode);

    void LoadItem(wxXmlNode *itemNode);

    void LoadContainer(wxXmlNode *containerNode, std::shared_ptr<SpecialContainer> container);

    void LoadVault(wxXmlNode  *containerNode, std::shared_ptr<Vault> vault);

public:
    LoadLevel(wxXmlDocument* doc, Game* game);


};

#endif //ACTIONSUDOKU_SUDOKULIB_LOADLEVEL_H
