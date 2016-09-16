CREATE TABLE IF NOT EXISTS identigiloj
(lando CHAR(2) NOT NULL,
 nomo TEXT NOT NULL,
 lingvo CHAR(2) NOT NULL,
 citajxo TEXT,
 referenco TEXT,
 objekto INTEGER NOT NULL,
 subskribon TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(lando,nomo,lingvo)
);
