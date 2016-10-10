CREATE TABLE IF NOT EXISTS identigiloj
(etno CHAR(2) NOT NULL,
 nomo TEXT NOT NULL,
 lingvo CHAR(2) NOT NULL,
 tipo INTEGER NOT NULL,
 citajxo TEXT,
 referenco BLOB,
 uuid TEXT NOT NULL,
 subskribo TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(etno,nomo,lingvo)
);

CREATE INDEX IF NOT EXISTS markoj ON identigiloj (etno,nomo);
CREATE INDEX IF NOT EXISTS identigiloj_uuid ON identigiloj (uuid);