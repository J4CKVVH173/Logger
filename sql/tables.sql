CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY ,
    username TEXT,
    first_name TEXT,
    first_enter INTEGER,
    user_id INTEGER NOT NULL UNIQUE,
    language_code TEXT,
    chart_id INTEGER
);

CREATE TABLE IF NOT EXISTS board (
    id INTEGER PRIMARY KEY,
    board TEXT NOT NULL,
    users_id INTEGER NOT NULL UNIQUE,
    FOREIGN KEY (users_id) REFERENCES users(user_id)
);

CREATE TABLE IF NOT EXISTS feedback (
    id INTEGER PRIMARY KEY,
    users_id INTEGER NOT NULL,
    message TEXT,
    FOREIGN KEY (users_id) REFERENCES users(user_id)
);