# RESTFULL api.....

rules..
1. server client architecture (server and client are independent machines and both should not be dependent on each other).

2. always respect all http methods
HTTP methods:-
-> GET/user - user data read kro and return data
-> POST/user - handle new user creation
-> PATCH/user - update the user

{POST/updateuser --> user ko update kr do
POST/createuser --> user ko create kro}==>not a good way of practicing

3) if client is browser then we render html data (server side rendering)

MERN-->json ke form me data render krenge