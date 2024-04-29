const fs = require("fs");
/*
//synchronous..

fs.writeFileSync("./test.txt",'hey there');

//asynchronous...

fs.writeFile("./test.txt","hello world async",(err)=>{})*/

//result=fs.readFileSync("./contacts.txt","UTF-8")
//console.log(result)

/*fs.readFile("./contacs.txt","utf-8",(err,data)=>{
    if(err){
        console.log("error!",err);
    }
    else{
        console.log(data);
    }
});*/

fs.appendFileSync("./test.txt",`\n${Date.now()} \t hey there`);
/*fs.cpSync("./test.txt","./copy.txt");
fs.unlinkSync("./copy.txt") // delete a file*/

console.log(fs.statSync("./test.txt"));
