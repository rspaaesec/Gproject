// database.inc
// Koneksi ke database MySQL menggunakan plugin BlueG R41-4.
// open.mp sudah di-include lewat main.pwn.

#if defined _CORE_DATABASE_INCLUDED
    #endinput
#endif
#define _CORE_DATABASE_INCLUDED

#include <a_mysql>
#include <YSI_Coding\y_hooks>

// =============================================================================
// State
// =============================================================================

new MySQL:g_SQL = MYSQL_INVALID_HANDLE;
new bool:g_DatabaseReady = false;

// =============================================================================
// Forward
// =============================================================================

forward OnDatabasePing();

// =============================================================================
// API Publik
// =============================================================================

stock bool:Database_IsReady()
{
    return g_DatabaseReady;
}

stock Database_Init()
{
    mysql_log(ERROR | WARNING);

    g_SQL = mysql_connect_file("mysql.ini");

    new err = mysql_errno(g_SQL);
    if (err != 0)
    {
        new szErr[64];
        format(szErr, sizeof(szErr), "Database: koneksi gagal, kode error: %d", err);
        Log_Error(szErr);
        g_DatabaseReady = false;
        return;
    }

    g_DatabaseReady = true;
    Log_Info("Database: terhubung");

    mysql_tquery(g_SQL, "SELECT 1", "OnDatabasePing", "");
}

stock Database_Close()
{
    if (g_DatabaseReady)
    {
        mysql_close(g_SQL);
        g_DatabaseReady = false;
        Log_Info("Database: koneksi ditutup");
    }
}

// =============================================================================
// Hooks
// =============================================================================

hook OnGameModeInit()
{
    Database_Init();
    return 1;
}

hook OnGameModeExit()
{
    Database_Close();
    return 1;
}

// =============================================================================
// Callback async
// =============================================================================

public OnDatabasePing()
{
    Log_Info("Database: query async OK");
    return 1;
}