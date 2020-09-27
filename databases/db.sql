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

alter table player add primary key (number);
alter table stats add constraint fk_number foreign key(number) references player(number);

select name, totalPoints, year from player join stats on player.number = stats.number;
/* select name, totalPoints, year from player join stats using number; */
select name, totalPoints, year from player left join stats on player.number = stats.number;

select avg(totalPoints) from stats;

/* calc each player's avg total pts per year */
select
  name,
  avg(totalPoints)
from player
join stats
  on player.number = stats.number
group by name;

/* pg 214 CompanyName and EmployeesHired tables */
select companyName from Company join EmployeesHired on Company.id = EmployeesHired.id
where EmployeesHired.fiscalQuarter = 4 and numHired > 0;

select companyName from Company join EmployeesHired on Company.id = EmployeesHired.id
where id not in (select id from EmployeesHired where numHired > 0);

/* return the names of all companies and the total number of employees that each company hired during fiscal quarters 1 through 4. */
select coalesce(sum(numHired) 0)
from Company left join EmployeesHired
  on Company.id = EmployeesHired.id
group by companyName;
/* end pg 214 CompanyName and EmployeesHired tables */
