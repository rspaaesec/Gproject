-- Gproject: skema awal (MySQL 8 / MariaDB). Aman dijalankan ulang.
-- Import: mysql -u root gproject < gamemodes/database/001_init.sql
CREATE TABLE IF NOT EXISTS schema_migrations (
  version VARCHAR(32) NOT NULL,
  applied_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (version)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
CREATE TABLE IF NOT EXISTS accounts (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  username VARCHAR(24) NOT NULL,
  password_hash VARCHAR(255) NOT NULL,
  email VARCHAR(100) NULL,
  admin_level TINYINT UNSIGNED NOT NULL DEFAULT 0,
  registered_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  last_login_at DATETIME NULL,
  last_ip VARCHAR(45) NULL,
  PRIMARY KEY (id),
  UNIQUE KEY uq_accounts_username (username)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
CREATE TABLE IF NOT EXISTS characters (
  id INT UNSIGNED NOT NULL AUTO_INCREMENT,
  account_id INT UNSIGNED NOT NULL,
  name VARCHAR(24) NOT NULL,
  gender TINYINT UNSIGNED NOT NULL DEFAULT 0,
  age TINYINT UNSIGNED NOT NULL DEFAULT 18,
  skin_id SMALLINT UNSIGNED NOT NULL DEFAULT 0,
  cash INT NOT NULL DEFAULT 0,
  bank INT NOT NULL DEFAULT 0,
  pos_x FLOAT NOT NULL DEFAULT 0,
  pos_y FLOAT NOT NULL DEFAULT 0,
  pos_z FLOAT NOT NULL DEFAULT 0,
  pos_angle FLOAT NOT NULL DEFAULT 0,
  interior_id INT UNSIGNED NOT NULL DEFAULT 0,
  world_id INT UNSIGNED NOT NULL DEFAULT 0,
  health FLOAT NOT NULL DEFAULT 100,
  armour FLOAT NOT NULL DEFAULT 0,
  created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  last_played_at DATETIME NULL,
  PRIMARY KEY (id),
  UNIQUE KEY uq_characters_name (name),
  KEY idx_characters_account (account_id),
  CONSTRAINT fk_characters_account FOREIGN KEY (account_id)
    REFERENCES accounts (id) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
INSERT IGNORE INTO schema_migrations (version) VALUES ('001_init');