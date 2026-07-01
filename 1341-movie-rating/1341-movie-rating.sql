# Write your MySQL query statement below

# first , do for the user

(Select U1.name as results  
from Users U1 inner join 
(Select user_id , count(movie_id) as noofmovies 
from MovieRating
group by user_id
)
T1 
on U1.user_id = T1.user_id
order by T1.noofmovies desc , U1.name
limit 1
)

UNION ALL



# now , for the movies
(Select M1.title AS results
from Movies M1 inner join 

(select movie_id , (sum(rating)/count(rating)) as average_rating
from MovieRating 
where created_at >= '2020-02-01' and created_at <= '2020-02-29'
group by movie_id
)
M2
on M1.movie_id = M2.movie_id
order by M2.average_rating desc, M1.title
limit 1 
)