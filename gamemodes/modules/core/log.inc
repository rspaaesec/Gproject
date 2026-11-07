#if defined _CORE_LOG_INCLUDED
    #endinput
#endif
#define _CORE_LOG_INCLUDED

// =============================================================================
// Fungsi Logging
// =============================================================================

stock Log_Info(const text[])
{
#if CURRENT_LOG_LEVEL >= LOG_LEVEL_INFO
    printf("[INFO] %s", text);
#else
    #pragma unused text
#endif
    return 1;
}

stock Log_Warn(const text[])
{
#if CURRENT_LOG_LEVEL >= LOG_LEVEL_WARN
    printf("[WARN] %s", text);
#else
    #pragma unused text
#endif
    return 1;
}

stock Log_Error(const text[])
{
#if CURRENT_LOG_LEVEL >= LOG_LEVEL_ERROR
    printf("[ERROR] %s", text);
#else
    #pragma unused text
#endif
    return 1;
}
