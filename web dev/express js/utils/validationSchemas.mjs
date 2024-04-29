export const createUservalidationSchema={
    username: {
        isLength:{
            options:{
                min:5,
                max:13,
            },
            errorMessage:"username must be in between 8 to 13 characters..",
        },
        notEmpty:{
            errorMessage:"username cant be empty"
        }, //because it is not taking option so giving it true
        isString:{
            errorMessage:"username must be string!",
        }
    },
    displayName:{
        notempty:true,
    }
};


