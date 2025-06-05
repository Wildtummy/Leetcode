# Write your MySQL query statement below
select Department, Employee,Salary 
from
(select d.name as Department ,e.name as Employee ,salary  as Salary 
,(dense_rank() over(partition by d.id order by e.salary desc )) as ds
from employee e  left join department d on e.departmentId = d.id) t
where ds<4