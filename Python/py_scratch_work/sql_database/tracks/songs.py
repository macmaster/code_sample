#########################################################
# songs.py
# Parses xml tracks data
# Creates an sqlite Database of songs 
#
# Author: Ronny Macmaster
# Date 3/17/2016
#########################################################

import xml.etree.ElementTree as et
import sqlite3

# Create Song Database
conn = sqlite3.Connection("songs.sqlite")
c = conn.cursor()

# Table Creation
c.executescript('''
DROP TABLE IF EXISTS Artist;
DROP TABLE IF EXISTS Album;
DROP TABLE IF EXISTS Genre;
DROP TABLE IF EXISTS Track;

CREATE TABLE Artist(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    name TEXT UNIQUE
);

CREATE TABLE Album(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    artist_id INTEGER,
    title TEXT UNIQUE
);

CREATE TABLE Genre(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    name TEXT UNIQUE
);

CREATE TABLE Track(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    title TEXT UNIQUE,
    album_id INTEGER,
    genre_id INTEGER,
    len INTEGER,
    rating INTEGER,
    count INTEGER
);                                                  ''')


# Function to lookup XML keys
# return text of subsequent element
def lookup(path, key):
    found = False
    for child in path:
        if found == True: return child.text
        if child.tag == "key" and child.text == key:
            found = True
    return None


# Parse xml song tree
tree = et.parse("Library.xml")
root = tree.getroot()

# Tracks dictionary
tracks = root.findall("dict/dict/dict")
for song in tracks:
    if lookup(song, "Track ID") is None: continue

    # Parse song fields
    name = lookup(song, "Name")
    artist = lookup(song, "Artist")
    album = lookup(song, "Total Time")
    genre = lookup(song, "Genre")
    length = lookup(song, "Album")
    rating = lookup(song, "Rating")
    count = lookup(song, "Play Count")

    if name is None or artist is None or \
       album is None or genre is None: continue

    print name, artist, album, genre

    # Add Artist
    c.execute('''
    INSERT OR IGNORE INTO Artist (name) VALUES (?)''', (artist,))
    c.execute('''
    SELECT id FROM Artist WHERE name = ?''', (artist,))
    artist_id = c.fetchone()[0]

    # Add Album
    c.execute('''
    INSERT OR IGNORE INTO Album (title, artist_id) VALUES (?,?)''', (album,artist_id))
    c.execute('''
    SELECT id FROM Album WHERE title = ?''', (album,))
    album_id = c.fetchone()[0]

    # Add Genre
    c.execute('''
    INSERT OR IGNORE INTO Genre (name) VALUES (?)''', (genre,))
    c.execute('''
    SELECT id FROM Genre WHERE name = ?''', (genre,))
    genre_id = c.fetchone()[0]


# Close Database
c.close()
conn.commit()
conn.close()
