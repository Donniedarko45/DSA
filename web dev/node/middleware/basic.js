const express =require('express')
const app=express();
const PORT=8000
app.get('/',(req,res)=>
{
    return res.send("hello i am kartikey")
})

app.post('/',(req,res)=>{
    res.send('update the name : ')
})


// route methods..
