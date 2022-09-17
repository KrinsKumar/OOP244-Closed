#ifndef _SDDS_UTILS_H_
#define _SDDS_UTILS_H_

namespace sdds
{
    void flushkeys();
    bool ValidYesResponse(char ch);
    bool yes();
    void readCstr(char cstr[], int len);
    int readInt(int min, int max);
}

#endif 