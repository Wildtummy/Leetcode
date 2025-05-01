# Write your MySQL query statement below
select u.unique_id,i.name from Employees i left join EmployeeUNI u on i.id=u.id