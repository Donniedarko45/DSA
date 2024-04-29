const http=require("http");
const fs=require("fs");

const myServer=http.createServer((req,res)=>{
    const log=`${Date.now()}: New Request Received`
    fs.appendFile('log.txt',log,(err,data)=>{ res.end("hello, i am again in underwater and u?")
    })
});

myServer.listen(8000,()=>
                 console.log("server started!"));
