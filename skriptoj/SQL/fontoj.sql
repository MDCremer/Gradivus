CREATE TABLE IF NOT EXISTS fontoj
(uuid TEXT NOT NULL,
 aludo CHAR(3) NOT NULL,
 literaturo TEXT,
 pagxo BLOB,
 subskribo TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(uuid,aludo)
);
