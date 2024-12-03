# GPS
Given a list of several towns, the distances between them, a departure town P and possibly an arrival town S, this C++ application determines the shortest possible route (in terms of kilometers traveled) that a means of transport can take proceed in such a way as to comply with the following conditions:
1) to leave P;
2) to go through all the localities in the list once;
3) possibly to arrive in S after passing through all the intermediate towns in the list (if an arrival town has been specified).
## Compile and run
The application can be found in the file 'code 220e.cpp' and is written in the C++ language. Consequently, an IDE that supports applications written in C++ (for example Codeblocks) will be used for compilation and running.
## Explanation of the terminology used
1) The 3 requirements: they are the requirements described previously, i.e. the road:
a) to leave P;
b) to go through all the localities in the list only once;
c) possibly arrive in S after passing through all the intermediate localities in the list (in case an arrival locality was specified);
2) Complete road: it is a road that respects the 3 requirements;
3) Intermediate road (intermediate distance): it is a road that connects 2 localities from those in the list.
4) Minimum road: it is the shortest possible road (in terms of number of kilometers traveled) among all the complete roads.
## Input data
Enter the following from the keyboard:
1) the number of localities N > 1;
2) the names of the N localities;
3) the number of departure town P (0 < P < N+1);
4) the number of the town of arrival S (0 < S < N+1; if you do not want to specify it, enter the number 0);
5) the distances between localities, in kilometers, taking into account the following conditions:
a) if you do not want to specify the distance between 2 localities, enter the number 0;
b) it is necessary to enter these distances so that there is at least one complete road.
## Output data 
This application will determine and display the minimum route and its length.
## Utility 
This application is useful for determining the optimal routes (in terms of the number of kilometers traveled and implicitly the time, consumption and costs) by:
1) companies whose object of activity is the transport of people and goods, which have the following types of vehicles: trains, buses, coaches, subways, trams, trolleybuses, etc.;
2) courier companies;
3) tourists who are staying in a locality and want to visit certain objectives in that locality and/or in other localities.
## Examples of the usefulness of this application
### 1) The example of the railway company 
Let's suppose that the workers of a railway company have to determine the optimal route on which a train must travel, so that it passes through certain localities in an area. In order to minimize the costs and duration of the trip, it is imperative that the chosen route be the road of minimum length that passes through all the respective localities. For this purpose, the respective workers could use this application, which will calculate the minimum distance.
### 2) The example of the courier 
Let's assume that a person wants to leave Bucharest, go through the cities of Craiova and Alexandria, and the chosen route should be the shortest. This person could be a courier or a tourist. In our example we will consider that it is a courier.
#### A) The train journey through 3 localities 
Let's assume that the respective courier will use public transport to travel this way.
If he uses the application frequently used by most people, he will only be able to enter the town of departure and the town of arrival (so he won't be able to enter more than 2 towns to pass through). Consequently, in order to determine the shortest path he will travel, he could choose one of the following options:
I) In the case of using the application frequently used by most people, the courier should generate all possible routes by himself (since, in the case of the train route, the respective application does not allow entering more than 2 localities). In the present case, there would be 2 possible paths:
Bucharest - Alexandria - Craiova and Bucharest - Craiova - Alexandria.
To find out the total lengths of the 2 roads above, he would have to determine the intermediate distances between all possible pairs of localities, that is, he would have to find out the lengths of 3 intermediate roads: Bucharest - Alexandria, Alexandria - Craiova and Bucharest - Craiova; he could find out the lengths of these 3 intermediate roads with the help of the application frequently used by most people, but then he should calculate the lengths of the 2 complete roads by himself, based on the lengths of the 3 intermediate roads; finally he should compare the lengths of the 2 complete roads and choose the shortest one;
II) To use my application. This application will relieve the courier of a large part of the work he should do to determine the minimum route. He will only have to enter the intermediate distances in the application, and the application will then determine the minimum route.
#### B) Traveling by train through at least 10 localities 
Imagine the case where the courier's route, instead of 3 towns, should pass through 10 towns or more. In this case, the number of complete roads would increase a lot. Moreover, determining the length of all complete roads and the minimum road would be extremely difficult to achieve without the help of an application.
In this case, the courier could choose one of the following options:
I) To find out all intermediate distances with the help of the application frequently used by most people. Afterwards, the courier should determine the length of all the complete routes and the minimum route by himself (because, as I stated before, the application frequently used by most people would not be useful, because, in the case of the train journey, the respective application does not allow the introduction of more than 2 localities). All these calculations would require an extremely arduous and very difficult work to be done by the courier without the help of an application such as my application.
II) To use my application. In this case, after entering the intermediate distances in the application, the courier should not do anything. In addition, to save time and effort, the courier would have the possibility to enter in the application only the relevant intermediate distances (for all other intermediate distances he can enter the number 0, and the application will ignore all road segments of length 0).
#### C) The road by car 
Let's further assume that he will use a car to travel this road.
To find out the route that the courier must take, he could enter the names of the localities in an application frequently used by most people, in the following order: 1) Bucharest; 2) Craiova; 3) Alexandria. The consequence will be that the application will show him the following route: Bucharest - Pitesti - Craiova - Alexandria (total distance traveled 379 km; total journey time 5hr8min).
But if the names of these localities are entered in my application (in the same order or in any other order), as well as the distances between them (Bucharest - Craiova 231 km, Bucharest - Alexandria 88 km, Craiova - Alexandria 144 km), then my application will display the following:
The shortest possible route (in terms of kilometers traveled) is: Bucharest Alexandria Craiova.
The total length of this road is 232 km.'
If we enter the route displayed by my application (Bucharest - Alexandria - Craiova) in the application frequently used by most people, we will be told that the total duration of this trip is 3hr42min.
From the data above, it appears that if that courier uses my application, the journey is shortened (as also results from the table below):
I) from the point of view of the distance covered with 147 km;
II) from the point of view of the journey duration by 1hr26min.
### 3) The example of the road on which repair works are carried out
Let's assume that:
A) a person has to drive a road that passes through the localities A, B, C and D;
B) the person in question found out that repair work is being done on the road between towns A and B and therefore wants to avoid traveling the road directly between A and B.
If he uses my application, the respective person has the possibility to enter the distance between A and B as 0. In this case, the application will determine the minimum route, but will also take into account the imposed restriction, so the route determined by the application will not include the direct route between A and B. For example, the road could look like this: A - C - B - D.
