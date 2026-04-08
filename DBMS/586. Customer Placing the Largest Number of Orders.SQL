SELECT Customer_number
FROM (
    SELECT Customer_number, COUNT(order_number) AS numord
    FROM Orders
    GROUP BY Customer_number
) AS W
ORDER BY numord DESC
LIMIT 1;