/* Write your PL/SQL query statement below */
select Department, Employee, Salary 
From (select d.name as Department, e.id as ID, e.name as Employee, e.salary as Salary, DENSE_RANK() OVER (PARTITION BY d.id ORDER by e.salary desc) as ranking FROM Employee e, Department d WHERE d.id = e.departmentId ORDER by d.id, e.salary) ED 
where ranking < 4;