#if defined _CORE_LIFECYCLE_INCLUDED
    #endinput
#endif
#define _CORE_LIFECYCLE_INCLUDED

#include <YSI_Coding\y_hooks>

hook OnGameModeInit()
{
    Log_Info("Core: OnGameModeInit via y_hooks");
    return 1;
}
