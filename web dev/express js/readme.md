# use of route params is when we have to access a specific id suppose there is an thousand of persons list in which the details information of every information is stored so by route params we can access those specific members by there ids and thus we can get all the details of specific user

@example:-
 app.get('/users/:userId/books/:bookId', (req, res) => {
  res.send(req.params)
})