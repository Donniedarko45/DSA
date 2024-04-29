const fs = require("fs");
const url = require("url");
const express = require("express");

const app = express();
app.get("/", (req, res) => {
  return res.send("hello from homepage");
});

app.get("/about",(req,res)=>
{
    return res.send("hello from about page");
})

app.listen(8000,()=>console.log("server started!"));
