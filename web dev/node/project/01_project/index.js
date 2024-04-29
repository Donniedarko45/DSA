//designing a rest api.....

const express = require('express');
const users = require("./MOCK_DATA.json");
const app=express();
const PORT=8000;

const fs=require("fs")

//Middleware--plugin(jab bhi form data aayega ye body me dalne ka kam krega)
app.use(express.urlencoded({extended:false}));

//routes
app.get("/users",(req,res)=>{
    const html=`
    <ul>
      ${users.map((user)=>`<li>${user.first_name}</li>`).join("")}
    </ul>
    `;
    res.send(html)
});



//REST api..

app
    .route("/api/users/:id")
    .get((req,res)=>{
        const id=Number(req.params.id);
        const user=users.find((user)=>user.id==id);
        return res.json(users);
        })
        //put method is for updating the data...........

    .put((req,res)=>{
        const {id}=req.params
        const {first_name}= req.body
        console.log(id,first_name)
        res.send("hello world")
    })
    .delete((req,res)=>{
        const id=Number(req.params.id);
        delete(id);
        return res.json(delete(users.id))
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






