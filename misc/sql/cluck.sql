/* Create the database schema */
CREATE DATABASE cluck; USE cluck;
CREATE TABLE pets (
  name VARCHAR(20),
  owner VARCHAR(20),
  species VARCHAR(20),
  sex CHAR(1),
  birth DATE,
  death DATE
);
CREATE TABLE events (
  name VARCHAR(20),
  date DATE,
  type VARCHAR(15),
  remark VARCHAR(255)
);

/* pets table */
LOAD DATA LOCAL INFILE 'pets.csv' REPLACE INTO TABLE pets
  FIELDS TERMINATED BY ','
  IGNORE 1 LINES;
INSERT INTO pets VALUES(
  'Puffball',
  'Diane',
  'hamster',
  'f',
  '1999-03-30',
  NULL
);

/* events table */
LOAD DATA LOCAL INFILE 'events.csv' REPLACE INTO TABLE events
  FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY ''''
  IGNORE 1 LINES;
