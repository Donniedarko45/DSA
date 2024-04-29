//designing a rest api.....

const express = require('express');
const users = require("./MOCK_DATA.json");
const app=express();
const PORT=8000;

const fs=require("fs")

//Middleware--plugin(jab bhi form data aayega ye body me dalne ka kam krega)
app.use(express.urlencoded({extended:false}));
//next is calling function so after that routes will call and processed
app.use((req,res,next)=>{
    fs.appendFile("log.txt",`${Date.now()}: ${req.path}`,
    (err,data)=>{
        next();
    }
    );
});//this will write in fs module once done it will call next middleware

//routes
app.get("/users",(req,res)=>{
    const user=users
    return res.json(user)
});



//REST api..

app
    .route("/users/:id")
    .get((req,res)=>{
        const id=Number(req.params.id);
        const user=users.find((user)=>user.id==id);
        return res.json(user);
        })
    .put((req,res)=>{
        //put (insert or update user with specific id..)
        return res.json({status:"pending"})
    })
    .delete((req,res)=>{
        // delete user with id..
        return res.json({status:"pending"})
    });

//create new user

app.post("/api/users",(req,res)=>{
    const body=req.body;
    users.push({...body,id:users.length+1});
    fs.writeFile("./MOCK_DATA.json",JSON.stringify(users),(err,data)=>{
        return res.json({status: "success",id:users.length});
    })
});

app.listen(PORT,()=>console.log(`Server started at PORT: ${PORT}`))






