SELECT w.seat_id
FROM (SELECT * , LEAD(free) OVER(ORDER BY seat_id) AS Next_seat, LAG(free) OVER(ORDER BY seat_id) AS Prev_seat
FROM Cinema) AS w
WHERE w.free=1 AND w.Next_seat=1
OR w.free=1 AND w.Prev_seat=1
ORDER by w.seat_id