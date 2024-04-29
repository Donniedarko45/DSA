# middleware works on every req,res..

# next()=> method is a function that is used to pass control to the next middleware function in the stack. when a middleware function is called,it recieves three parameters:=>req,res,next{a callback function to pass control to the next middleware function...}


$ Route paths==> {/ se leke jo aayega wo route path hai}
for example:-  app.get(/a/,(req,res)=>{
      res.send('/a/')
})


# Route parameters:-  Route parameters are named URL segments that are used to capture the values specified at their position in the URL. The captured values are populated in the req.params object, with the name of the route parameter specified in the path as their respective keys.




