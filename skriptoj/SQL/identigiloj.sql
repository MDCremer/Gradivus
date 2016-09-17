CREATE TABLE IF NOT EXISTS identigiloj
(lando CHAR(2) NOT NULL,
 nomo TEXT NOT NULL,
 lingvo CHAR(2) NOT NULL,
 citajxo TEXT,
 referenco TEXT,
 uuid TEXT NOT NULL,
 subskribon TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(lando,nomo,lingvo)
);

CREATE INDEX IF NOT EXISTS markoj ON identigiloj (lando,nomo);
CREATE INDEX IF NOT EXISTS identigiloj_uuid ON identigiloj (uuid);