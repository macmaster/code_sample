#########################################################
# roster.py
# Parses json student course data
# Creates an sqlite Database of students and courses
#
# Author: Ronny Macmaster
# Date 3/17/2016
#########################################################

import json
import sqlite3

# Create Student Database
conn = sqlite3.Connection("roster.sqlite")
c = conn.cursor()


# Table Creation
c.executescript('''
DROP TABLE IF EXISTS User;
DROP TABLE IF EXISTS Member;
DROP TABLE IF EXISTS Course;

CREATE TABLE User(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    name TEXT UNIQUE
);

CREATE TABLE Course(
    id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    title TEXT UNIQUE
);


CREATE TABLE Member(
    user_id INTEGER,
    course_id INTEGER,
    role INTEGER,
    PRIMARY KEY (user_id, course_id)
);                                                  ''')

# Load json data
str_data = open("roster_data.json").read()
json_data = json.loads(str_data)

# Parse sql fields from json
# [name, course, role]
for entry in json_data:
    
    # User fields
    name = entry[0]
    title = entry[1]
    role = entry[2]
    
    # Add user
    c.execute('''
    INSERT OR IGNORE INTO User (name) VALUES (?)''', (name,))
    c.execute('''
    SELECT id FROM User WHERE name = ?''', (name,))
    user_id = c.fetchone()[0]
    
    # Add Course
    c.execute('''
    INSERT OR IGNORE INTO Course (title) VALUES (?)''', (title,))
    c.execute('''
    SELECT id FROM Course WHERE title = ?''', (title,))
    course_id = c.fetchone()[0]
    
    # Add Member
    c.execute('''
    INSERT INTO Member (user_id, course_id, role) 
    VALUES (?,?,?)''', (user_id, course_id, role))
    
    print name, title, role


# Close and Save Database
c.close()
conn.commit()
conn.close()
