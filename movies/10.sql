 SELECT DISTINCT(name) FROM people,movies,directors,ratings WHERE people.id= directors.person_id AND directors.movie_id = movies.id AND ratings.movie_id = movies.id AND rating >=9.0;
