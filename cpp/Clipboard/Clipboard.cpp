//
// Created by Klaksyn on 22.09.2026.
//

#include "../../header/Clipboard/Clipboard.h"
#include "../../header/helper/IO.hpp"

#include <windows.h>

void Clipboard::copy_text(const std::string &text) {
    if (!OpenClipboard(GetConsoleWindow())) {
        IO::perror("Failed to open Clipboard");
        return;
    }

    EmptyClipboard();

    HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, text.size() + 1);
    if (!hGlobal) {
        CloseClipboard();
        IO::perror("Failed to allocate memory for clipboard");
        return;
    }

    // We copy the text
    memcpy(GlobalLock(hGlobal), text.c_str(), text.size() + 1);
    GlobalUnlock(hGlobal);

    SetClipboardData(CF_TEXT, hGlobal);

    CloseClipboard();

    IO::psuccess("text successfully copied in clipboard");
}
