PRAGMA auto_vacuum=1;
PRAGMA synchronous=NORMAL;
PRAGMA temp_store=MEMORY;
PRAGMA journal_mode=MEMORY;

CREATE TABLE IF NOT EXISTS agordoj
(nomo TEXT NOT NULL PRIMARY KEY,
 valoro TEXT NOT NULL
);

BEGIN;
INSERT OR IGNORE INTO agordoj (nomo,valoro) VALUES ('nomo','anonimo');
INSERT OR IGNORE INTO agordoj (nomo,valoro) VALUES ('lingvo','');
INSERT OR IGNORE INTO agordoj (nomo,valoro) VALUES ('pasvorto','');
INSERT OR IGNORE INTO agordoj (nomo,valoro) VALUES ('transdono adreso','http://contribute.gradivus.de/upload.php');
INSERT OR IGNORE INTO agordoj (nomo,valoro) VALUES ('vortaro','http://lexikon.gradivus.de/');
COMMIT;