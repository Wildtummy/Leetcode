# Write your MySQL query statement below
select name from employee
where id in(select managerID from employee group by managerID  having count(managerID)>=5 )