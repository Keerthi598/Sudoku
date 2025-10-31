project(SudokuLib)

set(SOURCE_FILES pch.h Mainframe.h Mainframe.cpp GameView.cpp GameView.h
        Game.cpp
        Game.h
        Item.cpp
        Item.h
        Background.cpp
        Background.h
        Declaration.cpp
        Declaration.h
        ids.h
        Sparty.cpp
        NumberG.cpp
        NumberG.h
        LoadLevel.cpp
        LoadLevel.h
        DeclarationNum.cpp
        DeclarationNum.h
        Container.cpp
        Container.h
        Xray.cpp
        Xray.h
        DeclarationXray.cpp
        DeclarationXray.h
        NumberD.cpp
        NumberD.h
        DeclarationSparty.cpp
        DeclarationSparty.h
        PlayableArea.cpp
        PlayableArea.h
        ScoreBoard.cpp
        ScoreBoard.h
        DeclarationContainer.cpp
        DeclarationContainer.h
        SpecialContainer.cpp
        SpecialContainer.h
        ItemVisitor.cpp
        ItemVisitor.h
        FindNumber.cpp
        FindNumber.h
        XrayManip.cpp
        XrayManip.h
        BoardNumber.cpp
        BoardNumber.h
        FindGivens.cpp
        FindGivens.h
        GameState.cpp
        GameState.h
        ScreenText.cpp
        ScreenText.h
        SolveVisitor.cpp
        SolveVisitor.h
        Vault.cpp
        Vault.h
        DeclarationVault.cpp
        DeclarationVault.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)