# Write your MySQL query statement below
WITH temp AS (SELECT
    name,
    salary,
    departmentid,
    DENSE_RANK() OVER (PARTITION BY departmentid ORDER BY salary DESC) as top_salary_order
FROM Employee)

SELECT 
    d.name as Department,
    t.name as Employee,
    t.salary AS Salary
FROM temp t
JOIN department d ON d.id = t.departmentid
WHERE top_salary_order <= 3
;