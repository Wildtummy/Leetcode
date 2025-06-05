# Write your MySQL query statement below
select  id   ,visit_date ,people from 
(select *,
lead(id,1) over (order by id )as f1,
lead(id,2) over (order by id ) as f2,
lag(id,1)  over (order by id )as b1,
lag(id,2) over (order by id )as b2
 from stadium where people>=100) t
 where 
 (b1=id-1 and b2=id-2) or
 (b1=id-1 and f1=id+1) or
 (f1=id+1 and f2=id+2) 

