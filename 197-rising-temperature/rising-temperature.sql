SELECT W1.id
FROM Weather W1
LEFT JOIN Weather W2
ON DATEDIFF(W1.recordDate, W2.recordDate) = 1
WHERE W2.temperature IS NOT NULL AND W1.temperature > W2.temperature