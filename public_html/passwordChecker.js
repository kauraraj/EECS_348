document.getElementById("submitButton").addEventListener("click", function() {

    var pass1 = document.getElementById("pass1").value;
    var pass2 = document.getElementById("pass2").value;

    var result = password_checker(pass1, pass2);

    alert(result);

});

function password_checker(password1, password2) {
    if(password1.length < 8) {
        return "Password 1 Length isn't 8 or more characters";
    }
    if(password2.length < 8) {
        return "Password 2 Length isn't 8 or more characters";
    }

    if (password1 == password2) {
        return "The passwords matched";
    } else {
        return "The passwords don't match";
    }

}