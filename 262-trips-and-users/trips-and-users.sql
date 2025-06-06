# Write your MySQL query statement below
with k as (
    select * from users where banned='No'
)
select request_at as Day, round(avg(status!='completed'),2) as `Cancellation Rate` 
from trips where (client_id in (select users_id from k) )and (driver_id in (select users_id from k) ) and 
right(request_at,1) in ('1','2','3')
group by request_at