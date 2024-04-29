import express, { request, response } from "express";

const app = express();

//for parsing using middleware
app.use(express.json());
const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
  console.log(`Running on Port ${PORT}`);
});

const loggingMiddleware = (request, response, next) => {
  console.log(`Finished logging`);
  next();
};

const resolveIndexByUserId = (request, response, next) => {
  const {
    params: { id },
  } = request;

  const parsedId = parseInt(id);
  if (isNaN(parsedId)) return response.sendStatus(400);
  const findUserIndex = mockUsers.findIndex((user) => user.id === parsedId);
  if (findUserIndex === -1) return response.sendStatus(404);
  request.findUserIndex = findUserIndex;
  next();
};

app.use(loggingMiddleware);

const mockUsers = [
  { id: 1, username: "kartikey", displayName: "kart" },
  { id: 2, username: "Sam", displayName: "Sam" },
  { id: 3, username: "Mohit", displayName: "Moh" },
];

app.get(
  "/",
  (request, response, next) => {
    console.log("1st middleware");
    next();
  },
  (request, response, next) => {
    console.log("2nd middleware");
    next();
  },
  (request, response, next) => {
    console.log("3rd middleware");
    next();
  },
  (request, response) => {
    response.status(201).send({ msg: "Hello from future" });
  }
);

app.get("/api/users", (request, response) => {
  console.log(request.query);
  const {
    query: { filter, value },
  } = request;
  // when filter and value are undefined

  if (!filter && !value) return response.send(mockUsers);
  if (filter && value)
    return response.send(
      mockUsers.filter((user) => user[filter].includes(value))
    ); //http://localhost:3000/api/users?filter=username&value=kar

  return response.send(mockUsers); // if no value is given  http://localhost:3000/api/users?filter=username
});

// post request..

app.post("/api/users", (request, response) => {
  console.log(request.body);
  const { body } = request;
  const newUser = { id: mockUsers[mockUsers.length - 1].id + 1, ...body };
  mockUsers.push(newUser);
  return response.status(201).send(newUser);
}); // here we get undefined when we post data so for that we have to parse json bodies....=> for parsing  app.use(express.json());

app.get("/api/product", (request, response) => {
  response.send([
    { id: 123, name: "cabbage", price: 547 },
    { id: 124, name: "potato", price: 103 },
    { id: 123, name: "onion", price: 84 },
  ]);
});

// route params

app.get("/api/users/:id", (request, response) => {
  console.log(request.params);
  const parsedId = parseInt(request.params.id);
  console.log(parsedId);
  if (isNaN(parsedId))
    return response.status(400).send({ msg: "Bad request or Invalid Id" });

  const findUser = mockUsers.find((user) => user.id === parsedId);
  if (!findUser) return response.sendStatus(404);
  return response.send(findUser);
});

app.put("/api/users/:id", resolveIndexByUserId,(request, response) => {
  const {
    body,
    params: { id },
  } = request;
  const parsedId = parseInt(id);
  if (isNaN(parsedId)) return response.sendStatus(400);

  const findUserIndex = mockUsers.findIndex((user) => user.id === parsedId);

  if (findUserIndex === -1) return response.sendStatus(404);

  mockUsers[findUserIndex] = { id: parsedId, ...body };
  return response.sendStatus(200);
});

// patch method-->partial update

app.patch("/api/users/:id", (request, response) => {
  const {
    body,
    params: { id },
  } = request;
  const parsedId = parseInt(id);
  if (isNaN(parsedId)) return response.sendStatus(400);

  const findUserIndex = mockUsers.findIndex((user) => user.id === parsedId); // if find index fxn gives -1 then it means that it didnt find

  if (findUserIndex === -1) return response.sendStatus(404);

  mockUsers[findUserIndex] = { ...mockUsers[findUserIndex], ...body };
  return response.sendStatus(200);
});

// delete request...

app.delete("/api/users/:id", (request, response) => {
  const {
    params: { id },
  } = request;

  const parsedId = parseInt(id);
  if (isNaN(parsedId)) return response.sendStatus(400); //bad request...

  const findUserIndex = mockUsers.findIndex((user) => user.id === parsedId);
  if (findUserIndex === -1) return response.sendStatus(404);

  mockUsers.splice(findUserIndex, 1);
  return response.sendStatus(200);
});
