# Write your MySQL query statement below
Select firstName,lastName,city,state From Person as P LEFT JOIN Address as A ON P.personId = A.personId