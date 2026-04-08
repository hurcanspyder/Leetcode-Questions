SELECT MIN(ABS(p1.x-p2.x)) AS Shortest
FROM Point as p1

CROSS JOIN Point as p2
WHERE p1.x<>p2.x