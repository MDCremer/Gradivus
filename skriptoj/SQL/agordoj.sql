PRAGMA auto_vacuum=1;
PRAGMA page_size=4096;
PRAGMA synchronous=NORMAL;
PRAGMA temp_store=MEMORY;

CREATE TABLE IF NOT EXISTS agordoj
{nomo TEXT NOT NULL PRIMARY KEY,
 valoro TEXT NOT NULL
};

INSERT OR IGNORE INTO agordoj (nomo,valoro) VALUES ('nomo','anonimo');
INSERT OR IGNORE INTO agordoj (nomo,valoro) VALUES ('lingvo','');
