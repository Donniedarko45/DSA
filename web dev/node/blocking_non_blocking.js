/*const fs=require("fs");

// blocking...

const result=fs.readFileSync("contacts.txt","utf-8");
console.log(result);*/
// in blocking code default thread pool size=4
//max?-8core cpu hai toh utta hi thread pool size hoga

// non-blocking

/*const fs=require("fs");

console.log("1")
fs.readFile("contacts.txt","utf-8",(err,result)=>{
    console.log(result);
});

console.log("2");
console.log("3");*/

const fs=require("fs");
const os=require("os");

console.log(os.cpus().length);// ye btayega max kitta thread pool size hoga