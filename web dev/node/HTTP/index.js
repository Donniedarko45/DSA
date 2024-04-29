const http=require("http");
const fs=require("fs");
const url = require("url");

const myServer=http.createServer((req,res)=>{
    if(req.url==='/favicon.ico') return res.end();
    const log=`${Date.now()}: ${req.method} ${req.url} New Request Received\n`;
    const myUrl=url.parse(req.url,true);
    fs.appendFile('log.txt',log,(err,data)=>{
        switch (myUrl.pathname) {
            case "/":
               if(req.method==="GET") res.end("homepage"); 
                break;
    
            case "/about":
                const username=myUrl.query.myname
                res.end(`hi,${username}`);
                break;
            case "/signup":
                if(req.method==="GET") res.end("This is a signup form");

                else if(req.method==="POST")
                 {
                    //DB query
                    res.end("success");
                 }  
    
            default:
                res.end("404 the golden error number");
        }
    });
});

myServer.listen(8000,()=>
                 console.log("server started!"));


                 // we can do this easily with express js framework..........