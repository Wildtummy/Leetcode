# Write your MySQL query statement below
select person_name from (select person_name, sum(weight)over(order by turn) as w ,turn from queue) t
where w<=1000 order by turn desc limit 1