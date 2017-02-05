CREATE TABLE IF NOT EXISTS modeloj
(uuid CHAR(22) NOT NULL,
 jaro INT NOT NULL,
 pezo REAL NOT NULL,
 pezofluktuo INT NOT NULL,
 prezo REAL NOT NULL,
 utilavivo INT NOT NULL,
 utilavivofluktuo INT NOT NULL,
 fontoj CHAR(12) NOT NULL,
 subskribo TEXT NOT NULL,
 stato INTEGER NOT NULL,
 PRIMARY KEY(uuid,jaro)
);
