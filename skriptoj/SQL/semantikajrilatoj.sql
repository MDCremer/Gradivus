CREATE TABLE IF NOT EXISTS semantikajrilatoj
(subjekto CHAR(22) NOT NULL,
 rilato INTEGER NOT NULL,
 objekto CHAR(22) NOT NULL,
 PRIMARY KEY(subjekto,rilato,objekto)
);
