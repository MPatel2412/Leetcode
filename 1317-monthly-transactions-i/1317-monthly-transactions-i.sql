# Write your MySQL query statement below
select SUBSTR(trans_date,1,7) as month, country, count(*) as trans_count, SUM(CASE WHEN state like 'approved' Then 1 else 0 end) as approved_count, sum(amount) as trans_total_amount, sum(case when state like 'approved' Then amount else 0 end) as approved_total_amount
from Transactions
Group by month,country;
