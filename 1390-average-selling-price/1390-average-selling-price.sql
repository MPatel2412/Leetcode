# Write your MySQL query statement below
select p.product_id, IFNULL(ROUND(SUM(units*price)/SUM(units),2),0) AS average_price
FROM Prices p LEFT JOIN UnitsSold u ON p.product_id = u.product_id AND u.purchase_date between p.start_date AND p.end_date
GROUP BY p.product_id