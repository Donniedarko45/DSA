import { Router } from "express";
import { query, validationResult } from "express-validator";


const router = Router();

router.get(
  "/api/users",
  [
    query("filter")
      .isString()
      .notEmpty()
      .withMessage("Must be not empty")
      .isLength({ min: 3, max: 8 })
      .withMessage("Must be at least 3 to 8 character"),
  ],
  (request, response) => {
    const result = validationResult(request);
    console.log(result);
    const {
      query: { filter, value },
    } = request;
    // when filter and value are undefined
    console.log(request["express-validator#contexts"]);
    if (!filter && !value) return response.send(mockUsers);
    if (filter && value)
      return response.send(
        mockUsers.filter((user) => user[filter].includes(value))
      ); //http://localhost:3000/api/users?filter=username&value=kar

    return response.send(mockUsers); // if no value is given  http://localhost:3000/api/users?filter=username
  }
);

export default router;
