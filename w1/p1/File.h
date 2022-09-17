#ifndef _SDDS_FILE_H_
#define _SDDS_FILE_H_

#include "ShoppingRec.h"

namespace sdds
{

    bool openFileForRead();
    bool openFileForOverwrite();
    void closeFile();
    bool freadShoppingRec(ShoppingRec* rec);
    void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif 