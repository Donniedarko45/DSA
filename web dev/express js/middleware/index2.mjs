import express, { request, response } from "express";
import {
  query,
  validationResult,
  body,
  matchedData,
  checkSchema,
} from "express-validator";
import { createUservalidationSchema } from "../utiils/validationSchemas.mjs";
import userRouter from "../src/Routes/user.mjs"

import { Router } from "express";

import {mockUsers} from "../utils/mock.mjs"

const app = express();

//for parsing using middleware
app.use(express.json());

app.use(userRouter);

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

// post request..

app.post(
  "/api/users",
  checkSchema(createUservalidationSchema),
  (request, response) => {
    const result = validationResult(request);
    console.log(result);
    if (!result.isEmpty())
      return response.status(400).send({ errors: result.array() });
    const data = matchedData(request);
    console.log(data);

    const { body } = request;
    const newUser = { id: mockUsers[mockUsers.length - 1].id + 1, ...body };
    mockUsers.push(newUser);
    return response.status(201).send(newUser);
  }
); // here we get undefined when we post data so for that we have to parse json bodies....=> for parsing  app.use(express.json());

app.get("/api/product", (request, response) => {
  response.send([
    { id: 123, name: "cabbage", price: 547 },
    { id: 124, name: "potato", price: 103 },
    { id: 123, name: "onion", price: 84 },
  ]);
});

// route params...

app.get("/api/users/:id", resolveIndexByUserId, (request, response) => {
  const { findUserIndex } = request;
  const findUser = mockUsers[findUserIndex];
  if (!findUser) return response.sendStatus(404);
  return response.send(findUser);
});

app.put("/api/users/:id", resolveIndexByUserId, (request, response) => {
  const { body, findUserIndex } = request;
  mockUsers[findUserIndex] = { id: mockUsers[findUserIndex].id, ...body };
  return response.sendStatus(200);
});

// patch method-->partial update

app.patch("/api/users/:id", resolveIndexByUserId, (request, response) => {
  const { body, findUserIndex } = request;

  mockUsers[findUserIndex] = { ...mockUsers[findUserIndex], ...body };
  return response.sendStatus(200);
});

// delete request...

app.delete("/api/users/:id", (request, response) => {
  const { findUserIndex } = request;

  mockUsers.splice(findUserIndex, 1);
  return response.sendStatus(200);
});
