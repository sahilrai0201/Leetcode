SELECT 
    S.user_id,
    ROUND(
        IFNULL(
            SUM(C.action = 'confirmed') / NULLIF(COUNT(*), 0),
            0
        ),
        2
    ) AS confirmation_rate
FROM Signups S
LEFT JOIN Confirmations C
ON S.user_id = C.user_id
GROUP BY S.user_id;