# Write your MySQL query statement below
select m.name from Employee e, Employee m
where m.id = e.managerId 
group by m.id
having count(*) >= 5;