#include <ComponentBase.h>
#include <types.h>

#include "SampleAddIn.h"

#ifdef _WINDOWS
#pragma warning (disable : 4311 4302)
#endif

const WCHAR_T *GetClassNames() {
    // Might contain multiple class names seperated by |
    static char16_t cls_names[] = u"Sample";
    return reinterpret_cast<WCHAR_T *>(cls_names);
}

long GetClassObject(const WCHAR_T *clsName, IComponentBase **pInterface) {
    if (!*pInterface) {
        auto cls_name = std::u16string(reinterpret_cast<const char16_t *>(clsName));
        if (cls_name == u"Sample") {
            *pInterface = new SampleAddIn;
        }
        return (long) *pInterface;
    }
    return 0;
}

long DestroyObject(IComponentBase **pInterface) {
    if (!*pInterface) {
        return -1;
    }

    delete *pInterface;
    *pInterface = nullptr;
    return 0;
}

AppCapabilities SetPlatformCapabilities(const AppCapabilities capabilities) {
    return eAppCapabilitiesLast;
}
