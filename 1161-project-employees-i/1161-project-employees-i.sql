# Write your MySQL query statement below
select p.project_id, ROUND(avg(experience_years),2) as average_years from Project p, Employee e
where p.employee_id = e.employee_id
Group by project_id;