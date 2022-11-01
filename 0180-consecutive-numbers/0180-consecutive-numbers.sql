# Write your MySQL query statement below
select distinct l1.Num as ConsecutiveNums
From Logs l1, Logs l2, Logs l3
Where l1.id = l2.id - 1 and l2.id = l3.id - 1 and l1.Num = l2.Num and l2.Num = l3.Num