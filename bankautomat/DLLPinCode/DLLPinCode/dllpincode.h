#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "DLLPinCode_global.h"
#include <QString>
#include "dialog.h"

class DLLPinCode
{
public:
    DLLPinCode();
    void DLLPINCODE_EXPORT openDllDialog();
    QString DLLPINCODE_EXPORT returnFromDll();
private:
    Dialog *objectDialog;
    QString dllValue;
};

#endif // DLLPINCODE_H
