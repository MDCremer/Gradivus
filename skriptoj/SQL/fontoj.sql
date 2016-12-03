CREATE TABLE IF NOT EXISTS fontoj
(uuid CHAR(22) NOT NULL,
 aludo CHAR(3) NOT NULL,
 literaturo TEXT,
 pagxo BLOB,
 subskribo TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(uuid,aludo),
 FOREIGN KEY(literaturo) REFERENCES literaturoj(aludo)
);
