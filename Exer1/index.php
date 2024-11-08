<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <form action="post">
    </form>
    <style>

body {
  padding: 25px;
}

* {
  font-family: "Varela Round", serif;
  font-weight: 400;
  font-style: normal;
  padding: 5px;
}

.title {
  color: #5C6AC4;
}

    </style>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Varela+Round&display=swap" rel="stylesheet">
  </head>
  <body>
      <!--  these do not follow the correct field names, add form tag  -->
      <label for="name">Name: </label>
      <input type="text" name="customerName" id="name" placeholder="[Lastname, Firstname M.I.]" />
      <br />
      <label for="email">Email: </label>
      <input type="text" name="customerEmail" id="email" placeholder="[username@example.com]" />
      <br />
      <label for="password">Password: </label>
      <input type="password" name="customerPassword" id="password" placeholder="[strong password]" />
      <br />
      <input type="submit" name="customer" id="submit" value="Register" onclick="validate()" />
      
      <script>
      
function validateWith(requirements) {
  let err = '';
  for (const [field, sub_requirements] of Object.entries(requirements)) {
    let sub_err = ''
  	const value = document.getElementById(field).value;
    for (const { regex, error } of sub_requirements) {
      const isValid = regex.test(value);
      if (!isValid) {
        sub_err += `- ${error}\n`;
      }
    }
    if (sub_err !== '') {
      err += `Invalid ${field}:\n${sub_err}\n`;
    }
  }
  return err;
}

function validate() {
  const err = validateWith({
    name: [{
      regex: /[A-Z][a-z]*, ([A-Z][a-z]* )+[A-Z]\./,
      error: "Must follow the format Lastname, Firstname M.",
    }],
    email: [{
      regex: /[\w\.]+@\w+(?:\.\w+)+/,
      error: "Must be a valid email like name@example.com",
    }],
    password: [
      {
      	regex: /\W/,
        error: "Must contain at least one special character",
      }, {
        regex: /\d/,
        error: "Must contain at least one digit",
      }, {
        regex: /[a-z]/,
        error: "Must contain at least one lowercase letter",
      }, {
        regex: /[A-Z]/,
        error: "Must contain at least one CAPITAL LETTER",
      }, {
      	regex: /.{8,}/,
        error: "Must be at least 8 characters",
      }
    ],
  });
  if (err === '') {
    alert('Registered.');
  } else {
    alert('Failed to register:\n\n' + err);
  }
}
      
      </script>
  </body>
</html>
