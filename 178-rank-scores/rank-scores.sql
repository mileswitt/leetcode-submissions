# Write your MySQL query statement below

# select all the values from score column
SELECT score, 
    DENSE_RANK() OVER(ORDER BY score DESC) AS 'rank'
FROM Scores




# give rank to each value from top to bottom

# duplicate values get same rank

