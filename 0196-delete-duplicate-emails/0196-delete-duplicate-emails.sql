# Write your MySQL query statement below
DELETE p from Person p, person e 
where p.email = e.email AND p.id > e.id;