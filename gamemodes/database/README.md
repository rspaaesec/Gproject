# Database Gproject

## Cara Import

Pastikan database `gproject` sudah dibuat, lalu jalankan:

```
C:\laragon\bin\mysql\mysql-8.0.30-winx64\bin\mysql.exe -u root gproject < gamemodes/database/001_init.sql
```

## Aturan Migrasi

- Setiap perubahan skema ditulis sebagai file baru bernomor urut:
  `002_*.sql`, `003_*.sql`, dst.
- Setiap file harus **idempotent** (`IF NOT EXISTS`, `INSERT IGNORE`, dll.)
  sehingga aman dijalankan ulang.
- **Jangan mengedit file yang sudah di-import** ke database manapun.
- **Tanpa `DROP TABLE` atau `TRUNCATE`** kecuali ada konfirmasi eksplisit.
- **Tanpa password, token, atau data pribadi** di dalam file `.sql`.