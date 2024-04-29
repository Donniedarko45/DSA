/*// in node js for making server there is an built in module named http

const http=require("http");

const myServer=http.createServer((req,res)=>{
    console.log("new request recieved");
    console.log(req.headers)
    res.end("hello from server"); //response ko end kr dega hello from server kahke

   
}); // ye hmare liye ekk web server bna dega


//server ko run krne ke liye humko port number ki jarurat padega
myServer.listen(8000,()=>console.log("server started"));*/



//lets do console.log in whole request....


const http=require("http");

const myServer=http.createServer((req,res)=>{
    console.log(req)  //request ke andar sara information stored hota hai like user kya access krna cah rha h user kon h etc etc
    res.end("hello how are u i am underwater")
});
myServer.listen(6969,()=>console.log("server started"));
