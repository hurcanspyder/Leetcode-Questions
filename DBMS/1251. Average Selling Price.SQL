SELECT 
    pr.product_id,
    ROUND(IFNULL(SUM(pr.price * un.units) / SUM(un.units), 0), 2) AS average_price
FROM Prices pr
LEFT JOIN UnitsSold un
ON pr.product_id = un.product_id
AND un.purchase_date BETWEEN pr.start_date AND pr.end_date
GROUP BY pr.product_id;
-- ✅ 3. Date Condition in JOIN (Not WHERE)

-- If you put date condition in WHERE:

-- 👉 LEFT JOIN becomes INNER JOIN again ❌

-- So we move it into: