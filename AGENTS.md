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

## Struktur
- main.pwn hanya meng-include modul, tanpa logika.
- Satu sistem = satu folder di gamemodes/modules/<nama>/ (bukan modules/ di root).
- Konfigurasi server memakai config.json (open.mp), bukan server.cfg.
- Callback ditangani per modul lewat hooking (y_hooks),
  bukan ditumpuk di main.pwn.

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