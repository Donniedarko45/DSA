const http=require("http");
const fs=require("fs");

const myServer=http.createServer((req,res)=>{
    const log=`${Date.now()}: ${req.url} New Request Received\n`
    fs.appendFile('log.txt',log,(err,data)=>{
        switch (req.url) {
            case "/":
                res.end("yahan aa gye toh thoda contact page pe bhi jao na"); // '/'--> homepage ke liye use hota hai...
                break;
    
            case "/about":
                res.end("zindagi mai kch nai ukhada abhi tak");
                break;
    
            case "/sex":
                res.end("virgin mar jaunga 😞");
                break;
    
            case "/gf":
                res.end("error not found");
                break;
    
            default:
                res.statusCode = 404;
                res.end("404 the golden error number");
        }
    });
});

myServer.listen(8000,()=>
                 console.log("server started!"));
