# Aturan Proyek: Server SA-MP Roleplay (Pawn)

## Konteks
- Server roleplay (utama) + freeroam kecil sebagai pelengkap.
- Dibangun bertahap: satu sistem per tugas.

## Prinsip kerja
1. Kerjakan HANYA yang diminta pada tugas ini. Jangan menambah fitur lain.
2. Kode harus rapi dan mudah dibaca: nama jelas, fungsi pendek,
   komentar untuk logika yang tidak jelas.
3. JANGAN mengarang native atau fungsi. Jika tidak yakin sebuah
   fungsi ada, katakan terus terang agar saya cek dokumentasi.
4. Jangan mencampur sintaks SA-MP dan open.mp tanpa menyebutkannya.
5. Titik koma wajib di akhir setiap pernyataan.

## Struktur
- main.pwn hanya meng-include modul, tanpa logika.
- Satu sistem = satu folder di gamemodes/modules/<nama>/ (bukan modules/ di root).
- Konfigurasi server memakai config.json (open.mp), bukan server.cfg.
  - config.json adalah konfigurasi lokal — di-ignore Git, TIDAK di-commit.
  - config.example.json adalah template yang di-commit; berisi placeholder,
    bukan nilai nyata.
  - Sebelum server dibuka ke publik, password RCON di config.json lokal
    WAJIB diganti dari nilai bawaan.
  - Password apa pun (RCON, database, dll.) tidak boleh masuk ke repo.
- Callback ditangani per modul lewat hooking (y_hooks),
  bukan ditumpuk di main.pwn.

## Dependensi
- Kompilator: pawncc 3.10.11
- Library YSI: v5.10.0006 (pawn-lang/YSI-Includes), berlokasi di qawno/include/ (tidak di-commit ke Git).
- Plugin MySQL: BlueG mysql-plugin R41-4 (32-bit), DLL di plugins/ (tidak di-commit ke Git).
- Include MySQL: a_mysql.inc di qawno/include/ (tidak di-commit ke Git).
- Kredensial database hanya di mysql.ini yang di-ignore Git; jangan pernah menulis password di kode atau di AGENTS.md.
- Perintah kompilasi resmi:
  `pawncc gamemodes/main.pwn -i:qawno/include -o:gamemodes/main "-;+" -d3`

## Penamaan
- Fungsi: Modul_Aksi(), contoh Player_Login().
- Variabel global: prefiks g_. Data pemain: enum terpisah.
- Konstanta/macro: HURUF_BESAR. Tidak ada angka ajaib.

## Database
- Semua query memakai escape/parameter. Input mentah tidak
  boleh langsung masuk ke string query.
- Query dijalankan asynchronous (threaded).
- Password tidak disimpan polos: gunakan hash modern (mis. bcrypt).

## Stabilitas
- Validasi semua input pemain (ID, panjang string, rentang angka).
- Cek pemain terkoneksi dan sudah login sebelum aksi apa pun.
- Reset data pemain saat OnPlayerDisconnect.

## Definisi selesai
- Compile tanpa warning.
- Di akhir tugas, laporkan: file yang diubah, cara tes manual,
  dan risiko/batasan yang diketahui.
- Jangan mengubah file di luar lingkup tugas.
## Encoding
- Semua file teks proyek memakai UTF-8 TANPA BOM.
- Di PowerShell 5.x jangan memakai Set-Content atau Out-File dengan
  -Encoding UTF8 (menambahkan BOM). Gunakan:
  [System.IO.File]::WriteAllText(path, text, (New-Object System.Text.UTF8Encoding($false)))