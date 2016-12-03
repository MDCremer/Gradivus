CREATE TABLE IF NOT EXISTS priskriboj
(uuid CHAR(22) NOT NULL,
 lingvo CHAR(2) NOT NULL,
 teksto BLOB NOT NULL,
 subskribo TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(uuid,lingvo),
 FOREIGN KEY(lingvo) REFERENCES lingvoj(mallongigo)
);
