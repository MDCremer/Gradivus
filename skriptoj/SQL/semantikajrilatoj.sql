CREATE TABLE IF NOT EXISTS semantikajrilatoj
(subjekto CHAR(22) NOT NULL,
 rilato INTEGER NOT NULL,
 objekto CHAR(22) NOT NULL,
 aludo CHAR(3),
 subskribo TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(subjekto,rilato,objekto),
 FOREIGN KEY(subjekto,aludo) REFERENCES fontoj(uuid,aludo)
);
