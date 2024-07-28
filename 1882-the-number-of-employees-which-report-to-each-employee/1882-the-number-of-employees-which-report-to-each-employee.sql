# Write your MySQL query statement below
select e.employee_id, e.name, count(m.employee_id) as reports_count, ROUND(AVG(m.age*1.00),0) as average_age
from Employees e, Employees m
where e.employee_id = m.reports_to
Group by e.employee_id, e.name
order by e.employee_id;