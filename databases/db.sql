create table player (name text, number int);

insert into player (name, number) values
  ('Larry Smith', 23),
  ('David Gonzalez', 12),
  ('George Rogers', 7),
  ('Mike Lee', 14),
  ('Rajiv Williams', 55);

create table stats (number int, totalPoints int, year text);

insert into stats (number, totalPoints, year) values
  (7, 59, 'Freshman'),
  (55, 90, 'Senior'),
  (23, 150, 'Senior'),
  (23, 221, 'Junior'),
  (55, 84, 'Junior');
