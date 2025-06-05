# Write your MySQL query statement below
select distinct s.user_id, round(avg(CASE WHEN action = 'confirmed' THEN 1 ELSE 0 END) over(partition by user_id ),2) as confirmation_rate from 
signups s 
left join 
confirmations c
on c.user_id=s.user_id
