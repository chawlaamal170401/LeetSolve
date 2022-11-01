# Write your MySQL query statement below
select ifnull((select distinct salary 
from Employee
order by salary desc Limit 1, 1), null) as SecondHighestSalary